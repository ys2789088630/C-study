#include "contact.h"

//动态版本

void CheckCapacity(Contact* pc)
{
    if (pc->count == pc->capacity)
    {
        PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
        if (NULL == ptr)
        {
            printf("AddContact: %s\n", strerror(errno));
        }
        else
        {
            pc->data = ptr;
            pc->capacity += INC_SZ;
            printf("扩容成功\n");
        }
        return;
    }
}

void AddContact(Contact* pc)
{
    assert(pc);
    //扩容
    CheckCapacity(pc);
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



void LoadContact(Contact* pc)
{
    FILE* pfRead = fopen("contact.txt", "rb");
    if (NULL == pfRead)
    {
        perror("LoadContact");
        return;
    }
    PeoInfo tmp = { 0 };
    while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
    {
        CheckCapacity(pc);

        pc->data[pc->count] = tmp;
        ++pc->count;
    }
    fclose(pfRead);
    pfRead = NULL;
}

//静态版本
//void InitContact(Contact* pc)
//{
//    assert(pc);
//    pc->count = 0;
//    memset(pc->data, 0, sizeof(pc->data));
//}

//动态版本
int InitContact(Contact* pc)
{
    assert(pc);
    pc->count = 0;
    pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
    if (NULL == pc->data)
    {
        printf("%s\n", strerror(errno));
        return 1;
    }
    pc->capacity = DEFAULT_SZ;
    //加载文件信息到通讯录
    LoadContact(pc);
    return 0;
}
//静态版本
//void AddContact(Contact* pc)
//{
//    assert(pc);
//    if (pc->count == MAX)
//    {
//        printf("通讯录已满,无法添加\n");
//        return;
//    }
//    printf("请输入名字:>");
//    scanf("%s", pc->data[pc->count].name);
//    printf("请输入年龄:>");
//    scanf("%d", &(pc->data[pc->count].age));
//    printf("请输入性别:>");
//    scanf("%s", pc->data[pc->count].sex);
//    printf("请输入电话:>");
//    scanf("%s", pc->data[pc->count].tele);
//    printf("请输入地址:>");
//    scanf("%s", pc->data[pc->count].addr);
//
//    pc->count++;
//    printf("增加成功\n");
//}



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

void SearchContact(const Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = { 0 };
    printf("请输入要查找的人的名字:>");
    scanf("%s", name);

    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要查找的对象不存在\n");
        return;
    }
    else
    {
        printf("%*s\t%5s\t%*s\t%*s\t%*s\n", MAX_NAME, "名字", "年龄", MAX_SEX, "性别",
            MAX_TELE, "电话", MAX_ADDR, "地址");
        printf("%*s\t%5d\t%*s\t%*s\t%*s\n", MAX_NAME, pc->data[pos].name,
            pc->data[pos].age,
            MAX_SEX, pc->data[pos].sex,
            MAX_TELE, pc->data[pos].tele,
            MAX_ADDR, pc->data[pos].addr);
    }
}

void ModifyContact(Contact* pc)
{
    assert(pc);
    char name[MAX_NAME] = { 0 };
    printf("请输入要修改的人的名字:>");
    scanf("%s", name);

    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("要修改的对象不存在\n");
        return;
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", pc->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(pc->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", pc->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", pc->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", pc->data[pos].addr);

        printf("修改成功\n");
    }

}

int cmp_peo_by_name(const void* e1, const void* e2)
{
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)
{
    assert(pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
    printf("排序成功\n");
}

void DestroyContact(Contact* pc)
{
    assert(pc);
    free(pc->data);
    pc->data = NULL;
}

void SaveContact(const Contact* pc)
{
    assert(pc);
    FILE* pfWrite = fopen("contact.txt", "wb");
    if (NULL == pfWrite)
    {
        perror("SaveContact");
        return;
    }
    //写文件-binary
    int i = 0;
    for (i = 0; i < pc->count; ++i)
    {
        fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
    }
}