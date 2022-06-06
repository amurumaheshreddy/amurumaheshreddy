#include <stdio.h>
int main()
{
    int numbers[21];
    printf("Value 10 to first element\n");
    scanf(" %d" , &numbers[0]);

    printf("Value 35 to last element\n");
    scanf(" %d" , &numbers[20]);

    printf("Value 50 to middle element (part way through)\n");
    scanf(" %d" , &numbers[10]);
    printf("Value at first element\n");
    printf(" %d\n" , numbers[0]);

    printf("Value at last element\n");
    printf(" %d\n" , numbers[20]);

    printf("Value at middle element (part way through)\n");
    printf(" %d\n" , numbers[10]);
    return 0;
}
