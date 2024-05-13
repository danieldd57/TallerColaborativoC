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
    char* newString = malloc(sizeof(char) * (strlen(string) + 1));

    if(start < end){
        for(int i = start - 1, j = 0; i < end; i++, j++){
            newString[j] = string[i];
        }
    }else{
        for(int i = start - 1, j = 0; i >= end - 1; i--, j++){
            newString[j] = string[i];
        }
    }
    return newString;
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
        printf("\n-----MENU----\n1.Function #1 \n2.Function #2 \n3.Function #3 \n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the String: \n");
                scanf("%s", string);
                printf("\nEnter the ocurrence: \n");
                scanf("%s", stringVerify);
                printf("\nEnter the initial position: \n");
                scanf("%d", &startPosition);
                int result1 = substringFound(string, stringVerify, startPosition);
                if(result1 != 0){
                    printf("\nOcurrence found at %d position", result1);
                }else{
                    printf("\nOcurrence not found");
                }
                break;
            case 2:
                int cQuantity;
                printf("\nEnter the String: \n");
                scanf("%s", string);
                printf("\nEnter the character to replace in: \n");
                scanf(" %c", &newChar);
                printf("\nEnter the orientation (0 = left, 1 = right): \n");
                scanf("%d", &startPosition);
                printf("\nEnter the character quantity to fill in: \n");
                scanf("%d", &cQuantity);

                char* result2 = fillChars(string, newChar, startPosition, cQuantity);
                printf("\nThe new string is: %s\n", result2);
                free(result2);
                break;
            case 3:

                printf("\nEnter the string:\n");
                scanf("%s", string);
                printf("\nEnter the start index:\n");
                scanf("%d", &startPosition);
                printf("\nEnter the end index:\n");
                scanf("%d", &endPosition);
                char* result3 = substringClassic(string, startPosition, endPosition);
                printf("\nThe substring is: %s\n", result3);
                free(result3);
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
        }
                printf("\n-- exit --\n");
    }

    return 0;
}

