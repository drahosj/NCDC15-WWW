#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdlib.h>

void main()
{
    size_t length = 0;
    char * line = NULL;
    char user_name[35];
    char attempt_password[35];
    char tokenbuffer[64];
    char tokenbuffer2[64];
    char * method;
    FILE f;

    method = getenv("REQUEST_METHOD");
    if(strcmp(method, "POST") == 0)
    {
        getline(&line, &length, stdin);
    }
    else
    {
        line = getenv("QUERY_STRING");
    }
    strcpy(user_name, post_value(line, "user_name"));
    strcpy(attempt_password, post_value(line, "password"));

    if (strstr(user_name, "&") != NULL)
        strstr(user_name, "&")[0] = 0;

    if (strstr(attempt_password, "&") != NULL)
        strstr(attempt_password, "&")[0] = 0;

    if (strstr(attempt_password, "\n") != NULL)
        strstr(attempt_password, "\n")[0] = 0;

//    if (strcmp(attempt_password, password_from_db)) //TODO: Way to get this
    if(strcmp(attempt_password, "hunter2") == 0)
    {
        headers();
        hexify_string(user_name, tokenbuffer);
        printf("Set access token to %s\n", tokenbuffer);
        stringify_hex(tokenbuffer, tokenbuffer2);
        printf("Stringified: %s\n", tokenbuffer2);
    }
    else
    {
        headers();
        printf("Wrong!\n");
    }
}
