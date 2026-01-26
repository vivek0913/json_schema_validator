#pragma once
#include <nlohmann/json.hpp>
#include "value.hpp"

Value from_json(const nlohmann::json& j);
