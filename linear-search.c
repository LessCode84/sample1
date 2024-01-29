#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, key, arr[10];

    printf("Enter the maximum elements you want to store: ");
    scanf("%d", &n);

    printf("Enter the Elements: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int found = 0; 
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            printf("Element %d found at index %d.\n", key, i);
            break; 
        }
    }

    if(!found)
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
