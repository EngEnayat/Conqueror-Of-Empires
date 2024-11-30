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
void gotoxy(int x, int y);

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
    int dim_x;
    int dim_y;
    int x_c1;
    int y_c1;
    int x_c2;
    int y_c2;
    int v_count;
    int villa_count = 1;
    int village_x_location;
    int village_y_location;
    int i;
    int j;

    printf("your x dimension :");
    scanf("%d", &dim_x);
    printf("your y dimension :");
    scanf("%d", &dim_y);
    char map[dim_x][dim_y];
    for(i=0;i<dim_x;i++){
        for(j=0;j<dim_y;j++){
            map[i][j] = '1';
        }
    }


    printf(RED"you dimension is %d x %d\n"RESET, dim_y,dim_x);

    printf(GREEN"please enter the x position of c1 : "RESET);
    scanf("%d", &x_c1);
    printf(GREEN"please enter the y position of c1 : "RESET);
    scanf("%d", &y_c1);
    map[x_c1][y_c1] = 'C';

    printf(GREEN"please enter the x position of c2 : "RESET);
    scanf("%d", &x_c2);
    if(x_c2  == x_c1 + 1 || x_c2  == x_c1 - 1 || x_c2  == x_c1) {return 1; printf("your kingdom is same");}
    printf(GREEN"please enter the y position of c2 : "RESET);
    scanf("%d", &y_c2);
    if(y_c2  == y_c1 + 1 || y_c2  == y_c1 - 1 ||  y_c2  == y_c1) {return 1; printf("your kingdom is same");}
    map[x_c2][y_c2] = 'C';

    printf(BOLD_MAGENTA"please enter the count of villages : "RESET);
    scanf("%d", &v_count);
    while(villa_count<=v_count){
    printf("please enter the x of vilage %d:", villa_count);
    scanf("%d", &village_x_location);
    printf("please enter the y of vilage %d:", villa_count);
    scanf("%d", &village_y_location);
    map[village_x_location][village_y_location] = 'v';

    villa_count++;

    }

    clear_screen();

    gotoxy(1,70);
    printf(BOLD_GREEN"your dimension"RESET);
    clear_screen();
    for(i=0;i<dim_x;i++){
        for(j=0;j<dim_y;j++){
            gotoxy(2*i+1,4*j+1+70);
            if((i==x_c1 && j==y_c1)||(i==x_c2 && j==y_c2)) {
                printf(GREEN"%c"RESET, map[i][j]);
            }else{
            printf("%c", map[i][j]);
            }
        }
      //  printf("\n");
     //   printf("\n");
    }

    getch();
    clear_screen();
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




