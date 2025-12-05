#include <stdio.h>

#include <conio.h>

char g_arr[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,0,0,0,0,0,1},
    {1,0,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,9,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

void refresh(){

    system("cls");
    for(int i = 0;i < 10;i++){

        for (int j=0;j <10;j++){

            if (g_arr[i][j] == 0) {
                 printf(" ");
            }

            else if(g_arr[i][j] == 1) {
                printf("田");
            }

            else if(g_arr[i][j] == 2) {
                printf("人");
            }
            else if(g_arr[i][j] == 3) {
                printf("口");
            }

            else if(g_arr[i][j] == 9) {
                printf("回");
            }
        }
        printf("\n");

    }

}

int move(int cmd) {

    int x,y;
    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 10; j++) {

            if (g_arr[i][j] == 2) {

                x = j;
                y = i;
            }
        }
    }

    char* man = &g_arr[y][x];
    if ( cmd == 119) {//W

    char* up1 = &g_arr[y-1][x];
    if( *up1 ==0){
        *up1 =2;
        *man = 0;
    } else if (*up1 == 3) {

        char* up2 = &g_arr[y-2][x];
        if (*up2 == 0) {
            *up2 = *up1;
            *up1 = *man;
            *man = 0;
        } else if (*up2 == 9) {
            *up2 = *up1;
            *up1 = *man;
            *man = 0;
            return 1;
        }
    }
}

else if ( cmd == 115) {//S
    char* down1 = &g_arr[y+1][x];
    if( *down1 ==0){
        *down1 =2;
        *man = 0;
    } else if (*down1 == 3) {

        char* down2 = &g_arr[y+2][x];
        if (*down2 == 0) {
            *down2 = *down1;
            *down1 = *man;
            *man = 0;
        } else if (*down2 == 9) {
            *down2 = *down1;
            *down1 = *man;
            *man = 0;
            return 1;
        }
    }
}

else if ( cmd == 97) {//A
    char* left1 = &g_arr[y][x-1];
    if( *left1 ==0){
        *left1 =2;
        *man = 0;
    } else if (*left1 == 3) {

        char* left2 = &g_arr[y][x-2];
        if (*left2 == 0) {
            *left2 = *left1;
            *left1 = *man;
            *man = 0;
        } else if (*left2 == 9) {
            *left2 = *left1;
            *left1 = *man;
            *man = 0;
            return 1;
        }
    }
}

else if( cmd == 100) {//D
    char* right1 = &g_arr[y][x+1];
    if( *right1 ==0){
        *right1 =2;
        *man = 0;
    } else if (*right1 == 3) {

        char* right2 = &g_arr[y][x+2];
        if (*right2 == 0) {
            *right2 = *right1;
            *right1 = *man;
            *man = 0;
        } else if (*right2 == 9) {
            *right2 = *right1;
            *right1 = *man;
            *man = 0;
            return 1;
            }
        }
    }

}

int main(){
    refresh();
    while (1) {
        refresh();
        int cmd =_getch;
        int ret = move(cmd);
        refresh;
        if (ret != 0) {
            printf("WIN\n");
            break;
        }
    }
    return 0;
}