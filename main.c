#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

int substringFound(char string[], char subString[], int startPosition) {
    int counter = 0;
    for (int i = startPosition; i < strlen(string); i++) {
        for (int j = 0; j < strlen(subString); j++) {
            if (string[i + counter] == subString[j]) {
                counter++;
                if (counter == strlen(subString)) {
                    return i + 1;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}

char* fillChars(char string[], char cToFill, int orientation, int cQuantity) {
    char* newString = malloc(sizeof(char) * (strlen(string) + cQuantity + 1));
    strcpy(newString, string);
    if (orientation == 0) {
        for (int i = strlen(string); i < strlen(string) + cQuantity; i++) {
            newString[i] = cToFill;
        }
        newString[strlen(string) + cQuantity] = '\0';
    } else {
        for (int i = 0; i < cQuantity; i++) {
            newString[strlen(string) + i] = cToFill;
        }
        newString[strlen(string) + cQuantity] = '\0';
    }
    return newString;
}

char* substringClassic(char string[], int start, int end) {
    int length = abs(end - start) + 1;
    char* newString = malloc(sizeof(char) * (length + 1));
    if (newString == NULL) {
        printf("Error: No se pudo asignar memoria.");
        exit(1);
    }

    if (start < end) {
        for (int i = start - 1, j = 0; i <= end - 1; i++, j++) {
            newString[j] = string[i];
        }
    } else {
        for (int i = start - 1, j = 0; i >= end - 1; i--, j++) {
            newString[j] = string[i];
        }
    }
    newString[length] = '\0';
    return newString;
}

char* removeCharactersRepeated(char *input) {
    char *output = (char *)malloc(strlen(input) + 1);
    int aux = 1;
    output[0] = input[0];
    for (int i = 1; i < strlen(input); i++) {
        int j;
        for (j = 0; j < aux; j++) {
            if (output[j] == input[i]) {
                break;
            }
        }
        if (j == aux) {
            output[aux++] = input[i];
        }
    }
    output[aux] = '\0';
    return output;
}

char* replaceOccurrencesChar(char *input, char oldChar, char newChar) {
    char *out = malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(out, input);
    for (int i = 0; i < strlen(out); i++) {
        if (out[i] == oldChar) {
            out[i] = newChar;
        }
    }
    return out;
}

int startWith(char *baseString, char *verifyString) {
    int verifyLength = strlen(verifyString);
    if (strlen(baseString) < verifyLength) {
        return 0;
    }
    for (int i = 0; i < verifyLength; i++) {
        if (baseString[i] != verifyString[i]) {
            return 0;
        }
    }
    return 1;
}

void stringDifference(char first[], char second[], char result[]) {
    int resultIndex = 0;

    for (int i = 0; i < strlen(first); i++) {
        if (!strchr(second, first[i])) {
            result[resultIndex++] = first[i];
        }
    }
    result[resultIndex] = '\0';
}

void insertString(char base[], char stringToInsert[], int position) {
    int baseLength = strlen(base);
    int insertLength = strlen(stringToInsert);
    if (position < 0 || position > baseLength) {
        return;
    }
    for (int i = baseLength; i >= position; i--) {
        base[i + insertLength] = base[i];
    }
    for (int i = 0; i < insertLength; i++) {
        base[position + i] = stringToInsert[i];
    }
}

int compareCharacters(const void *a, const void *b) {
    char charA = tolower(*(const char *)a);
    char charB = tolower(*(const char *)b);
    return (charA > charB) - (charA < charB);
}

void sortString(char string[]) {
    int length = strlen(string);
    qsort(string, length, sizeof(char), compareCharacters);
}

int main(void) {
    int option;
    char string[MAX_LENGTH];
    char stringVerify[MAX_LENGTH];
    char newChar, oldChar;
    int startPosition, endPosition;

    do {
        printf("\nMenu:\n");
        printf("1. Find the first occurrence\n");
        printf("2. Fill with characters to the left or right\n");
        printf("3. Return a substring depending on the initial and final positions\n");
        printf("4. Replace all occurrences of a character with another\n");
        printf("5. Validate if a string starts with another\n");
        printf("6. String without repeated characters\n");
        printf("7. Calculate difference between two strings\n");
        printf("8. Insert a string into another\n");
        printf("9. Sort a string ignoring case\n");
        printf("10. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character after reading the option

        switch (option) {
            case 1:
                printf("Input the String: ");
                scanf(" %[^\n]", string);
                printf("Input the occurrence: ");
                scanf(" %[^\n]", stringVerify);
                printf("Input the initial position: ");
                scanf("%d", &startPosition);
                int result1 = substringFound(string, stringVerify, startPosition);
                if (result1 != 0) {
                    printf("Occurrence found at %d position\n", result1);
                } else {
                    printf("Occurrence not found\n");
                }
                break;
            case 2:
                printf("Input the String: ");
                scanf(" %[^\n]", string);
                printf("Input the character to fill in: ");
                scanf(" %c", &newChar);
                printf("Input the orientation (0 = left, 1 = right): ");
                scanf("%d", &startPosition);
                int cQuantity;
                printf("Input the character quantity to fill in: ");
                scanf("%d", &cQuantity);

                char* result2 = fillChars(string, newChar, startPosition, cQuantity);
                printf("The new string is: %s\n", result2);
                free(result2);
                break;
            case 3:
                printf("Input the string: ");
                scanf(" %[^\n]", string);
                printf("Input the start index: ");
                scanf("%d", &startPosition);
                printf("Input the end index: ");
                scanf("%d", &endPosition);
                char* result3 = substringClassic(string, startPosition, endPosition);
                printf("The substring is: %s\n", result3);
                free(result3);
                break;
            case 4:
                printf("Input string: ");
                scanf(" %[^\n]", string);
                printf("Input character to replace: ");
                scanf(" %c", &oldChar);
                printf("Input new character: ");
                scanf(" %c", &newChar);
                printf("%s\n", replaceOccurrencesChar(string, oldChar, newChar));
                break;
            case 5:
                printf("Input base string: ");
                scanf(" %[^\n]", string);
                printf("Input string to verify: ");
                scanf(" %[^\n]", stringVerify);

                if (startWith(string, stringVerify) == 0) {
                    printf("The string to be verified (%s) does not exist at the start!\n", stringVerify);
                } else {
                    printf("The string to be verified (%s) is at the start.\n", stringVerify);
                }
                break;
            case 6:
                printf("Input string: ");
                scanf(" %[^\n]", string);
                printf("%s\n", removeCharactersRepeated(string));
                break;
            case 7:
                printf("Enter the first string: ");
                scanf(" %[^\n]", string);
                printf("Enter the second string: ");
                scanf(" %[^\n]", stringVerify);
                stringDifference(string, stringVerify, string);
                printf("The difference between the strings is: %s\n", string);
                break;
            case 8:
                printf("Enter the base string: ");
                scanf(" %[^\n]", string);
                printf("Enter the string to insert: ");
                scanf(" %[^\n]", stringVerify);
                printf("Enter the insertion position (0-%d): ", strlen(string));
                scanf("%d", &startPosition);
                getchar();
                insertString(string, stringVerify, startPosition);
                printf("The resulting string is: %s\n", string);
                break;
            case 9:
                printf("Enter a string: ");
                scanf(" %[^\n]", string);
                sortString(string);
                printf("The sorted string is: %s\n", string);
                break;
            case 10:
                printf("\n-- Exit --\n");
                break;
            default:
                printf("\n-- Invalid option. Please select again. --\n");
                break;

        }

    } while (option != 10);

    return 0;
}
