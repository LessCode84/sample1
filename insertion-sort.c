#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, key, n, arr[10];

    printf("Enter the maximum elements you want to store: ");
    scanf("%d", &n);

    printf("Enter the Elements: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    printf("The array sorted in ascending order is: \n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);

    return 0;
}
