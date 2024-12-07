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

void hide_cursor();
void welcome();
void initialize();
void clear_screen();
int rand_number();
void village_detals();
void gotoxy(int x, int y);


int dim_x;
int dim_y;
int x_c1;
int y_c1;
int x_c2;
int y_c2;
char kingdom[2][2];
int numb_king;
char map[17][17];
char detail[17][4];
char x_houses[287][2];

int main(){

    hide_cursor();
    welcome();
    initialize();
    return 0;
}

int rand_number(){
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        printf("%d\n", rand());
    }

    int random_num_0_to_9 = rand() % 10;
    printf("Random number between 0 and 9: %d\n", random_num_0_to_9);


    int random_num_1_to_6 = rand() % 6 + 1;
    printf("Random number between 1 and 6: %d\n", random_num_1_to_6);
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

    printf("your x dimension :");
    scanf("%d", &dim_x);
    printf("your y dimension :");
    scanf("%d", &dim_y);

    for(iy=0;iy<dim_y;iy++){
        for(jx=0;jx<dim_x;jx++){
            map[iy][jx] = '1';
        }
    }

    printf(RED"dimension is %d x %d\n"RESET, dim_x,dim_y);

    printf("count of kingdom");

    scanf("%d", &numb_king);

    if(numb_king>2 || numb_king<0) return 1;

    kingdom[numb_king][2];

    int xc1 = 18;
    int yc1 = 18;

    int farmanrava[numb_king][2];

    for(i=0;i<numb_king;i++){
        printf(GREEN"please enter the x position of c%d : "RESET,i+1);
        scanf("%d", &farmanrava[i][0]);
        printf(GREEN"please enter the y position of c%d : "RESET,i+1);
        scanf("%d", &farmanrava[i][1]);
        map[farmanrava[i][0]][farmanrava[i][1]] = 'c';
        }
        if(farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1] || farmanrava[0][0]==farmanrava[1][0]+1 && farmanrava[0][1]==farmanrava[1][1]+1 || farmanrava[0][0]==farmanrava[1][0]+1 && farmanrava[0][1]==farmanrava[1][1] || farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1]+1 || farmanrava[0][0]==farmanrava[1][0]-1 && farmanrava[0][1]==farmanrava[1][1]-1 || farmanrava[0][0]==farmanrava[1][0] && farmanrava[0][1]==farmanrava[1][1]-1 || farmanrava[0][0]==farmanrava[1][0]-1 && farmanrava[0][1]==farmanrava[1][1]) return 1;


    int x_house;
    int x_x_house;
    int y_x_house;
    printf("count x house:");
    scanf("%d", &x_house);
    x_houses[x_house][2];
    for(i=0;i<x_house;i++){
        printf("x of x house %d :", i+1);
        scanf("%d", &x_houses[i][0]);
        printf("y of x house %d :", i+1);
        scanf("%d", &x_houses[i][1]);
        map[x_houses[i][0]][x_houses[i][1]] = 'x';
    }

    printf(BOLD_MAGENTA"please enter the count of villages : "RESET);
    scanf("%d", &v_count);
    detail[v_count][4];
    int villa_count = 0;

    while(villa_count<v_count){
    printf("village(%d) x cordinate:", villa_count+1);
    scanf("%d", &detail[villa_count][0]);
    printf("village(%d) y cordinate:", villa_count+1);
    scanf("%d", &detail[villa_count][1]);
    printf("village(%d) gold range :", villa_count+1);
    scanf("%d", &detail[villa_count][2]);
    printf("village(%d) food range :", villa_count+1);
    scanf("%d", &detail[villa_count][3]);
    map[detail[villa_count][0]][detail[villa_count][1]] = 'v';
    villa_count++;
    }

    clear_screen();
    i = 0;
    j = 0;
    int v = 0;
    gotoxy(1,70);
    printf(BOLD_GREEN"your dimension"RESET);
    clear_screen();
    for(iy=0;iy<dim_y;iy++){
        for(jx=0;jx<dim_x;jx++){
            gotoxy(2*iy+1,4*jx+1+70);
            if((jx==farmanrava[0][0] && iy==farmanrava[0][1])||(jx==farmanrava[1][0] && iy==farmanrava[1][1])) {printf(GREEN"%c"RESET, map[iy][jx]);}
            else{
                printf("%c", map[iy][jx]);
            }
        }
    }

    gotoxy(35,0);
    for(i=0;i<210;i++) printf("-");
    i = 0;
    gotoxy(38,0);
    while(i<v_count){
        printf("village(%d) x cordinate:%d\n",i+1,detail[i][1]);
        printf("village(%d) y cordinate:%d\n",i+1,detail[i][0]);
        printf("village(%d) gold range:%d\n",i+1,detail[i][2]);
        printf("village(%d) food range:%d\n",i+1,detail[i][3]);
        i++;
   }

    gotoxy(2*y_c1 + 1,4*x_c1 + 1 + 70);
    int currentx=x_c1;
    int currenty=y_c1;

    while(1){
    gotoxy(2*y_c1 + 1,4*x_c1 + 1 + 70);
    currentx=x_c1;
    currenty=y_c1;
    gotoxy(36 , 80);
    printf("Currentx:%d  CurrentY:%d   ",x_c1,y_c1);
    gotoxy(2*y_c1 + 1,4*x_c1 + 1 + 70);
    int a1 = getch();

    if(a1==224){
        int a2=getch();
        if(a2==72&&y_c1>0){
            y_c1--;
        }
        if(a2==80&&y_c1<dim_y-1){
            y_c1++;
        }
        if(a2==77&&x_c1<dim_x-1){
            x_c1++;
        }
        if(a2==75&&x_c1>0){
            x_c1--;
            }
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

    printf(GREEN"W     W  EEEEE  L       CCCC  OOO   M   M  EEEEE\n"RESET);
    printf(GREEN"W     W  E      L      C     O   O  MM MM  E    \n"RESET);
    printf(GREEN"W  W  W  EEEE   L      C     O   O  M M M  EEEE \n"RESET);
    printf(GREEN"W  W  W  E      L      C     O   O  M   M  E    \n"RESET);
    printf(GREEN"W     W  EEEEE  LLLLL   CCCC  OOO   M   M  EEEEE\n"RESET);

    printf("\n");

    getch();

    clear_screen();

    printf(GREEN"RRRR       A       H   H   EEEEE     RRRR         A        SSSSS   TTTTT   EEEEE    GGGGG        A       RRRR      III \n"RESET);
    printf(GREEN"R   R     A A      H   H   E         R   R       A A       S         T     E        G           A A      R   R      I  \n"RESET);
    printf(GREEN"RRRR     AAAAA     HHHHH   EEEE      RRRR       AAAAA      SSSSS     T     EEEE     G  GG      AAAAA     RRRR       I  \n"RESET);
    printf(GREEN"R  R    A     A    H   H   E         R  R      A     A         S     T     E        G   G     A     A    R  R       I  \n"RESET);
    printf(GREEN"R   R  A       A   H   H   EEEEE     R   R    A       A    SSSSS     T     EEEEE    GGGGG    A       A   R   R     III \n"RESET);

    getch();
    clear_screen();
    gotoxy(1, 90);
    printf("Created by :saeed fahimi and enayat balaghi\n");

    gotoxy(2, 90);
    printf("Proffessor Abrishami\n");

    gotoxy(4,90);

    printf("pleae enter to countinue");
    getch();
    clear_screen();
}




