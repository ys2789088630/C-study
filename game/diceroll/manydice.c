#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int dice;
    int roll;//所有骰子分数之和
    int sides;
    int status;

    srand((unsigned int) time(0));//时间戳重置seed
    printf("Enter the number of sides per die, 0 to stop.\n");

    while(scanf("%d", &sides) == 1 && sides > 0)
    {
        printf("How many dice?\n");
        //非法校验
        if((status = scanf("%d", &dice)) != 1)
        {
            if (status == EOF)
            {
                break;
            }
             else
           {
            printf("You should have entered an integer.");
            printf("    Let's  begin  again.\n ");

            while (getchar() != '\n')
            {
                continue;
            }

            printf("How many sides?  Enter 0 to stop.\n");
            continue;
           }
        }
       roll = roll_n_dice (dice, sides);
       printf("You have rolled a %d using %d %d-sided dice.\n",roll, dice, sides);
       printf("How many sides?  Enter 0 to stop.\n");
    }
    printf ("The rollem() function was called %d times.\n", roll_count);
    printf ("GOOD FORTUNR TO YOU!\n");

    return 0;
}

