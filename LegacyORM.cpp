#include "LegacyORM.h"
#include <regex>

bool LegacyORM::executeQuery(std::string query) {
    bool result = false;
    std::regex pattern("^(?=.*SELECT.*FROM)(?!.*(?:CREATE|DROP|UPDATE|INSERT|ALTER|DELETE|ATTACH|DETACH)).*$");
    if (std::regex_match(query, pattern)) {
        std::cout << "Executing valid query: " << query << std::endl;
        result = true;
    }
    return result;
}