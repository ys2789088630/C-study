#include "contact.h"


void InitContact(Contact* pc)
{
    assert(pc);
    pc->count = 0;
    memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
    assert(pc);
    if (pc->count == MAX)
    {
        printf("通讯录已满,无法添加\n");
        return;
    }
    printf("请输入名字:>");
    scanf("%s", pc->data[pc->count].name);
    printf("请输入年龄:>");
    scanf("%d", &(pc->data[pc->count].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pc->count].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pc->count].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pc->count].addr);

    pc->count++;
    printf("增加成功\n");
}

void ShowContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    printf("%*s\t%5s\t%*s\t%*s\t%*s\n", MAX_NAME, "名字", "年龄", MAX_SEX, "性别",
        MAX_TELE, "电话",MAX_ADDR,  "地址");
    for (i = 0; i < pc->count; ++i)
    {
        printf("%*s\t%5d\t%*s\t%*s\t%*s\n", MAX_NAME, pc->data[i].name,
            pc->data[i].age,
            MAX_SEX, pc->data[i].sex,
            MAX_TELE, pc->data[i].tele,
            MAX_ADDR, pc->data[i].addr
            );
    }
}

static int FindByName(Contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->count; ++i)
    {
        if (0 == strcmp(pc->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void DelContact(Contact* pc)
{
    char name[MAX_NAME] = { 0 };
    int i = 0;
    assert(pc);
    if (pc->count == 0)
    {
        printf("已经为空啦\n");
        return;
    }
    printf("请输入要删除的人的名字:>");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要删除的人不存在\n");
        return;
    }
    //删除
    for (i = pos; i < pc->count; ++i)
    {
        pc->data[i] = pc->data[i + 1];
    }
    --pc->count;
    printf("删除成功\n");
}