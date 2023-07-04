/*
* Nome, numero de aluno, e turno pratico dos elementos do grupo:
* Rui Albuquerque: a46897, PL1
* Luís Sá: a46753, PL4
*/


#include <stdio.h>
#define N 3

/* Construção da grelha | Argumento: Matriz bidimensional | Não devolve nenhum valor */
void inicializaGrelha(char grid[N][N])
{
int i;
int j;
for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
grid[i][j] = ' ';
}
}
}

/* Desenhar grelha | Argumento: Matriz bidimensional | Não devolve nenhum valor */
void imprimeGrelha(char grid[N][N])
{
int i;
int j;
for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
if (j < 2) {
printf(" %c |", grid[i][j]);
}
else {
printf(" %c \n", grid[i][j]);
}
}
if (i < 2)
printf("--- --- --- \n");
}
}

/* Movimentação de cada jogador | Argumentos: Matriz bidimensional, três variáveis do tipo inteiro | Devolve a jogada de cada jogador */
int jogada(char grid[N][N], int x, int y, int jogador)
{
int possible;

if (x > 2 || y > 2 || x < 0 || y < 0) {
possible = 1;
}
else if (grid[x][y] != ' ')
{
possible = 2;
}
else
{
grid[x][y] = (jogador == 0) ? 'O' : 'X';
possible = 0;
}

return possible;
}

/* Colocação dos caracteres na grelha | Argumentos: Matriz bidimensional, duas variáveis do tipo inteiro | Devolve a posição de cada caracter */
int tresEmLinha(char grid[N][N], int x, int y)
{
char value = grid[x][y];

if (value == ' ') {
return -1;
}
else
{
if (grid[0][0] == value && grid[1][0] == value && grid[2][0] == value)
{
return 1;
}
else if (grid[0][1] == value && grid[1][1] == value && grid[2][1] == value)
{
return 1;
}
else if (grid[0][2] == value && grid[1][2] == value && grid[2][2] == value)
{
return 1;
}
else if (grid[0][0] == value && grid[0][1] == value && grid[0][2] == value)
{
return 1;
}
else if (grid[1][0] == value && grid[1][1] == value && grid[1][2] == value)
{
return 1;
}
else if (grid[2][0] == value && grid[2][1] == value && grid[2][2] == value)
{
return 1;
}
else if (grid[0][0] == value && grid[1][1] == value && grid[2][2] == value)
{
return 1;
}
else if (grid[2][0] == value && grid[1][1] == value && grid[0][2] == value)
{
return 1;
}
else
{
return 0;
}
}
}


int main(void)
{
/* Variáveis globais */
char grid[N][N];
int curPlayer = 0;
int possible;
int won;
int x = 0;
int y = 0;
int curRound;

/* Desenha a grelha */
inicializaGrelha(grid);

/* Definir movimentação de cada jogador */
for (curRound = 0; curRound < 9; curRound++) {
printf("\e[1;1H\e[2J");

imprimeGrelha(grid);

if (curPlayer == 0) {
printf("\n\njogador O\n\nPosicao X (entre 0 e 2): ");
scanf("%d", &x);

printf("\e[1;1H\e[2J");

imprimeGrelha(grid);
printf("\n\njogador O\n\nPosicao Y (entre 0 e 2): ");
scanf("%d", &y);

possible = jogada(grid, x, y, curPlayer);

while (possible != 0)
{

printf("\e[1;1H\e[2J");
imprimeGrelha(grid);
printf("\n\njogador O\n\nCoordenada invalida por favor repita\n\nPosicao X (entre 0 e 2): ");
scanf("%d", &x);


printf("\e[1;1H\e[2J");

imprimeGrelha(grid);
printf("\n\njogador O\n\nCoordenada invalida por favor repita\n\nPosicao Y (entre 0 e 2): ");
scanf("%d", &y);

possible = jogada(grid, x, y, curPlayer);
}

won = tresEmLinha(grid, x, y);

if (won == 1) {

printf("\e[1;1H\e[2J");
imprimeGrelha(grid);
printf("\nJogador O venceu!\n\n");
break;
}

curPlayer = 1;
}
else
{
printf("\n\njogador X\n\nPosicao X (entre 0 e 2): ");
scanf("%d", &x);


printf("\e[1;1H\e[2J");

imprimeGrelha(grid);
printf("\n\njogador X\n\nPosicao Y (entre 0 e 2): ");
scanf("%d", &y);

possible = jogada(grid, x, y, curPlayer);

while (possible != 0)
{

printf("\e[1;1H\e[2J");
imprimeGrelha(grid);
printf("\n\njogador X\n\nCoordenada invalida por favor repita\n\nPosicao X (entre 0 e 2): ");
scanf("%d", &x);


printf("\e[1;1H\e[2J");

imprimeGrelha(grid);
printf("\n\njogador X\n\nCoordenada invalida por favor repita\n\nPosicao Y (entre 0 e 2): ");
scanf("%d", &y);

possible = jogada(grid, x, y, curPlayer);
}

won = tresEmLinha(grid, x, y);

if (won == 1) {

printf("\e[1;1H\e[2J");
imprimeGrelha(grid);
printf("\nJogador X venceu!\n\n");
break;
}

curPlayer = 0;
}
}

if (won != 1) {

printf("\e[1;1H\e[2J");
imprimeGrelha(grid);
printf("\n\nEmpate!\n\n");
}

return 0;
}
