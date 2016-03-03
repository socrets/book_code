#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strrindex(char source[], char search_for[]);
char pattern[] = "ou";

int main()
{
    char line[MAXLINE];
    
    if ((get_line(line, MAXLINE)) > 0) {
	printf("%d", strrindex(line, pattern));
    }
}

int get_line(char s[], int lim) {
    int character, i;

    i = 0;
    while ((character = getchar()) != EOF && (lim--) > 0 && character != '\n') {
	s[i++] = character;
    }
    if (character == '\n') {
	s[i++] = character;
    }
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
	for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
	    ;
	}
	if (k > 0 && t[k] == '\0') {
	    return i;
	}
    }
    return -1;
}
