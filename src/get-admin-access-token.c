#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdlib.h>

void main()
{
    size_t length = 0;
    char * line = NULL;
    char * user_name;
    char attempt_password[35];
    char tokenbuffer[64];
    char tokenbuffer2[64];
    char * method;
    char password_from_db[64];
    FILE * f;

    user_name="ADMINISTRATOR";
    get_parameter("password", attempt_password);

    sprintf(tokenbuffer, "../../db/pass_%s", user_name);
    f = fopen(tokenbuffer, "r");
    if (f != NULL)
    {
        getline(&line, &length, f);
        strcpy(password_from_db, line);

        if (strncmp(attempt_password, password_from_db, strlen(attempt_password)) == 0)
        {
            hexify_string(user_name, tokenbuffer);
            printf("Set-cookie: access_token=%s; Path=/\n", tokenbuffer);
            headers();

            printf("access_token=%s", tokenbuffer);
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
