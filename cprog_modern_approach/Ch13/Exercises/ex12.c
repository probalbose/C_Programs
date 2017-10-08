#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void get_extension(const char *file_name, char *extension);

int main(int argc, char *argv[]) {
    const char *file_name = argv[1];
    char file_ext[BUFSIZE] = {0};
    get_extension(file_name, file_ext);
    printf("file extension: %s\n", file_ext);
    return 0;
}

void get_extension(const char *file_name, char *extension) {
    while (*file_name++)
        if (*file_name == '.')
            strcpy(extension, file_name);
    strcat(extension, "");
}
