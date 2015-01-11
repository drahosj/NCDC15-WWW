#include <stdio.h>
#include "utils.h"

void main()
{
    char buffer[1024];
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
        printf("<table><tr><th>Transaction</th><th>Debit</th><th>Credit</th><th>Balance</th></tr>\n");
        fflush(stdout);
        sprintf(buffer, "cat ../../db/user_%s | sed -e 's/from: \\(.*\\) \\(.*\\) \\(.*\\)/<tr><td>\\1<\\/td><td>---<\\/td><td>\\2<\\/td><td>\\3<\\/td><\\/tr>/' -e 's/to: \\(.*\\) \\(.*\\) \\(.*\\)/<tr><td>\\1<\\/td><td>\\2<\\/td><td>---<\\/td><td>\\3<\\/td><\\/tr>/'", query_value("user_name"));
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
