#include <stdio.h>

int main () {

    char file_path[99];
    printf("Enter filename with absolute path -->");
    if (scanf("%99[^\n]", file_path) != 1) {
        printf("Error reading file path.\n");
        return 1; // Return an error code
    }

    FILE *file = fopen(file_path, "r");

    if (file==NULL){
        printf("\nError! I could not open the specified file %s\n",file_path);
    }

    int line_count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;
    }

    fclose(file);

    printf("The file %s contains %d lines.\n",file_path,line_count);
}