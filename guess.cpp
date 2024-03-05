#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

void printHigherLower(int guess, int secretNumber) {
    if (guess < secretNumber) {
        printf("Higher! ");
    } else {
        printf("Lower! ");
    }
}

void playSound(const char *soundEffect) {
   
    printf("%s\n", soundEffect);
    usleep(500000); 
}

int main() {
    int secretNumber, guess, attempts, maxAttempts;
    int rangeStart, rangeEnd, difficulty;
    int score = 0, highScore = 0;
    char playAgain;
    srand(time(NULL)); 

    do {
        printf("\nWelcome to Guess the Number!\n");
        printf("Select difficulty level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        printf("Enter your choice: ");
        scanf("%d", &difficulty);

        switch (difficulty) {
            case 1:
                rangeStart = 1;
                rangeEnd = 50;
                maxAttempts = 10;
                break;
            case 2:
                rangeStart = 1;
                rangeEnd = 100;
                maxAttempts = 7;
                break;
            case 3:
                rangeStart = 1;
                rangeEnd = 1000;
                maxAttempts = 5;
                break;
            default:
                printf("Invalid choice! Defaulting to Easy level.\n");
                rangeStart = 1;
                rangeEnd = 50;
                maxAttempts = 10;
                break;
        }

        secretNumber = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
        printf("I've picked a number between %d and %d. Can you guess what it is?\n", rangeStart, rangeEnd);

        attempts = 0;

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess < secretNumber) {
                printHigherLower(guess, secretNumber);
            } else if (guess > secretNumber) {
                printHigherLower(guess, secretNumber);
            } else {
                printf("Congratulations! You guessed the number %d in %d attempts.\n", secretNumber, attempts);
                playSound("Correct guess!");
                score += maxAttempts - attempts + 1;
                break;
            }

            if (attempts == maxAttempts) {
                printf("Sorry, you've run out of attempts. The correct number was %d.\n", secretNumber);
                playSound("Game over!");
                break;
            }

        } while (attempts < maxAttempts);

        if (score > highScore) {
            highScore = score;
            printf("New High Score: %d\n", highScore);
        }

        printf("Your Score: %d\n", score);

        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

        score = 0;

    } while (playAgain == 'Y' || playAgain == 'y');

    printf("Thanks for playing!\n");

    return 0;
}
