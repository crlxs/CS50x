//https://cs50.harvard.edu/x/psets/1/credit/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_digits (long number);

int main (void) {

    long card_number;

    do {

        card_number = get_long("Number: ");
    } while (card_number <= 0);

    int cardnumber_digits = count_digits(card_number);

    if (cardnumber_digits == 13 || cardnumber_digits == 15 || cardnumber_digits == 16){

        long card_number2 = card_number;
        int even_digits_sum = 0;
        int odd_digits_sum = 0;
        int first_digit = 0;
        int second_digit = 0;

        for (int i = 0; i < cardnumber_digits; i++) {

            int digit = card_number2 % 10;

            if (i % 2 == 0){ // Even positions of the digits 4003600000000014

                even_digits_sum = even_digits_sum + digit;
            } else { // Odd positions of the digits

                if (digit >= 5) { // Same as if (digit * 2 > 10), or if ()

                    odd_digits_sum = odd_digits_sum + (digit * 2 % 10) + ((digit * 2 / 10) % 100); //Doubling the digit and adding its digits: digit = 6 -> 6 * 2 = 12 -> 1 + 2 = 3
                } else {

                    odd_digits_sum += digit * 2;
                }
            }

            card_number2 = (card_number2 - digit) / 10;
        }

        if ((odd_digits_sum + even_digits_sum) % 10 != 0) {

            printf("INVALID\n");
        } else {

            int first2_digits = card_number / (pow(10, (cardnumber_digits -2)));

            if ((first2_digits >= 51 && first2_digits <= 55) && cardnumber_digits == 16){

                printf("MASTERCARD\n");
            } else if ((first2_digits == 34 || first2_digits == 37) && cardnumber_digits == 15) {

                printf("AMEX\n");
            } else if ((first2_digits / 10 == 4) && (cardnumber_digits == 13 || cardnumber_digits == 16)) {

                printf("VISA\n");
            } else {

                printf("INVALID\n");
            }
        }

    } else {

        printf("INVALID\n");
    }
}


int count_digits (long number) {

    int digits = 0;

    do {
        number /= 10;
        digits++;
    } while (number != 0);

    return digits;
}
