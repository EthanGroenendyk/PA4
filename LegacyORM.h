#ifndef ADAPTER_H
#define ADAPTER_H

#include <string>

class LegacyORM {
public:
    bool executeQuery(std::string query);    
};

#endif