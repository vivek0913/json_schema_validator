#pragma once

#include "schema.hpp"
#include "value.hpp"
#include <string>

bool validate(
    const Value& value,
    const Schema& schema,
    const std::string& path = "$"
);
