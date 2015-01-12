#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void headers()
{
    printf("Content-type: text/plain\n\n");
}

void headers_html()
{
    printf("Content-type: text/html\n\n");
}

void redirect(char * location)
{
    printf("Status:302\nLocation: %s\n", location);
}

char * query_string()
{
    return getenv("QUERY_STRING");
}

char * query_value(char * key)
{
    char * offset;
    offset = strstr(query_string(), key);
    if (offset == NULL)
        return NULL;
    
    return offset + strlen(key) + 1;
}

char * post_value(char * str, char * key)
{
    char * offset;
    offset = strstr(str, key);
    if (offset == NULL)
        return NULL;
    
    return offset + strlen(key) + 1;
}

int file_exists(char * filename)
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

void hexify_string(char * str, char * hexstr)
{
    int i = 0;
    char tmpbuffer1[128] = "";
    char tmpbuffer2[4] = "";
    for (i = 0; i < strlen(str); i++)
    {
        sprintf(tmpbuffer2, "%02X", str[i]);
        strcat(tmpbuffer1, tmpbuffer2);
    }
    strcpy(hexstr, tmpbuffer1);
}

void stringify_hex(char * hexstr, char * str)
{
    int i = 0;
    char tmpbuffer1[128] = "";
    char tmpbuffer2[4] = "";
    
    tmpbuffer2[2] = 0;
    for(i = 0; i < (strlen(hexstr)/2); i++)
    {
        tmpbuffer2[0] = hexstr[i*2];
        tmpbuffer2[1] = hexstr[(i*2) + 1];
        sscanf(tmpbuffer2, "%X", tmpbuffer1 + i);
    }
    strcpy(str, tmpbuffer1);
}

void forbidden()
{
    printf("Status: 403\n");
    headers();
    printf("Forbidden!");
}

int require_admin_token()
{
    char buffer[512];

    hexify_string("ADMINISTRATOR", buffer);

    if (getenv("HTTP_COOKIE") == NULL || post_value(getenv("HTTP_COOKIE"), "access_token") == NULL)
        return 1;

    return strcmp(buffer, post_value(getenv("HTTP_COOKIE"), "access_token"));
}

int require_user_token(char * user)
{
    if (require_admin_token() == 0)
        return require_admin_token();

    if (getenv("HTTP_COOKIE") == NULL || post_value(getenv("HTTP_COOKIE"), "access_token") == NULL)
        return 1;

    char buffer[512];
    hexify_string(user, buffer);
    return strcmp(buffer, post_value(getenv("HTTP_COOKIE"), "access_token"));
}

int get_balance(char * user)
{
    FILE * f;
    char buffer[512];
    int last_balance = 0;;
    char * index;

    sprintf(buffer, "../../db/user_%s", user);
    f = fopen(buffer, "r");
    while(!feof(f))
    {
        memset(buffer, 0, 512);
        fgets(buffer, 512, f);
        index = rindex(buffer, ' ');
        if (index == NULL)
            break;
        sscanf(index, " %d", &last_balance);
    }
    return last_balance;
}

void get_parameter(char * key, char * buffer)
{
    char internal_buffer[128];
    char * line = NULL;
    size_t length = 0;
    char * method;

    line = buffer;

    method = getenv("REQUEST_METHOD");
    if(strcmp(method, "POST") == 0)
    {
        getline(&line, &length, stdin);
    }
    else
    {
        line = getenv("QUERY_STRING");
    }
    strcpy(buffer, post_value(line, key));
    if (strstr(buffer, "&") != NULL)
        strstr(buffer, "&")[0] = 0;

    if (strstr(buffer, "\n") != NULL)
        strstr(buffer, "\n")[0] = 0;
}

int check_user(char * user_name)
{
    FILE * f;
    char buffer[64];
    sprintf(buffer, "../../db/user_%s", user_name);
    if (fopen(buffer, "r"))
        return 1;
    else
        return 0;
}
