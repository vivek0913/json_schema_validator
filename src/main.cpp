#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "json_loader.hpp"
#include "print.hpp"
#include "schema.hpp"
#include "value.hpp"
#include "validator.hpp"
using json = nlohmann::json;

std::shared_ptr<Schema> load_schema(const json& j);
Value from_json(const nlohmann::json& j);

static json load_json_file(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    json j;
    file >> j;
    return j;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0]
                  << " <schema.json> <data.json>\n";
        return 1;
    }

    try {
        // Load JSON files
        json schemaJson = load_json_file(argv[1]);
        json dataJson   = load_json_file(argv[2]);

        // Convert to internal representations
        std::shared_ptr<Schema> schema = load_schema(schemaJson);
        Value value = from_json(dataJson);

        // Validate
        bool ok = validate(value, *schema);

        if (ok) {
            std::cout << "JSON is valid\n";
            return 0;
        } else {
            std::cout << "JSON is invalid\n";
            return 2;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 3;
    }
}