#include "LegacyORM.h"
#include <regex>

bool LegacyORM::executeQuery(std::string query) {
    bool result = false;
    std::regex pattern("^(SELECT|INSERT|UPDATE|DELETE|CREATE|DROP|ALTER|TRUNCATE|GRANT|REVOKE|USE|BEGIN|COMMIT|ROLLBACK|SET|SHOW|DESCRIBE|EXPLAIN|CALL|LOAD|LOCK|UNLOCK|RENAME|START|STOP|ANALYZE|CHECK|OPTIMIZE|REPAIR|BACKUP|RESTORE|CHANGE|FLUSH|KILL|PURGE|RESET|SHUTDOWN|STATUS|BINLOG|CACHE|CHECKSUM|DELAYED|FOR|FORCE|HIGH_PRIORITY|IGNORE|LOW_PRIORITY|QUICK|SQL_BIG_RESULT|SQL_CALC_FOUND_ROWS|SQL_SMALL_RESULT|STRAIGHT_JOIN|TABLES|SQL_NO_CACHE|SQL_CACHE|DISTINCT|ALL|AS|ASC|DESC|FROM|WHERE|GROUP BY|HAVING|ORDER BY|LIMIT|OFFSET|INNER JOIN|LEFT JOIN|RIGHT JOIN|FULL OUTER JOIN|ON|USING|CASE|WHEN|THEN|ELSE|END|LIKE|IN|BETWEEN|IS|NULL|NOT|AND|OR|XOR|&|\\||\\^|\\+|\\-|\\*|\\/|\\%|\\=|\\>|\\<|\\!|\\~|\\(|\\)|\\,|\\;|\\:|\\@|\\#|\\$|\\&|\\_|\\{|\\}|\\[|\\]|\\`|\\?|\\||\\^|\\@|\\%|\\&|\\*|\\-|\\+|\\=|\\~|\\!|\\/|\\;|\\:|\\<|\\>|\\,|\\?|\\#|\\$|\\^|\\&|\\_|\\||\\`|\\{|\\}|\\[|\\]|\\(|\\))+$");
    if (std::regex_match(query, pattern)) {
        std::cout << "Executing valid query: " << query << std::endl;
        result = true;
    }
    return result;
}