#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void replaceSubstring(char *str, char *substr);//declarer function

int main(){/*main fuction that ask for 2 strings from the user and call the fuction.*/
    int len;
    char str[101],substr[101];
    while (1){

        printf("Enter text: ");
        fgets(str,100,stdin);//get string from user
        len = strlen(str);//remove "enter" from string end
        if(str[len-1] == '\n')
            str[len-1]='\0';
            if (strlen(str) == '\0')//if string is empty
            break;
        
        printf("Enter substring: ");
        fgets(substr,101,stdin);//get string from user
        len = strlen(substr);
        if(substr[len-1] == '\n')
           substr[len-1]='\0';
           if (strlen(substr) == '\0')//if string is empty
         
          break;

        replaceSubstring(str,substr);//call for the function and print the updated string 
        printf("%s\n\n", str);
    }
    printf("Finish");
    return 0;
}

void replaceSubstring(char *str, char*substr){// function that change to uppercase letters all the returns of substring inside the string.
    char *pt;// Pointer to hold the location of the substring within the main string
    int i,substrlen = strlen(substr);

    while (pt != NULL){// Loop to find and replace all occurrences of the substring
         pt = strstr(str, substr);
        if (pt != NULL) {
            for (i = 0; i < substrlen; i++)// Convert each character of the found substring to uppercase
            {
                if ('a' <= pt[i] && pt[i] <= 'z')
                {
                    pt[i] = (pt[i] - 'a') + 'A';
                }
            }
            str = pt;
        }
        str++;
    }

}