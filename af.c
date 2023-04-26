// #include <stdio.h>
// void change(int *x, int y)
// {
//     *x = *x + 11;
//     y = y * 10;
//     return;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("%d %d\n", a, b);
//     change(&a, b);
//     printf("%d %d\n", a, b);
    
//     return 0;
// }

#include <stdio.h>
void func(int B[], int n);
int main()
{
    int A[5] = {10, 20, 30, 40, 50};
    int i;
    for (i = 4; i >= 0; i--)
    {
        printf("%d ",A[i]);
    }
    func(A, 5);
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
void func(int B[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    B[i] = (B[i] + i) * (i + 1);
   return;
}   