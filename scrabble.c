#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1001

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);
int check_number(char *input);

int main(void)
{
    // Get input words from both players
    char word1[MAX_LENGTH], word2[MAX_LENGTH];

    while (1)
    {
        printf("Player 1: ");
        scanf("%1000s", word1);
        {
            if (check_number(word1))
            {
                break;
            }
        }
    }

    while (1)
    {
        printf("Player 2: ");
        scanf("%1000s", word2);
            if (check_number(word2))
            {
                break;
            }
    }

    // Store score for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Evaluate winner and print
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(const char *word)
{
    // Initialize score
    int score = 0;

    // Iterate through word to check individual characters
    for (int letter = 0; letter < strlen(word); letter++)
    {
        // Evaluate character for points
        switch (toupper(word[letter])) // Ignore lowercase letters
        {
            case 65:
            case 69:
            case 73:
            case 76:
            case 78:
            case 79:
            case 82:
            case 83:
            case 84:
            case 85:
                score++;
                break;
            case 68:
            case 71:
                score += 2;
                break;
            case 66:
            case 67:
            case 77:
            case 80:
                score += 3;
                break;
            case 70:
            case 86:
            case 87:
            case 89:
                score += 4;
                break;
            case 75:
                score += 5;
                break;
            case 81:
            case 90:
                score += 10;
                break;
            default:
                break;
        }
    }

    // Return total word score
    return score;
}

int check_number(char *input) {
    if (*input == '\0')
    {
        return 0; // If the string is empty, it's not accepted
    }

    // Check each character in the remaining string
    while (*input != '\0') {
        if (isdigit(*input))
        {
            return 0; // If a character is a digit, it's not an accepted
        }
        input++;
    }

    return 1; // All characters are letters, so it's accepted
}
