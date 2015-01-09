#include <stdio.h>
#include "utils.h"

void main()
{
    char buffer[200];
    sprintf(buffer, "../../db/user_%s", query_value("user_name"));
    if (file_exists(buffer))
    {
        headers_html();
        printf("<html><style type=\"text/css\">table, td, th { border: 1px solid black;}</style><body><h2>Showing user %s\n</h2>",
            query_value("user_name"));
        printf("<p>Balance: ");
        sprintf(buffer, "cat ../../db/user_%s | tail -n 1 | cut -d ' ' -f 4",
            query_value("user_name"));
        fflush(stdout);
        system(buffer);
        printf("</p>");
        printf("<h3>Transaction History</h3>");
        printf("<table><tr><th>To or From</th><th>Other Party</th><th>Amount</th><th>Balance</th></tr>\n");
        fflush(stdout);
        sprintf(buffer, "cat ../../db/user_%s | sed -e 's/\\(.*\\): \\(.*\\) \\(.*\\) \\(.*\\)/<tr><td>\\1<\\/td><td>\\2<\\/td><td>\\3<\\/td><td>\\4<\\/td><\\/tr>/'", query_value("user_name"));
	system(buffer);
        printf("</table></body></html>");
    }
    else 
    {
        printf("Status: 404\n");
        headers_html();
        printf("<html><body><p>User not found!</p></body></html>\n");
    }
}
