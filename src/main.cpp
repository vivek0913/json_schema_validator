#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <ranges>
using namespace std;

using json = nlohmann::json;

void print_json(const json &j) {
    if(j.is_object()) {
        for(auto &[key, value]: j.items()) {
            std::cout<<key<<"(obj): "<<value.type_name()<<"\n";
            print_json(value);
        }
    }
    else if(j.is_array()) {
        for(size_t i=0;i<j.size(); i++) {
            std::cout<<"["<<i<<"](arr) :";
            std::cout<<j[i].type_name()<<"\n";
            print_json(j[i]);

        }
    }
}

int main() {
    std::ifstream file("/Users/vivek/json_validator/sample_config.json");
    if(!file) {
        std::cerr<<"Failed to open sample_config.json";
        return 1;
    }

    json config;
    file >> config;

    print_json(config);

    int port = config["server"]["port"];

    // for(int i: std::iota::views(0, config.size()))
    std::cout<<"Size="<<config.size()<<"\n";
    for(auto it=config.begin(); it!=config.end(); it++) {
        std::cout<<"Key="<<it.key()<<"Type="<<it.value().type_name()<<"\n";
    }

    std::cout<<"Port value = "<<port<<"\n";
        std::cout << "\nType inspection:\n";
    std::cout << "server is object: "
              << config["server"].is_object() << "\n";
    std::cout << "port is number: "
              << config["server"]["port"].is_number() << "\n";
    std::cout<<"name="<<config["server"]["name"]<<"\n";
    std::cout<<"logging-level="<<config["logging"]["level"]<<"\n";

    return 0;

}