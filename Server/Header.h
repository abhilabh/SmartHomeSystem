#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include<pthread.h>
#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<mysql.h>
#include<signal.h>
#include<time.h>
#define ADMIN 1
#define FLATE_OWNER 2
#define EXIT 3
#define Choice_Size 2
#define bZero 0
#define bOne 1
#define bTwo 2
#define bListen 5
#define nSize 200
#define CREATE_FLAT_ACCOUNT 1
#define DELETE_ACCOUNT 2
#define VIEW_APPLIANCE_STATUS 3
#define GENERATE_REPORT 4
#define ADMIN_LOGOUT 5
#define REGISTER_APPLIANCE 1
#define MODIFY_APPLIANCE_CONTROL 2
#define VIEW_APPLIANCE_STATUS 3
#define CONTROL_APPLIANCE 4
#define ADD_FAMILY_MEMBERS 5
#define CHANGE_LOGIN_CREDENTIALS 6
#define QUIT 7

struct login
{
        char strUserName[10];
        char strUserPassword[15];
};
