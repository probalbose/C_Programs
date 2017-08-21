/* write a program that evaluates an expression
 * the expression is evaluated from left to right
 * there is no operator precedence
 */

#include <stdio.h>

int main(void) {
    float input, result;
    char operator = ' ';

    printf("enter an expression: ");

    // get first term & operator
    scanf("%f%c", &result, &operator);

    while (operator != '\n') {
        // get next term
        scanf("%f", &input);

        // perform operation
        switch (operator) {
            case '+': result += input; break;
            case '-': result -= input; break;
            case '*': result *= input; break;
            case '/': result /= input; break;
            default: break;
        }

        // get next operator
        scanf("%c", &operator);
    }

    printf("value of expression: %f\n", result);

    return 0;
}
