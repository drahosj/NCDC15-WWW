#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void main()
{
    char buffer[64];
    char buffer2[64];
    char * line = NULL;
    size_t line_len = 0;
    char name[64];

    if(require_admin_token())
        return forbidden();

    if (strcmp("POST", getenv("REQUEST_METHOD")) == 0)
    {
        getline(&line, &line_len, stdin);
    }
    else
    {
        line = getenv("QUERY_STRING");
    }

    strcpy(name, post_value(line, "user_name"));

    sprintf(buffer, "../../db/user_%s", name);

    if (file_exists(buffer))
    {
        headers_html();

        sprintf(buffer2, "rm %s", buffer);
        system(buffer2);
        printf("User %s deleted!\n", name);
    }
    else
    {
        printf("Status: 404\n");
        headers_html();
        printf("User %s not found!\n", name);
    }
}

