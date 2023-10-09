#include "adapter.h"

int main() {

    adapter buddy;

    buddy.Query("FROM table1 JOIN table2 ON table1.id = table2.id SELECT * WHERE column1 = 'value'");

    return 0;
}
