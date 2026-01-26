#include "value.hpp"

ValueType Value::type() const {
    return std::visit([](const auto& v) -> ValueType {
        using T = std::decay_t<decltype(v)>;

        if constexpr (std::is_same_v<T, std::nullptr_t>) return ValueType::Null;
        if constexpr (std::is_same_v<T, bool>)           return ValueType::Boolean;
        if constexpr (std::is_same_v<T, int64_t>)        return ValueType::Integer;
        if constexpr (std::is_same_v<T, double>)         return ValueType::Float;
        if constexpr (std::is_same_v<T, std::string>)    return ValueType::String;
        if constexpr (std::is_same_v<T, Array>)          return ValueType::Array;
        if constexpr (std::is_same_v<T, Object>)         return ValueType::Object;

        return ValueType::Null;
    }, data);
}
