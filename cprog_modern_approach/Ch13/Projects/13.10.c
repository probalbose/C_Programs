/* 
 * Take first & last name entered by the user & then display last name, comma, & first initial
 * this is unnecessarily complex, i'm sure...
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 99

void reverse_name(char *name);

int main(void) {
    char buf[BUFSIZE+1];

    printf("enter a first & last name: ");

    for (char *p = buf; p < buf+BUFSIZE; p++) {
        *p = getchar();
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    reverse_name(buf);
    printf("reversed name: %s\n", buf);

    return 0;
}

void reverse_name(char *name) {
    char new_str[strlen(name)], *p, *q;
    // seek to end of last name
    for (p = name + strlen(name) - 1; *p == ' ' || *p == '\0'; p--)
        ;
    // seek to beginning of last name
    for (; *(p-1) != ' '; p--)
        ;
    // copy it to new string
    for (int i = 0; *p && *p != ' '; i++, p++) {
        new_str[i] = *p;
    }
    // add comma and space
    strncat(new_str, ", ", BUFSIZE - strlen(new_str)); //practicing my safe coding...?
    // add first initial
    for (p = name; *p == ' '; p++)
        ;
    q = new_str + strlen(new_str);
    *q = *p;
    // add period
    *++q = '.';
    *++q = '\0';
    // copy the whole thing into the original string
    strcpy(name, new_str);
}
