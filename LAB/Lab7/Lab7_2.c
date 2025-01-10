#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int marks[4];
    float avg;
} student;

student* Create_Class(int size);
void Avg_Mark(student* s);
void Print_One(student* s);
void free_class(student* arr, int size);

int main() {
    int size, i;
    student *arr;

    printf("\nEnter the number of students: ");
    scanf("%d", &size);
    getchar(); // Consume the newline character left by scanf

    arr = Create_Class(size);

    for (i = 0; i < size; i++) {
        if (arr[i].avg >= 85) {
            Print_One(&arr[i]);
        }
    }

    free_class(arr, size);

    return 0;
}

student* Create_Class(int size) {
    student *arr = (student*)malloc(size * sizeof(student));
    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    char max[50];
    for (int i = 0; i < size; i++) {
        printf("\nEnter your name: ");
        fgets(max, sizeof(max), stdin);
        max[strcspn(max, "\n")] = '\0'; // Remove the newline character

        arr[i].name = (char*)malloc(strlen(max) + 1);
        if (arr[i].name == NULL) {
            printf("\nNot enough memory\n");
            for (int j = 0; j < i; j++) {
                free(arr[j].name);
            }
            free(arr);
            exit(1);
        }
        strcpy(arr[i].name, max);

        printf("\nEnter your marks: ");
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i].marks[j]);
        }
        getchar(); // Consume the newline character left by scanf

        Avg_Mark(&arr[i]);
    }

    return arr;
}

void Avg_Mark(student* s) {
    s->avg = (s->marks[0] + s->marks[1] + s->marks[2] + s->marks[3]) / 4.0;
}

void Print_One(student* s) {
    printf("\nThe average of %s is %.1f", s->name, s->avg);
}

void free_class(student* arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i].name);
    }
    free(arr);
}