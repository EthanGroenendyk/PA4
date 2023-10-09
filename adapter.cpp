#include "adapter.h"
#include "legacyORM.h"

bool adapter::Query(string query){

    // Find the positions of FROM and JOIN clauses
    int fromPos = query.find("FROM");
    int selectPos = query.find("SELECT");
    int restPos = query.find("WHERE");

    if(selectPos == 0){return false;} else{};

    LegacyORM ORM;

    int count = 12;
    string words[] = {"HAVING", "ORDER BY", "LIMIT",  "OFFSET", "COUNT", "SUM", "AVG", "MIN", "MAX", "CASE", "IN", "BETWEEN", "LIKE"};

    while(count>=0){
        if(restPos == string::npos){
            restPos = query.find(words[count--]);
        }
        else{
            count = -99;
        }
    }

    if (fromPos != string::npos && restPos != string::npos) {
        // Extract the SELECT clause and the rest of the query
        string fromPart = query.substr(0, selectPos);
        string selectPart = query.substr(selectPos, restPos-selectPos);
        string rest = query.substr(restPos);

        //cout << selectPart << "\n" << fromPart << "\n" << rest << "\n";

        // Rearrange the query
        string rearrangedQuery = selectPart + fromPart + rest;

        // cout << "Original SQL query: " << query << endl;
        // cout << "Rearranged SQL query: " << rearrangedQuery << endl;
        
        return ORM.executeQuery(rearrangedQuery);
    } else if (fromPos == string::npos && restPos == string::npos) {
        
        // cout << "Original SQL query: " << query << endl;
        // cout << "Rearranged SQL query: " << query << endl;

        return ORM.executeQuery(query);
    } 
    return true;
}