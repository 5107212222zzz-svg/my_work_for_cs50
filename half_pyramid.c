#include<stdio.h>
int main(void)
{
    int n;

    printf("Please enter the hight of your pyramid\n ");

    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}