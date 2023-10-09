#include "adapter.h"
#include "legacyORM.h"

bool adapter::Query(string query){

    // Find the positions of FROM and JOIN clauses
    int fromPos = query.find("FROM");
    int joinPos = query.find("JOIN");
    int restPos = query.find("WHERE");

    bool found = false;
    while()
    if(restPos == string::npos){
        restPos = query.find("HAVING");
    }

    if (fromPos != string::npos && joinPos != string::npos && restPos != string::npos) {
        // Extract the SELECT clause and the rest of the query
        string selectClause = query.substr(0, fromPos);
        string joinQuery = query.substr(fromPos, restPos-fromPos);
        string rest = query.substr(restPos);

        cout << selectClause << "\n" << joinQuery << "\n" << rest << "\n" << query[joinPos] << "\n";

        // Rearrange the query
        string rearrangedQuery = joinQuery + selectClause + rest;

        cout << "Original SQL query: " << query << endl;
        cout << "Rearranged SQL query: " << rearrangedQuery << endl;
    } else {
        cout << "The SQL query does not contain both FROM and JOIN clauses." << endl;
    }
}