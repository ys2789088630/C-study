#include "Minesweeper.h"

void InitBoard( char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (j = 0; j <= cols; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < rows; i++)
    {
        printf("%d ", i);
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("--------------------------------------\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------------\n");

}

SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;

        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
    return (board[x-1][y] +
    board[x-1][y-1] +
    board[x][y-1] +
    board[x+1][y-1] +
    board[x+1][y] +
    board[x+1][y+1] +
    board[x][y+1] +
    board[x-1][y+1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;//找到的非雷的个数
    while(win < row * col - EASY_COUNT)
    {
    printf("Input x and y:>");
    scanf("%d%d", &x, &y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
    {
        if (show[x][y] != '*')
        {
            printf("Don't repeat.\n");
            continue;
        }
        if(mine[x][y] == '1')
        {
            printf("GAME OVER\n");
            DisplayBoard(mine, ROW, COL);
            break;

        }
        else
        {
            win++;
            //统计周围的雷
            int count = get_mine_count(mine, x, y);
            show[x][y] = count + '0';//转换成数字字符
            DisplayBoard(show, ROW, COL);
        }
    }
    else
    {
        printf("Error!Try agin.\n");
    }
}
if(win == row * col - EASY_COUNT)
{
    printf("CONGRATULATIONS!!!\n");
    Displayboard(mine, ROW, COL);
}
}