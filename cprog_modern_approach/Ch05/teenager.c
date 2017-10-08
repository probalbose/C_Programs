#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool teenager;
    int age;

    printf("Enter an age: ");
    scanf("%d", &age);
    teenager = (age >= 13 && age <= 19) ? true : false;
    printf("teenager: %d ", teenager);
    printf("%s\n", teenager == 0 ? "false" : "true");
    return 0;
}
