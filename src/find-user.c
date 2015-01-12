#include <stdio.h>
#include "utils.h"

void main()
{
    char buffer[1024];
    sprintf(buffer, "../../db/user_%s", query_value("user_name"));

    if (require_admin_token())
        return forbidden();

    if (file_exists(buffer))
    {
        headers();
        printf("%d", get_balance(query_value("user_name")));
    }
    else 
    {
        printf("Status: 404\n");
        headers_html();
        printf("<html><body><p>User not found!</p></body></html>\n");
    }
}
