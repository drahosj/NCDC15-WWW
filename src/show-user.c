#include <stdio.h>
#include "utils.h"

void main()
{
    char buffer[1024];
    sprintf(buffer, "../../db/user_%s", query_value("user_name"));

    if (require_user_token(query_value("user_name")))
            return forbidden();

    if (file_exists(buffer))
    {
        headers_html();
        printf("<html><style type=\"text/css\">table, td, th { border: 1px solid black;}</style><body bgcolor=grey><center><h1>%s's Account\n</h1>",
            query_value("user_name"));
        printf("<h3>Balance: ");
        sprintf(buffer, "cat ../../db/user_%s | tail -n 1 | cut -d ' ' -f 4",
            query_value("user_name"));
        fflush(stdout);
        system(buffer);
        printf("</h3>");
        printf("<h2>Transaction History</h2>");
        printf("<table><tr><th>Transaction</th><th>Debit</th><th>Credit</th><th>Balance</th></tr>\n");
        fflush(stdout);
        sprintf(buffer, "cat ../../db/user_%s | sed -e 's/from: \\(.*\\) \\(.*\\) \\(.*\\)/<tr><td>\\1<\\/td><td>---<\\/td><td bgcolor=limegreen>\\2<\\/td><td bgcolor=lightsteelblue>\\3<\\/td><\\/tr>/' -e 's/to: \\(.*\\) \\(.*\\) \\(.*\\)/<tr><td>\\1<\\/td><td bgcolor=salmon>\\2<\\/td><td>---<\\/td><td bgcolor=lightsteelblue>\\3<\\/td><\\/tr>/'", query_value("user_name"));
	system(buffer);
        printf("</table>");
        printf("<a href=\"/cgi-bin/show/landing\">Back</a>");
        printf("</center><hr/>");
        printf("<iframe src=\"/bottom2.html\" scrolling=no frameborder=none width=100%%></body></html>");
    }
    else 
    {
        printf("Status: 404\n");
        headers_html();
        printf("<html><body><p>User not found!</p></body></html>\n");
    }
}
