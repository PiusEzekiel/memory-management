#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int NUM_STUDENTS = 10;
int main() {

    char **emails = (char **)malloc(NUM_STUDENTS * sizeof(char *));
    if (emails == NULL) {
        printf("Error: Failed to allocate memory for emails.\n");
        return 1;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        char email[50];
        printf("Enter email for student %d: ", i + 1);
        scanf("%s", email);
        emails[i] = (char *)malloc((strlen(email) + 1) * sizeof(char));
        if (emails[i] == NULL) {
            printf("Error: Failed to allocate memory for email %d.\n", i + 1);
            
            for (int j = 0; j < i; j++) {
                free(emails[j]);
            }
            free(emails);
            return 1;
        }
        strcpy(emails[i], email);
    }

  
    emails = (char **)realloc(emails, 6 * sizeof(char *));
    if (emails == NULL) {
        printf("Error: Failed to reallocate memory for emails.\n");
        return 1;
    }

  printf("Reallocated memory for 6 emails.\n");
    for (int i = 0; i < 6; i++) {
        printf("Email %d: %s\n", i + 1, emails[i]);
    }

  
    for (int i = 0; i < 6; i++) {
        free(emails[i]);
    }
    free(emails);

    return 0;
}