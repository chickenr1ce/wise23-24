#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareFloats(const void *a, const void *b) {
    float float_a = *((float *)a);
    float float_b = *((float *)b);

    if (float_a < float_b) return -1;
    if (float_a > float_b) return 1;
    return 0;
}

int main(){
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


    char output_file_path[99 + 12];
    snprintf(output_file_path, sizeof(output_file_path), "%s.sorted.txt", file_path);
    FILE *output_file = fopen(output_file_path, "w");


    char buffer[256];
    float numbers[100];
    int counter = 0;

    while (fgets(buffer,sizeof(buffer), file) != NULL)      //read line, store in buffer,
    {                                                       // until fgets returns null, doesnt read a line
        float current_number = atof(buffer);      //convert string to float
        printf("\nNumber #%d: %f",counter,current_number);
        numbers[counter++] = current_number;
    }

    fclose(file);

    qsort(numbers, counter, sizeof(float), compareFloats);

    for (int i = 0; i < counter; i++)
    {
        fprintf(output_file, "%f\n",numbers[i]);
    }

    fclose(output_file);
    
}
