#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int low, int high, int key);

int main()
{
    int i, n, key, arr[10];

    printf("Enter the maximum elements you want to store: ");
    scanf("%d", &n);

    printf("Enter the Elements (sorted): \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);

    if(index != -1)
    {
        printf("Element %d found at index %d.\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}

int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}
