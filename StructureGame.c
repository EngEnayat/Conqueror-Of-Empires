#include <stdio.h>
void Map();
int main()
{
    Map();
}
void Map()
{
    int n=5, m=5;
    char Map[5][5]={
        {'C', '1', '1', 'X', 'V'},
        {'X', 'X', 'X','1', 'X'},
        {'1', '1', 'X', 'V', 'X'},
        {'X', 'V', '1', 'X', 'X'},
        {'X', 'V', '1', '1', 'C'}
    };
    for (int i=0;i<n;i++){
         for (int j=0;j<n;j++)
            printf("%c   ", Map[i][j]);
        printf("\n");
    }
}

// Map[0][0] ='C', Map[0][1] = '1', Map[0][2] ='1', Map[0][3] = 'X', Map[0][4] = 'V';
//     Map[1][0] ='X', Map[1][1] = 'X', Map[1][2] ='X', Map[1][3] = '1', Map[1][4] = 'X';
//     Map[2][0] ='1', Map[2][1] = '1', Map[2][2] ='X', Map[2][3] = 'V', Map[2][4] = 'X';
//     Map[3][0] ='X', Map[3][1] = 'V', Map[3][2] ='1', Map[3][3] = 'X', Map[3][4] = 'X';
//     Map[4][0] ='X', Map[4][1] = 'V', Map[4][2] ='1', Map[4][3] = '1', Map[4][4] = 'C';
//     for (int i=0; i<n;i++){