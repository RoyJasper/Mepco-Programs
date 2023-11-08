#include <stdio.h>
#include <math.h>
int calculate(int n);
int main(void)
{
    printf("\n**************** F CONTROL PROBLEM **************\n\n");
    int length;
    printf("\n Enter no of times ");
    scanf("%d", &length);
    int answers[length];
    int i, input;
    printf("\n Enter the inputs \n");
    for (i = 0; i < length; ++i)
    {
        scanf("%d", &input);
        answers[i] =calculate(input);
    }
    printf("\n Outputs are: \n");
    for (i = 0; i < length; ++i)
    {
        printf("  %d  \n", answers[i]);
    }
    return 0;
}
int calculate(int n)
{
    int values = 0;
    if (n < 5)
        return values;
    int k = 1;
    while ((int)floor(pow(5, k + 1)) < n)
        ++k;
    int i;
    for (i = 1; i <= k; ++i)
    {
        values += floor((n / pow(5, i)));
    }
    return values;
}
