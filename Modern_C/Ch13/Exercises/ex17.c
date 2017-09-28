#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

bool test_extension(const char *file_name, const char *extension);

int main(int argc, char *argv[]) {
    char file_name[BUFSIZE] = {0};
    char extension[BUFSIZE] = {0};

    strcpy(file_name, argv[1]);
    strcpy(extension, argv[2]);

    for (int i = 0; i < strlen(file_name); i++)
        file_name[i] = toupper(file_name[i]);
    for (int i = 0; i < strlen(extension); i++)
        extension[i] = toupper(extension[i]);

    bool result = test_extension(file_name, extension);
    if (result == true)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

bool test_extension(const char *file_name, const char *extension) {
    while (*file_name++) {
        if (*file_name == '.')
            if ((strcmp(++file_name, extension)) == 0)
                return true;
    }
    return false;
}
