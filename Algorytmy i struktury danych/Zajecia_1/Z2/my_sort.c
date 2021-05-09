#include "my_sort.h"

/*
 * Algorytmy i struktury danych - SPzut
 * Marcin Kierinkiewicz 26 april 2021
 */

void bubble_sort(int *arr, int arr_size)
{
    // ____ Variables init ____
    // j - (1) loop iterator
    // i - (2) loop iterator
    // p - algorithm stop flag
    int p = 0, i = 0, j = 0;

    // First loop (1)
    for (j = arr_size - 1; j >= 1; j--)
    {
        p = 1;

        // Second loop (2)
        for (i = 1; i <= j; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                // Solution without using temporary variable
                arr[i - 1] ^= arr[i];
                arr[i] ^= arr[i - 1];
                arr[i - 1] ^= arr[i];
                p = 0;
            }
        }
        if (p == 1)
        {
            break;
        }
    }
}

void insertion_sort(int *arr, int arr_size)
{
    // ____ Variables init ____
    // j - (1) loop iterator
    // i - (2) loop iterator
    // x - aux variable
    int j = 0, i = 0, x = 0;

    // First loop (1)
    for (j = arr_size - 1; j >= 0; j--)
    {
        x = arr[j];
        // Second loop (2)
        for (i = j + 1; i <= arr_size; i++)
        {
            if (x <= arr[i])
            {
                arr[i - 1] = x;
                break;
            }
            else
            {
                arr[i - 1] = arr[i];
            }
        }
    }
}

void selection_sort(int *arr, int arr_size)
{
    // ____ Variables declaration ____
    // j - (1) loop iterator
    // i - (2) loop iterator
    // pmin - minimum value index
    // temp - temporary variable to exchange two values
    int j = 0, i = 0, pmin = 0;
    int temp = 0;

    // First loop (1)
    for (j = 0; j < arr_size; j++)
    {
        pmin = j;

        for (i = j + 1; i < arr_size; i++)
        {
            if (arr[i] < arr[pmin])
            {
                pmin = i;
            }
        }
        // solution with auxiliary variable
        temp = arr[pmin];
        arr[pmin] = arr[j];
        arr[j] = temp;
    }
}