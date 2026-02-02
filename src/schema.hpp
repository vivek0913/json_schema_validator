#pragma once

#include <string>
#include <map>
#include <memory>
#include <set>

enum class SchemaType {
    Null,
    Boolean,
    Integer,
    Number,
    String,
    Array,
    Object
};

struct Schema;

struct Schema {
    // The expected type of the JSON value
    SchemaType type;
    
    std::map<std::string, std::shared_ptr<Schema>> properties;

    // Used when type == Object
    // Set of required property names
    std::set<std::string> required;

    // Used when type == Array
    // Schema for array elements
    std::shared_ptr<Schema> items;
};


SchemaType schema_type_from_string(const std::string& s);
