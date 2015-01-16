#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char buffer[64];
    char buffer2[128];
    if (getenv("HTTP_COOKIE") == NULL || post_value(getenv("HTTP_COOKIE"), "access_token") == NULL)
    {
        headers_html();
        fflush(stdout);
        system("cat ../../templates/not-logged-in.html");
    }
    else
    {
        stringify_hex(post_value(getenv("HTTP_COOKIE"), "access_token"), buffer);
        sprintf(buffer2, "sed -e 's/&&USER_NAME&&/%s/g' ../../templates/welcome.html", buffer);
        headers_html();
        fflush(stdout);
        system(buffer2);
    }
}
