#include <string.h>
#include <stdio.h>
#include <assert.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
//类型的声明
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;

//通讯录
typedef struct Contact
{
    PeoInfo data[MAX];
    int count;//记录当前通讯录中实际人数
}Contact;

void InitContact(Contact* pc);
void AddContact(Contact* pc);
void ShowContact(const Contact* pc);
void DelContact(Contact* pc);
