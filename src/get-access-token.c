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
    char password_from_db[64];
    FILE * f;

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

    sprintf(tokenbuffer, "../../db/pass_%s", user_name);
    f = fopen(tokenbuffer, "r");
    if (f != NULL)
    {
        getline(&line, &length, f);
        strcpy(password_from_db, line);

        if (strncmp(attempt_password, password_from_db, strlen(attempt_password)) == 0)
        {
            hexify_string(user_name, tokenbuffer);
            printf("Set-cookie: access_token=%s; Path=/;\n", tokenbuffer);
            redirect("/cgi-bin/show/landing");
            headers();

            printf("access_token=%s\n", tokenbuffer);
        }
        else
        {
            headers();
            printf("Wrong!\n");
        }
    }
    else
    {
        headers();
        printf("User not into existing\n");
    }
}
