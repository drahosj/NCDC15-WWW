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
    }
    else
    {
        printf("Set-cookie: access_token=deleted; path=/; expires=Thu, 01 Jan 1970 00:00:00 GMT\n");
    }
    redirect("/cgi-bin/show/landing");
    headers();
}
