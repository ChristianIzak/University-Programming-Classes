#include <stdio.h>

int main(void) {
    char dictionary[5][20] = {"Tesla", "Edison", "Faraday", "Maxwell", "Ohm"};
    char name[20];

    printf("Enter a name: ");
    scanf("%s", name);

    for(int i = 0; i < 5; i++) {
        int matchFound = 1;
        for(int j = 0; j < 20; j++) {
            if(dictionary[i][j] == '\0') { break; }

            if(dictionary[i][j] != name[j]) {
                matchFound = 0;
            }
        }
        if(matchFound) {
            printf("Access Granted!\n");
            break;
        } else if(i == 4 && !matchFound) {
            printf("Access Denied.\n");
        }
    }
}