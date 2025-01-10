#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 256

typedef struct{
    char code[10];
    char* name;
}Book;

typedef struct{
    char name[MAX];
    int num_books;
    Book* books;

}Library;

int input_book(Book* B,FILE *in);
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);

int main()
{
	FILE *in,*out;
	Library Libr;
	int i;

    if ((in = fopen("input.txt","rt"))== NULL){
        printf("\nError");
        return 1;
    }
    if ((out = fopen("output.txt","wt"))== NULL){
        printf("\nError");
        return 1;
    }
	input_library(&Libr,in);
	fclose(in);

	output_library(&Libr,out);
	fclose(out);

    for(i=0;i<Libr.num_books; i++)   /* free the memory!!!*/
    {
        free(Libr.books[i].name);
    }
    free(Libr.books);

    return 0;
}

void input_library(Library *L,FILE *in){
    fscanf(in, "%s %d", L->name, &L->num_books);
    L->books = (Book*)malloc(sizeof(Book)*L->num_books);
    if ((L->books) == NULL) {
        exit(1);
    }
    for (int i=0;i<L->num_books;i++){
        if (input_book(&L->books[i],in)==0){
            for (int j=0;j<L->num_books;j++){
                free(L->books[j].name);
            }
            free(L->books);
            exit(1);
        }
    }
}

int input_book(Book* B,FILE *in){
    char* temp;
    if (fscanf(in,"%s",B->code) != 1){
    return 0;
    }
    if (fscanf(in,"%s",temp) != 1){
        return 0;
    }
    B->name = (char*) malloc(sizeof (char)* (strlen(temp)+1));
    if (B->name == NULL){
        return 0;
    }
    strcpy(B->name,temp);
    return 1;
}

void output_library(Library* L,FILE *out){
    fprintf(out,"%s\n",L->name);
    for (int i=0;i<L->num_books;i++){
        output_book(&L->books[i],out);
    }
}

void output_book(Book* B,FILE *out){
    fprintf(out,"%-8s %s\n",B->code,B->name);
}






