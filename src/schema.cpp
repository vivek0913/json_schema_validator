#include "schema.hpp"
#include <stdexcept>

/*
 * Converts a JSON schema type string into SchemaType enum.
 * Throws if an unsupported type is encountered.
 */
SchemaType schema_type_from_string(const std::string& s) {
    if (s == "null")    return SchemaType::Null;
    if (s == "boolean") return SchemaType::Boolean;
    if (s == "integer") return SchemaType::Integer;
    if (s == "number")  return SchemaType::Number;
    if (s == "string")  return SchemaType::String;
    if (s == "array")   return SchemaType::Array;
    if (s == "object")  return SchemaType::Object;

    throw std::runtime_error("Unknown schema type: " + s);
}
