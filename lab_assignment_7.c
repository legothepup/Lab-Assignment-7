//Aidan Huggins
//Dr. Torosdagli
//COP3502
//Lab Assignment 7

#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) 
{
    int temp, i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) 
            {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Increment swaps for the swapped elements
                swaps[j]++;
                swaps[j+1]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) 
{
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        // Swap elements
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Increment swaps for the swapped elements
        swaps[i]++;
        swaps[minIndex]++;
    }
}

//Prints arrays
void printResults(int arr[], int n, int swaps[], char *sortName) 
{
    printf("%s:\n", sortName);
    for (int i = 0; i < n; i++) {
        printf("%d: %d swaps\n", arr[i], swaps[i]);
    }
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps += swaps[i];
    }
    printf("total # of swaps: %d\n\n", totalSwaps);
}

int main() 
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0}; // Assuming values range from 0 to 99
    int swaps2[100] = {0};

    // Perform Bubble Sort on array1
    bubbleSort(array1, n1, swaps1);
    printResults(array1, n1, swaps1, "Bubble Sort");

    // Perform Bubble Sort on array2
    bubbleSort(array2, n2, swaps2);
    printResults(array2, n2, swaps2, "Bubble Sort");

    // Perform Selection Sort on array1
    selectionSort(array1, n1, swaps1);
    printResults(array1, n1, swaps1, "Selection Sort");

    // Perform Selection Sort on array2
    selectionSort(array2, n2, swaps2);
    printResults(array2, n2, swaps2, "Selection Sort");

    return 0;
}
