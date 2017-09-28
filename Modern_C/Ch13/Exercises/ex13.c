#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void build_index_url(const char *domain, char *index_url);

int main(int argc, char *argv[]) {
    const char *domain = argv[1];
    char index_url[BUFSIZE] = {0};
    build_index_url(domain, index_url);
    printf("index url: %s\n", index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}
