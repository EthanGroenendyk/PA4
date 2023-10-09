#include <iostream>
#include <string>
using namespace std;

int main() {
    // Input SQL query
    string sqlQuery = "SELECT * FROM table1 JOIN table2 ON table1.id = table2.id WHERE column1 = 'value'";

    // Find the positions of FROM and JOIN clauses
    size_t fromPos = sqlQuery.find("FROM");
    size_t joinPos = sqlQuery.find("JOIN");
    size_t restPos = sqlQuery.find("WHERE");

    if (fromPos != string::npos && joinPos != string::npos) {
        // Extract the SELECT clause and the rest of the query
        string selectClause = sqlQuery.substr(0, fromPos);
        string joinQuery = sqlQuery.substr(fromPos, restPos-fromPos);
        string rest = sqlQuery.substr(restPos);

        cout << selectClause << "\n" << joinQuery << "\n" << rest << "\n" << sqlQuery[joinPos] << "\n";

        // Rearrange the query
        string rearrangedQuery = joinQuery + selectClause + rest;

        cout << "Original SQL query: " << sqlQuery << endl;
        cout << "Rearranged SQL query: " << rearrangedQuery << endl;
    } else {
        cout << "The SQL query does not contain both FROM and JOIN clauses." << endl;
    }

    return 0;
}
