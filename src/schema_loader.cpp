#include "schema.hpp"
#include <nlohmann/json.hpp>
#include <stdexcept>

/*
 * Loads a JSON Schema (as nlohmann::json) into our Schema structure.
 * This function is recursive.
 */
std::shared_ptr<Schema> load_schema(const nlohmann::json& j) {
    auto schema = std::make_shared<Schema>();

    // Every schema must define a "type"
    if (!j.contains("type")) {
        throw std::runtime_error("Schema missing 'type'");
    }

    schema->type = schema_type_from_string(
        j.at("type").get<std::string>()
    );

    // Handle object schemas
    if (schema->type == SchemaType::Object) {

        if (j.contains("required")) {
            for (const auto& name : j.at("required")) {
                schema->required.insert(name.get<std::string>());
            }
        }

        if (j.contains("properties")) {
            for (auto it = j.at("properties").begin(); it != j.at("properties").end(); ++it) {
                // Recursively load schema for each property
                schema->properties[it.key()] =
                    load_schema(it.value());
            }
        }
    }

    // Handle array schemas
    if (schema->type == SchemaType::Array) {
        if (!j.contains("items")) {
            throw std::runtime_error("Array schema missing 'items'");
        }

        // Recursively load item schema
        schema->items = load_schema(j.at("items"));
    }

    return schema;
}
