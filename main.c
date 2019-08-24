#include <stdio.h>
#include <stdlib.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int rock_paper_scissors(int player1, int player2);

int main() {
    printf("Hello, World!\n");
    return 0;
}

int rock_paper_scissors(int player1, int player2){
    int result;
    if(player1 == ROCK && player2 == PAPER){
        result = PLAYER2_WIN;
    }
    else if(player1 == ROCK && player2 == SCISSORS){
        result = PLAYER1_WIN;
    }
    else if(player1 == PAPER && player2 == ROCK){
        result = PLAYER1_WIN;
    }
    else if(player1 == PAPER && player2 == SCISSORS){
        result = PLAYER2_WIN;
    }
    else if(player1 == SCISSORS && player2 == ROCK){
        result = PLAYER2_WIN;
    }
    else if(player1 == SCISSORS && player2 == PAPER){
        result = PLAYER1_WIN;
    }
    else {
        result = DRAW;
    }
}