#include "print.hpp"
#include <iostream>

void print_value(const Value& v, const std::string& indent) {
    switch (v.type()) {
        case ValueType::Null:
            std::cout << indent << "null\n";
            break;

        case ValueType::Boolean:
            std::cout << indent << (std::get<bool>(v.data) ? "true" : "false") << "\n";
            break;

        case ValueType::Integer:
            std::cout << indent << std::get<int64_t>(v.data) << "\n";
            break;

        case ValueType::Float:
            std::cout << indent << std::get<double>(v.data) << "\n";
            break;

        case ValueType::String:
            std::cout << indent << "\"" << std::get<std::string>(v.data) << "\"\n";
            break;

        case ValueType::Array: {
            std::cout << indent << "[\n";
            for (const auto& elem : std::get<Array>(v.data)) {
                print_value(elem, indent + "  ");
            }
            std::cout << indent << "]\n";
            break;
        }

        case ValueType::Object: {
            std::cout << indent << "{\n";
            for (const auto& [key, val] : std::get<Object>(v.data)) {
                std::cout << indent << "  " << key << ": ";
                print_value(val, indent + "  ");
            }
            std::cout << indent << "}\n";
            break;
        }
    }
}
