#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, temp, j, arr[10];

    printf("Enter the maximum elements you want to store: ");
    scanf("%d", &n);

    printf("Enter the Elements: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n-1; i++)
    {
        int min_index = i;
        printf("Enter", i,"\n");

        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    printf("The array sorted in ascending order is: \n");
    for(i=0; i<n; i++)
        printf("%d\t", arr[i]);

    return 0;    
}
