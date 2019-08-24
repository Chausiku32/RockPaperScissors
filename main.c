#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int rock_paper_scissors(int player1, int player2);

int get_user_input();

void print_word(int v);

int main() {

    int user_score = 0;
    int computer_score = 0;

    int quit = 0;
    while(!quit){

        int user_input = get_user_input();
        int computer_choice = (rand() % 3) + 1;

        //as it generates 0, 1 and/or 2;
        srand(time(NULL));

        printf("Computer chose: \n");
        print_word(computer_choice);
        printf("User chose: \n");
        print_word(user_input);

        int result = rock_paper_scissors(user_input, computer_choice);

        if(result == DRAW){
            printf("It is a draw\n");
        }else if(result == PLAYER1_WIN){
            printf("User wins and computer lost\n");
            user_score++;
        }
        else if(result == PLAYER2_WIN){
            printf("Computer wins and user lost\n");
            computer_score++;
        }

        printf("\n");
        printf("_____________________________\n");
        printf("User score: %d\n", user_score);
        printf("Computer score: %d\n", computer_score);
        printf("_____________________________\n");

        printf("If you want to continue input any integer, 0 to terminate. \n");
        int response;
        scanf("%d", &response);
        if(response == 0){
            quit = 1;
        }
    }
    printf("Final score... \n");
    printf("\n");
    printf("_____________________________\n");
    printf("User score: %d\n", user_score);
    printf("Computer score: %d\n", computer_score);
    printf("_____________________________\n");
    printf("\n\n");

    if(user_score == computer_score){
        printf("GAME WAS DRAWN\n");
    }
    else if(user_score > computer_score){
        printf("USER WINS THE GAME\n");
    }
    else{
        printf("COMPUTER WINS THE GAME\n");
    }
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

int get_user_input(){
    int choice;
    do{
        printf("1. ROCK\n");
        printf("2. PAPER\n");
        printf("3. SCISSORS\n");
        printf("Please input [1, 2, 3]: \n");
        scanf("%d", &choice);
        if(! (choice >= 1 && choice <= 3)){
            printf("ERROR... INVALID INPUT, should be 1 or 2 or 3 \n");
        }
    }
    while(! (choice >= 1 && choice <= 3));
    return choice;
}

void print_word(int v){
    if(v == ROCK){
        printf("Rock\n");
    }
    else if(v == PAPER){
        printf("Paper\n");
    }
    else{
        printf("Scissors\n");
    }
}