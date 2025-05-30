// https://cs50.harvard.edu/x/psets/1/mario/more/

#include <stdio.h>
#include <cs50.h>

void print_spaces(int spaces);
void print_bricks(int spaces);

const char brick = '#';

int main (void) {

    int height;

    do {

        height = get_int("Height: ");
    } while(height <= 0 || height > 8);

    for (int i = 1; i <= height; i++) {

        int spaces = height - i;
        int bricks = i;

        if (i < height) {

            print_spaces(spaces);
            print_bricks(bricks);
        } else {

            print_bricks(bricks);
        }

        printf("\n");
    }
}

void print_spaces (int spaces) {

    for (int i = 1; i <= spaces; i++) {
        printf(" ");
    }

}

void print_bricks (int bricks) {

    for (int i = 1; i <= bricks; i++) { //Takes care of the bricks on the left side

        printf("%c", brick);

        if (i == bricks) {

            printf ("  ");

            for (int j = 1; j <= bricks; j++){

                printf("%c", brick);
            }
        }
    }
}
