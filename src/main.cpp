#include <fstream>
#include <nlohmann/json.hpp>
#include "json_loader.hpp"
#include "print.hpp"
using json = nlohmann::json;

int main() {
    std::ifstream file("/Users/vivek/json_validator/sample_config.json");
    json j;
    file >> j;

    Value root = from_json(j);
    print_value(root);
}
