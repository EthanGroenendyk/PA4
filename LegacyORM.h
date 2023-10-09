#ifndef ADAPTER_H
#define ADAPTER_H

#include <string>
#include <regex>
#include <iostream>

class LegacyORM {
public:
    bool executeQuery(std::string query);    
};

#endif