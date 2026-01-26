#include "json_loader.hpp"

using json = nlohmann::json;

Value from_json(const json& j) {
    if (j.is_null())        return { nullptr };
    if (j.is_boolean())     return { j.get<bool>() };
    if (j.is_number_integer()) return { j.get<int64_t>() };
    if (j.is_number_float())   return { j.get<double>() };
    if (j.is_string())      return { j.get<std::string>() };

    if (j.is_array()) {
        Array arr;
        for (const auto& elem : j) {
            arr.push_back(from_json(elem));
        }
        return { std::move(arr) };
    }

    if (j.is_object()) {
        Object obj;
        for (const auto& [key, val] : j.items()) {
            obj[key] = from_json(val);
        }
        return { std::move(obj) };
    }

    return { nullptr };
}
