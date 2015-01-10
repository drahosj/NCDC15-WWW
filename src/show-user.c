#include <stdio.h>
#include "utils.h"

void main()
{
    char buffer[200];
    sprintf(buffer, "../../db/user_%s", query_value("user_name"));
    if (file_exists(buffer))
    {
        headers_html();
        printf("<html><body><h2>Showing user %s\n</h2>",
            query_value("user_name"));
        printf("<p>Balance: ");
        sprintf(buffer, "cat ../../db/user_%s | tail -n 1 | cut -d ' ' -f 4",
            query_value("user_name"));
        fflush(stdout);
        system(buffer);
        printf("</p>");
        printf("<h3>Transaction History</h3>");
        fflush(stdout);
        sprintf(buffer, "cat ../../db/user_%s | sed -e 's/\\(.*\\): \\(.*\\) \\(.*\\) \\(.*\\)/<p>Transaction \\1 \\2. Amount: \\3 Total balance: \\4<\\/p>/'", query_value("user_name"));
	system(buffer);
        printf("</body></html>");
    }
    else 
    {
        printf("Status: 404\n");
        headers_html();
        printf("<html><body><p>User not found!</p></body></html>\n");
    }
}
