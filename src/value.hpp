#pragma once

#include <string>
#include <variant>
#include <vector>
#include <map>

enum class ValueType {
    Null,
    Boolean,
    Integer,
    Float,
    String,
    Array,
    Object
};

struct Value;

using Array  = std::vector<Value>;
using Object = std::map<std::string, Value>;

struct Value {
    using Storage = std::variant<
        std::nullptr_t,
        bool,
        int64_t,
        double,
        std::string,
        Array,
        Object
    >;

    Storage data;

    ValueType type() const;
};
