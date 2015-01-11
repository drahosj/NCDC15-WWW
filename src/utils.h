#ifndef __UTILS_H
#define __UTILS_H
void headers();
void headers_html();
void redirect(char *);
char * query_string();
char * query_value(char * key);
char * post_value(char * str, char * key);
int file_exists(char * filename);
int require_user_token(char * user);
int require_admin_token();
void forbidden();
void get_parameter(char * key, char * buffer);
int check_user(char * user_name);
#endif
