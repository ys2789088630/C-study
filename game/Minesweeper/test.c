
#include "Minesweeper.h"

void menu()
{
    printf("*************************\n");
    printf("******** 1. Play ********\n");
    printf("******** 0. Exit ********\n");
    printf("*************************\n");
}

void game()
{
    char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
    char show[ROWS][COLS] = {0};//存放排查出的雷的信息
    //初始化
    //mine 没有布置雷的时候都是'0'
    InitBoard( mine, ROWS, COLS, '0');
    //show 没有排查雷的时候都是'*'
    InitBoard( show, ROWS, COLS, '*');
    //DisplayBoard(mine, ROW, COL);
    //设置雷
    SetMine(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //排查雷
    FindMine(mine, show, ROW, COL);

}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("Choice :>");
        scanf("%d", &input);
        switch( input )
        {
            case 1:
                printf("Minesweeper\n");
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Error\n");
                break;
        }
    } while (input);

    return 0;
    
}