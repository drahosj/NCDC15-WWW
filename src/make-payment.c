#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char buffer[64];
    char user_name[32];
    char access_token[64];
    int amount = 0;
    int new_amount = 0;
    char other_party[32];
    int other_party_new_amount;

    strcpy(access_token, post_value(getenv("HTTP_COOKIE"), "access_token"));
    stringify_hex(access_token, user_name);

    if(strcmp(user_name, "ADMININSTRATOR") == 0)
    {
        get_parameter("user_name", user_name);
    }

    if (check_user(user_name) == 0)
    {
        printf("Status: 404\n");
        headers();
        printf("User not into existing!\n");    
        return;
    }
    get_parameter("other_party", other_party);
    if (check_user(other_party) == 0)
    {
        printf("Status: 404\n");
        headers();
        printf("Other party not into existing!\n");
        return;
    }

    get_parameter("amount", buffer);
    sscanf(buffer, "%d", &amount);
    new_amount = get_balance(user_name) - amount;
    other_party_new_amount = get_balance(other_party) + amount;
    
    sprintf(buffer, "echo to: %s %d %d >> ../../db/user_%s", other_party, amount, new_amount, user_name);
    system(buffer);

    sprintf(buffer, "echo from: %s %d %d >> ../../db/user_%s", user_name, amount, other_party_new_amount, other_party);
    system(buffer);

    sprintf(buffer, "/cgi-bin/show/show-user?user_name=%s", user_name);
    redirect(buffer);
    headers();
    printf("amt %d",get_balance(user_name));
}
