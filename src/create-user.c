#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdlib.h>

void main()
{
    size_t length = 0;
    char * method;
    char * line = NULL;
    char user_name[35];
    char redirect_buffer[50];
    char touch_str[64];

    method = getenv("REQUEST_METHOD");
    
    if(strcmp(method, "POST") == 0)
    {
        getline(&line, &length, stdin);
    }
    else
    {
        line = getenv("QUERY_STRING");
    }
    strcpy(user_name, post_value(line, "name"));

    if (strstr(user_name, "&") != NULL)
        strstr(user_name, "&")[0] = 0;

    sprintf(redirect_buffer, "/cgi-bin/show/show-user?user_name=%s", user_name);
    redirect(redirect_buffer);
    headers();

    sprintf(touch_str, "echo from: initial 0 > ../../db/user_%s", user_name);
    system(touch_str);
    printf("New user %s created!\n", user_name);
}
