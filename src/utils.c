#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int require_admin_token()
{
    char * cookie;

    cookie=getenv("HTTP_COOKIE");
    printf("Users cookie is cookie\n", cookie);
}
