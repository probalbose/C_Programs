// formats product information entered by the user.

#include <stdio.h>

int main(void)
{
    int item_no, month, day, year;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit Price\t\tPurchase Date\n");
    printf("%d\t\t%7.2f\t\t\t%d/%d/%d\n", item_no, price, month, day, year);

    return 0;
    
}
