#include "LegacyORM.h"
#include <regex>

bool LegacyORM::executeQuery(std::string query) {
    bool result = false;
    std::regex pattern(R"(\bSELECT\b.*\bFROM\b.*(?:\bJOIN\b.*\bON\b.*|WHERE|ORDER\s+BY|LIMIT|OFFSET|COUNT|SUM|AVG|MIN|MAX|CASE|IN|BETWEEN|LIKE).*|/\*.*?\*/)", std::regex::icase);
    if (std::regex_match(query, pattern)) {
        std::cout << "Executing valid query: " << query << std::endl;
        result = true;
    }
    return result;
}