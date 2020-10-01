#include <stdio.h>
int main()
{
    // int n;
    // printf("Enter value of n : ");
    // scanf("%d", &n);
    // printf("Enter n values in the array : ");
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d ", &arr[i]);
    // }
    int arr[8] = {12, 10, 0, 18, 11, 99, 55, 4};
    int n = 8;
    int i, j, position, swap;
    for (i = 0; i < (n - 1); i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i)
        {
            swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}