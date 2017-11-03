#include <stdio.h>

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = 
    {{"Argentina",      54},  {"Bangladesh",        880},
     {"Brazil",         55},  {"Burma (Myanmar)",    95},
     {"China",          86},  {"Colombia",           57},
     {"Congo, DR of",  243},  {"Egypt",              20},
     {"Ethiopia",      251},  {"France",             33},
     {"Germany",        49},  {"India",              91},
     {"Indonesia",      62},  {"Iran",               98},
     {"Italy",          39},  {"Japan",              81},
     {"Mexico",         52},  {"Nigeria",           234},
     {"Pakistan",       92},  {"Phillipines",        63},
     {"Poland",         48},  {"Russia",              7},
     {"South Africa",   27},  {"South Korea",        82},
     {"Spain",          34},  {"Sudan",             249},
     {"Thailand",       66},  {"Turkey",             90},
     {"Ukraine",       380},  {"United Kingdom",     44},
     {"United States",   1},  {"Vietnam",            84}};

void print_code(int code);

int main(void) {
    // get input
    int input;
    printf("Enter an international dialing code: ");
    scanf(" %d", &input);
    // look up code
    print_code(input);
    return 0;
}

void print_code(int code) {
    int i;
    for (i = 0; i < 32; i++) {
        if (country_codes[i].code == code) {
            printf("%s\n", country_codes[i].country);
            break;
        }
    }
    if (i == 32)
        printf("country not found\n");
    return;
}
