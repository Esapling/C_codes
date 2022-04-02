#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pov(int,int); // just pow function but return type is int
int how_many_digit(int); //to see how many digits an input has

void isArmstrong(int n, int number)
{
    int arr[n];
    arr[0]=0; // to prevent any unwanted results
    int sum= 0;
    for (int i = 1; i <=n; i++)
    {
        arr[i] = ( number / pov(10,i-1)) % 10 ;
        sum = sum + pov(arr[i],3);
    /*  printf("%d. digit = %d\n",i,arr[i]); if you want to debug it to see whats going on
        printf("sum = %d \n",sum);  just open */
    }
    if (sum == number) {
        printf("%d is an armstrong number .\n",number);
    }
    else{
        printf("%d is not an armstrong number\n",number);
    }


}

int main()
{
    int x;
    printf("Enter any number to see wheter it is an armstrong number or not:\n");
    scanf("%d",&x);
    int digit_num = how_many_digit(x);
    isArmstrong(digit_num,x);
    return 0;
}

int how_many_digit(int n)
{
    int result = n;
    int i;
    for ( i = 1; i <= n; i++) {
        result = n / pov(10,i-1); // *i-1 ,be careful we are taking the power of ten
        if (abs(result)< 10) {
            break;
        }
    }
    return i;
}

int pov(int number, int power)
{
    int result = 1;
    for (int i = 1; i <= power; i++) {
        result = number *result;
    }
    return result;
}
