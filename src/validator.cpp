#include "validator.hpp"
#include <iostream>
#include <variant>

/*
 * Check if a ValueType matches a SchemaType.
 */
static bool type_matches(ValueType valueType, SchemaType schemaType) {
    switch (schemaType) {
        case SchemaType::Null:
            return valueType == ValueType::Null;

        case SchemaType::Boolean:
            return valueType == ValueType::Boolean;

        case SchemaType::Integer:
            return valueType == ValueType::Integer;

        case SchemaType::Number:
            return valueType == ValueType::Integer ||
                   valueType == ValueType::Float;

        case SchemaType::String:
            return valueType == ValueType::String;

        case SchemaType::Array:
            return valueType == ValueType::Array;

        case SchemaType::Object:
            return valueType == ValueType::Object;
    }
    return false;
}

bool validate(const Value& value, const Schema& schema, const std::string& path) {
    // Type check
    if (!type_matches(value.type(), schema.type)) {
        std::cerr << "Type mismatch at " << path << "\n";
        return false;
    }

    // Object validation
    if (schema.type == SchemaType::Object) {
        const auto& obj = std::get<Object>(value.data);

        // Required fields
        for (const auto& name : schema.required) {
            if (obj.find(name) == obj.end()) {
                std::cerr << "Missing required field "
                          << path << "." << name << "\n";
                return false;
            }
        }

        // Properties
        for (const auto& [key, propSchema] : schema.properties) {
            auto it = obj.find(key);
            if (it != obj.end()) {
                if (!validate(it->second, *propSchema, path + "." + key)) {
                    return false;
                }
            }
        }
    }

    // Array validation
    if (schema.type == SchemaType::Array) {
        const auto& arr = std::get<Array>(value.data);

        for (size_t i = 0; i < arr.size(); ++i) {
            if (!validate(arr[i], *schema.items, path + "[" + std::to_string(i) + "]")) {
                return false;
            }
        }
    }

    return true;
}
