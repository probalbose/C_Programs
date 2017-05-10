// Enter numbers 1-16 in any order
// Display numbers in 4x4 arrangement
// Print sums of the rows, columns, & diagonals

#include <stdio.h>

int main(void)
{
    int one, two, three, four, five, six, seven,
        eight, nine, ten, eleven, twelve, thirteen,
        fourteen, fifteen, sixteen;

    printf("Enter the numbers 1-16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &one, &two, &three, &four, &five, &six, &seven, &eight,
            &nine, &ten, &eleven, &twelve, &thirteen, &fourteen,
            &fifteen, &sixteen);
    
    printf("%d %d %d %d\n", one, two, three, four);
    printf("%d %d %d %d\n", five, six, seven, eight);
    printf("%d %d %d %d\n", nine, ten, eleven, twelve);
    printf("%d %d %d %d\n", thirteen, fourteen, fifteen, sixteen);

    printf("Sums of the rows: %d %d %d %d\n", one+two+three+four,
            five+six+seven+eight, nine+ten+eleven+twelve,
            thirteen+fourteen+fifteen+sixteen);
    printf("Sums of the columns: %d %d %d %d\n", one+five+nine+thirteen,
            two+six+ten+fourteen, three+seven+eleven+fifteen,
            four+eight+twelve+sixteen);
    printf("Sums of the diagonals: %d %d\n", one+six+eleven+sixteen,
            thirteen+ten+seven+four);

    return 0;
}
