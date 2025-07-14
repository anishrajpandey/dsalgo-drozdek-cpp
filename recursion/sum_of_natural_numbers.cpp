#include <iostream>

int sum(int n)
{
    if (n == 0)
        return 0;

    return n + sum(n - 1);
}

int main()
{
    int num;
    printf("enter n");
    scanf("%d", &num);
    int result = sum(num);
    printf("%d", result);
}