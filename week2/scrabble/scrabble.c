#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//https://en.cppreference.com/w/cpp/language/ascii.html
// The decimal ASCII values of the upper letters from A to Z go from 65 to 90.


// Constants
//              A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
const int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes
int getScore (string word);

int main (void) {

    //get user input
    string player1_word = get_string("Player 1: ");
    string player2_word = get_string("Player 2: ");

    // Get score of each player
    int player1_score = getScore(player1_word);
    int player2_score = getScore(player2_word);

    // Calculate winner
    if (player1_score > player2_score) {

        printf ("Player 1 wins!\n");
    } else if (player1_score < player2_score) {

        printf ("Player 2 wins!\n");
    } else {

        printf ("Tie!\n");
    }
}

int getScore (string word) {

    int score = 0;
    for (int i = 0; i < strlen(word); i++) {

        int ascii = toupper(word[i]);
        if (ascii >= 65 && ascii <= 90){

            score = score + values[ascii - 65];
        }
    }

    return score;
}
