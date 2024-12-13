#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

#define BOLD_BLACK   "\033[1;30m"
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

int  rand_number();
int GenerateNumber();
void hide_cursor();
void welcome();
void initialize();
void clear_screen();
void village_detals();
void making_road();
void gotoxy(int x, int y);


int dim_x;
int dim_y;
int x_c1;
int y_c1;
int x_c2;
int y_c2;
char kingdom[2][2];
int numb_king = 1;
int map[17][17];
int detail[17][4];
int x_houses[287][2];
int farmanrava[1][2];
int cost = 0;

int main(){
    srand(time(NULL));
    hide_cursor();
    welcome();
    initialize();
    making_road();
    return 0;
}

int rand_number(){
    //srand(time(NULL));

    //int random_num_0_to_9 = rand() % 10;
    //printf("Random number between 0 and 9: %d\n", random_num_0_to_9);


    int random_num_1_to_6 = rand() % 5 + 1;
    //printf("Random number between 1 and 6: %d\n", random_num_1_to_6);
}


void gotoxy(int x, int y) {
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorCoord;
cursorCoord.X = y;
cursorCoord.Y = x;
SetConsoleCursorPosition(consoleHandle, cursorCoord);
}


void initialize(){

    int v_count;
    int village_x_location;
    int village_y_location;
    int i ,iy;
    int j ,jx;

    gotoxy(1,90);
    printf("x dimension : ");
    scanf("%d", &dim_x);
    if(dim_x==0) return 1;
    gotoxy(2,90);
    printf("y dimension : ");
    scanf("%d", &dim_y);
    if(dim_y==0) return 1;

    gotoxy(3,90);
    printf(RED"dimension is %d x %d \n"RESET, dim_x,dim_y);

    gotoxy(4,90);
    printf("count of kingdom ");
    scanf("%d", &numb_king);

    if(numb_king>2 || numb_king<0) return 1;

    kingdom[numb_king][2];

    //int xc1 = 18;
    //int yc1 = 18;

    farmanrava[numb_king][2];

    for(i=0;i<numb_king;i++){
        gotoxy(2*i+5,90);
        printf(GREEN"please enter the X position of c%d : "RESET,i+1);
        scanf("%d", &farmanrava[i][1]);
        if(farmanrava[i][1]>=dim_x) return 1;
        gotoxy(2*i+6,90);
        printf(GREEN"please enter the Y position of c%d : "RESET,i+1);
        scanf("%d", &farmanrava[i][0]);
        if(farmanrava[i][0]>=dim_y) return 1;
        }
        if(farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1] || farmanrava[0][0]==farmanrava[1][0]+1 && farmanrava[0][1]==farmanrava[1][1]+1 || farmanrava[0][0]==farmanrava[1][0]+1 && farmanrava[0][1]==farmanrava[1][1] || farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1]+1 || farmanrava[0][0]==farmanrava[1][0]-1 && farmanrava[0][1]==farmanrava[1][1]-1 || farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1]-1 || farmanrava[0][0]==farmanrava[1][0]-1 && farmanrava[0][1]==farmanrava[1][1]) return 1;

    int s = 0;
    int x_house;
    int x_x_house;
    int y_x_house;
    gotoxy(9,90);
    printf(BOLD_RED"count x house:"RESET);
    scanf("%d", &x_house);
    x_houses[x_house][2];
    for(i=0;i<x_house;i++){
        gotoxy(2*i+10,90);
        printf(BOLD_RED"x of x house %d :"RESET, i+1);
        scanf("%d", &x_houses[i][0]);
        if(x_houses[i][0]>=dim_x) return 1;
        gotoxy(2*i+11,90);
        printf(BOLD_RED"y of x house %d :"RESET, i+1);
        scanf("%d", &x_houses[i][1]);
        if(x_houses[i][1]>=dim_y) return 1;
        gotoxy(2*i+12,90);
        if(x_houses[i][0]==farmanrava[s][1] && x_houses[i][1]==farmanrava[s][0]) {return 1;}
    }

    gotoxy(2*i+12,90);
    printf(BOLD_MAGENTA"please enter the count of villages : "RESET);
    scanf("%d", &v_count);
    detail[v_count][4];
    int offset_v = 2 * i +13;
    int villa_count = 0;
    while(villa_count<v_count){
    gotoxy(4*villa_count+offset_v+1,90);
    printf("village(%d) x cordinate:", villa_count+1);
    scanf("%d", &detail[villa_count][0]);
    if(detail[villa_count][0]>=dim_x) return 1;
    gotoxy(4*villa_count+offset_v+2,90);
    printf("village(%d) y cordinate:", villa_count+1);
    scanf("%d", &detail[villa_count][1]);
    if(detail[villa_count][1]>=dim_y) return 1;
    gotoxy(4*villa_count+offset_v+3,90);
    printf("village(%d) gold range :", villa_count+1);
    scanf("%d", &detail[villa_count][2]);
    gotoxy(4*villa_count+offset_v+4,90);
    printf("village(%d) food range :", villa_count+1);
    scanf("%d", &detail[villa_count][3]);
    villa_count++;
    }

    clear_screen();
    i = 0;
    j = 0;
    int v = 0;
    gotoxy(1,70);
    printf(BOLD_GREEN"your dimension"RESET);
    clear_screen();
    y_c1 = farmanrava[i][0];
    x_c1 = farmanrava[i][1];
    for(iy=0;iy<dim_y;iy++){
        for(jx=0;jx<dim_x;jx++){
            map[iy][jx] = rand_number();
            if(iy==y_c1 && jx==x_c1) map[iy][jx] = 0;
        }
    }
    for(iy=0;iy<dim_y;iy++){
        for(jx=0;jx<dim_x;jx++){
            gotoxy(2*iy+1,4*jx+1+70);
            if(jx==farmanrava[0][1] && iy==farmanrava[0][0]) printf(BOLD_GREEN"C%d"RESET,1);
            else if (jx==farmanrava[1][1] && iy==farmanrava[1][0]) printf(BOLD_GREEN"C%d"RESET,2);
            else printf(BOLD_WHITE"%d"RESET, map[iy][jx]);
            }
        }

    for(i=0;i<x_house;i++){
        iy = x_houses[i][0];
        jx = x_houses[i][1];
        gotoxy(2*iy+1,4*jx+1+70);
        printf(RED"X"RESET);
    }

    for(i=0;i<v_count;i++){
        iy = detail[i][0];
        jx = detail[i][1];
        gotoxy(2*iy+1,4*jx+1+70);
        printf(MAGENTA"V"RESET);
    }


    gotoxy(35,0);
    for(i=0;i<210;i++) printf("-");
    i = 0;
    gotoxy(38,0);
    while(i<v_count){
        printf("village(%d) x cordinat:%d\n",i+1,detail[i][1]);
        printf("village(%d) y cordinat:%d\n",i+1,detail[i][0]);
        printf("village(%d) gold range:%d\n",i+1,detail[i][2]);
        printf("village(%d) food range:%d\n",i+1,detail[i][3]);
        i++;
   }


    gotoxy(2*y_c1+1,4*x_c1+1+70);
}

void making_road(){

    x_c1 = farmanrava[0][1];
    y_c1 = farmanrava[0][0];
    gotoxy(2*y_c1 + 1,4*x_c1 + 1 + 70);
    int currentx=x_c1;
    int currenty=y_c1;

    int allow_up = 0;
    int allow_dn = 0;
    int allow_r = 0;
    int allow_l = 0;

    while(1){

    if(currenty!=0){
        if(map[currenty][currentx]==0 || map[currenty-1][currentx]==0) allow_up = 1;
        else allow_up = 0;
    }

        if(currenty!=dim_y-1){
        if(map[currenty][currentx]==0 || map[currenty+1][currentx]==0) allow_dn = 1;
        else allow_dn = 0;
    }

        if(currentx!=dim_x-1){
        if(map[currenty][currentx]==0 || map[currenty][currentx+1]==0) allow_r = 1;
        else allow_r = 0;
    }

        if(currentx!=0){
        if(map[currenty][currentx]==0 || map[currenty][currentx-1]==0) allow_l = 1;
        else allow_l = 0;
    }

    gotoxy(36 , 80);
    printf("Currentx:(%d)  CurrentY:(%d)   ",currentx,currenty);
    gotoxy(2*currenty + 1,4*currentx + 1 + 70);

    int r;
    int a1 = getch();
    if(a1==224){
        int a2=getch();
        if(a2==72 && y_c1>0 && allow_up==1){
            currenty--;
            allow_up = 0;
            allow_r = 0;
            allow_l = 0;
        }
        if(a2==80 && y_c1<dim_y-1 && allow_dn==1){
            currenty++;
            allow_dn = 0;
            allow_r = 0;
            allow_l = 0;
        }

        if(a2==77&&x_c1<dim_x-1&&allow_r==1){
            currentx++;
            allow_r = 0;
            allow_dn = 0;
            allow_up = 0;
        }

        if(a2==75&&x_c1>0&&allow_l==1){
            currentx--;
            allow_l = 0;
            allow_up = 0;
            allow_dn = 0;
            }

        }
    if(a1==114){
        cost+=map[currenty][currentx];
        map[currenty][currentx] = 0;
        gotoxy(2*currenty + 1,4*currentx + 1 + 70);
        printf("=");
        gotoxy(2*currenty + 1,4*currentx + 1 + 70);
        }
    }
}

void clear_screen(){
system("cls");
}

void hide_cursor(){
    CONSOLE_CURSOR_INFO CURSORINFO;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSORINFO);
    CURSORINFO.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CURSORINFO);
}

void welcome(){

    clear_screen();

    gotoxy(1,50);
    printf(GREEN"*             *  *****  *       ****  ***        *   *      *****\n"RESET);
    gotoxy(2,50);
    printf(GREEN" *           *   *      *      *     *   *      * * * *     *    \n"RESET);
    gotoxy(3,50);
    printf(GREEN"  *    *    *    ****   *      *     *   *     *   *   *    **** \n"RESET);
    gotoxy(4,50);
    printf(GREEN"   *  *  * *     *      *      *     *   *    *         *   *    \n"RESET);
    gotoxy(5,50);
    printf(GREEN"    *     *      *****  *****   ****  ***    *           *  *****\n"RESET);

    getch();
    clear_screen();

    gotoxy(1,90);
    printf("RAHE RASTEGARI");

    gotoxy(2, 80);
    printf("Created by :Saeed Fahimi and Enayat Balaghi\n");

    gotoxy(3, 80);
    printf("Professor Abrishami\n");

    gotoxy(5,80);
    printf("please enter to countinue");
    getch();
    clear_screen();
}




