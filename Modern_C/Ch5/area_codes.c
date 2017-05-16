#include <stdio.h>

int main(void) {
    int area_code;
    
    printf("Enter an area code: ");
    scanf("%3d", &area_code);

    switch (area_code) {
        default:        printf("Area code not recognized"); break;
        case 229:       printf("Albany"); break;
        case 404:
        case 470:
        case 770:       printf("Atlanta"); break;
        case 706:
        case 762:       printf("Columbus"); break;
        case 478:       printf("Macon"); break;
        case 912:       printf("Savannah"); break;
    }
    return 0;
}
