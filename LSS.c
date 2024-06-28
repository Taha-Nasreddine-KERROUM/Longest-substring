#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MADMAX 100

void shorty ( char *s, char *c ) {
    int error = 0, i = 0, x = 0;
    char *temp = ( char* ) malloc (MADMAX), *p = s;
    if ( temp == NULL ) {
        puts(" temp's memory allocation failed");
        exit(EXIT_FAILURE);
    }
    while(*p) {
        if ( *p == ' ' ) *temp = '\0';
        while ( *p == ' ' ) ++p;
        while ( *p && (*p != ' ' ) ) *(temp + i++) = *p++;
        if ( strlen(c) < strlen(temp) )
            strcpy(c, temp);
        i = 0;
    }
    free(temp);
    temp = NULL;
}

int main()
{
    char *s = ( char* ) malloc (MADMAX), *c = ( char* ) malloc (MADMAX);
    if ( (c == NULL) || (s == NULL) ) {
        puts(" c or s's memory allocation failed");
        exit(EXIT_FAILURE);
    }
    printf(" enter a string: ");
    gets(s);
    shorty(s, c);
    s = ( char* ) realloc (s, strlen(s));
    c = ( char* ) realloc (c, strlen(c));
    if ( (c == NULL) || (s == NULL) ) {
        puts(" c or s's memory re-allocation failed");
        exit(EXIT_FAILURE);
    }
    printf(" the longest substring is: %s", c);
    free(c);
    free(s);
    s = NULL;
    c = NULL;
    return 0;
}
