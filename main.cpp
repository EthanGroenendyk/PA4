#include "adapter.h"
#include "legacyORM.h"

#include <iostream>
#include <sstream>

void TestAdapterValidQueryWithFromAndJoin() {
    adapter a;
    string query = "FROM table1 JOIN table2 ON table1.id = table2.id SELECT * WHERE table1.name = 'John'";

    bool result = a.Query(query);

    if (!result) {
        std::cerr << "TestAdapterValidQueryWithFromAndJoin failed" << std::endl;
    }
}

void TestAdapterValidQueryWithOnlyFrom() {
    adapter a;
    string query = "FROM table1 SELECT * WHERE name = 'John'";

    bool result = a.Query(query);

    if (!result) {
        std::cerr << "TestAdapterValidQueryWithOnlyFrom failed" << std::endl;
    }
}

void TestAdapterValidQueryWithNeitherFromNorJoin() {
    adapter a;
    string query = "SELECT * WHERE name = 'John'";

    bool result = a.Query(query);

    if (!result) {
        std::cerr << "TestAdapterValidQueryWithNeitherFromNorJoin failed" << std::endl;
    }
}

void TestAdapterInvalidQuery() {

    adapter a;
    string query = "SELECT * FROM table1 WHERE name = 'John' JOIN table2 ON table1.id = table2.id";

    bool result = a.Query(query);

    if (!result) {
        std::cerr << "TestAdapterInvalidQuery failed" << std::endl;
    }
}

void TestLegacyORMExecuteQuery() {
    LegacyORM* orm = new LegacyORM();
    string query = "SELECT * FROM table1 WHERE name = 'John'";

    bool result = orm->executeQuery(query);
    if (!result) {
        std::cerr << "TestLegacyORMExecuteQuery failed" << std::endl;
    }

    
}

int main() {
    cout << "first test: " << endl;
    TestAdapterValidQueryWithFromAndJoin();
    cout << "second test: " << endl;
    TestAdapterValidQueryWithOnlyFrom();
    cout << "third test: " << endl;
    TestAdapterValidQueryWithNeitherFromNorJoin();
    cout << "forth test: " << endl;
    TestAdapterInvalidQuery();
    cout << "fifth test: " << endl;
    TestLegacyORMExecuteQuery();

    return 0;
}