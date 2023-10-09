#include "LegacyORM.h"
#include <regex>

bool LegacyORM::executeQuery(std::string query) {
    bool result = false;
    std::regex pattern("^/(\s*([\0\b\'\"\n\r\t\%\_\\]*\s*(((select\s+\S.*\s+from\s+\S+)|(insert\s+into\s+\S+)|(update\s+\S+\s+set\s+\S+)|(delete\s+from\s+\S+)|(((drop)|(create)|(alter)|(backup))\s+((table)|(index)|(function)|(PROCEDURE)|(ROUTINE)|(SCHEMA)|(TRIGGER)|(USER)|(VIEW))\s+\S+)|(truncate\s+table\s+\S+)|(exec\s+)|(\/\*)|(--)))(\s*[\;]\s*)*)+)/i");
    if (std::regex_match(query, pattern)) {
        std::cout << "Executing valid query: " << query << std::endl;
        result = true;
    }
    return result;
}