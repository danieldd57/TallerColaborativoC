#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int substringFound(char string[], char subString[], int startPosition){
    int counter = 0;
    for(int i = startPosition; i < strlen(string); i++){
        for(int j = 0; j < strlen(subString); j++){
            if(string[i + counter] == subString[j]){
                counter++;
                if(counter == strlen(subString)){
                    return i + 1;
                }
            }else{
                break;
            }
        }       
    }
    return 0;
}

char* fillChars(char string[], char cToFill, int orientation, int cQuantity){
    
    char* newString = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(newString, string);
    for(int i = 0; i < cQuantity && i < strlen(newString); i++){
        if(orientation == 0){
            newString[i] = cToFill;
        }else{
            newString[strlen(newString) - i - 1] = cToFill;
        }
    }

    return newString;
}

char* substringClassic(char string[], int start, int end){
    
    int length = end - start;
    if(length < 0){length *= -1;}
    length++;
    char* newString = malloc(sizeof(char) * (length + 1));
    if (newString == NULL) {
        printf("Error: No se pudo asignar memoria.");
        exit(1);
    }

    if(start < end){
        for(int i = start - 1, j = 0; i <= end - 1; i++, j++){
            newString[j] = string[i];
        }
    }else{
        for(int i = start - 1, j = 0; i >= end - 1; i--, j++){
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
    //
    int j;
    for(int i=1; i<strlen(input); i++){
        for(j=0; j<aux; j++){
            if(output[j] == input[i]){
                break; //for j
            }
        }
        if (j==aux) {
            output[aux] = input[i];
            aux++;
        }
    }
    output[aux] = '\0';
    return output;
}

char* replaceOccurrencesChar(char *input, char oldChar, char newChar){
    char *out = input;
    for(int i=0; i<strlen(input); i++){
        if(input[i] == oldChar){
            out[i] = newChar;
        }
    }
    return out;
}

int startWith(char *baseString, char *verifyString){
    if(strlen(verifyString) > strlen(baseString)){
        return 0;
    }else{
        for(int i=0; i<strlen(verifyString); i++){
            if(baseString[i] != verifyString[i]){
                return 0;
            }
        }
        return 1;
    }
}
int main(void) {
    int option = 0;
    char string [50];
    char stringVerify [50];
    char newChar;
    char oldChar;
    int startPosition; 
    int endPosition;

    while(option!=10){
        printf("\n-----MENU----\n1.Function #1 \n2.Function #2 \n3.Function #3 \n4.Function #4 \n5.Function #5 \n6.Function #6 \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Input the String\n");
                scanf(" %[^\n]", string);
                printf("Input the ocurrence\n");
                scanf(" %[^\n]", stringVerify);
                printf("Input the initial position\n");
                scanf("%d", &startPosition);
                int result1 = substringFound(string, stringVerify, startPosition);
                if(result1 != 0){
                    printf("Ocurrence found at %d position", result1);
                }else{
                    printf("Ocurrence not found");
                }
                break;
            case 2:
                int cQuantity;
                printf("Input the String\n");
                scanf(" %[^\n]", string);
                printf("Input the character to replace in\n");
                scanf(" %c", &newChar);
                printf("Input the orientation (0 = left, 1 = right)\n");
                scanf("%d", &startPosition);
                printf("Input the character quantity to fill in\n");
                scanf("%d", &cQuantity);

                char* result2 = fillChars(string, newChar, startPosition, cQuantity);
                printf("The new string is: %s", result2);
                free(result2);
                break;
            case 3:

                printf("Input the string\n");
                scanf(" %[^\n]", string);
                printf("Input the start index\n");
                scanf("%d", &startPosition);
                printf("Input the end index\n");
                scanf("%d", &endPosition);
                char* result3 = substringClassic(string, startPosition, endPosition);
                printf("The substring is: %s", result3);
                free(result3);
                break;
            case 4:
                printf("Input string\n");
                scanf(" %[^\n]", string);
                printf("Input character to replace\n");
                scanf(" %c", &oldChar);
                printf("Input new character\n");
                scanf(" %c", &newChar);
                printf("%s", replaceOccurrencesChar(string, oldChar, newChar));
                break;
            case 5:
                printf("Input base string\n");
                scanf(" %[^\n]", string);
                printf("Input string to verify\n");
                scanf(" %[^\n]", stringVerify);

                if(startWith(string, stringVerify)==0){
                    printf("The string to be verified (%s) NO exist in the start!",stringVerify);
                }else{
                    printf("The string to be verified (%s) Is it the start",stringVerify );
                }
                break;
            case 6:
                printf("Input string\n");
                scanf(" %[^\n]", string);
                printf("%s", removeCharactersRepeated(string));
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("\n-- Exit --\n");
                break;
            default:
                printf("\n-- Option invalid --\n");
                break;

        }

    }

    return 0;
}

