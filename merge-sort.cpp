// C++ program for Merge Sort
#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(vector<int> &array, int const left, int const mid, int const right) // O(n)
{

    int const subArrayOne = mid - left + 1; // 1
    int const subArrayTwo = right - mid;    // 1

    // Create temp arrays
    vector<int> leftArray;  // 1
    vector<int> rightArray; // 1

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)        // O(2(n + 1))
        leftArray.push_back(array[left + i]);     // 1 * n
    for (auto j = 0; j < subArrayTwo; j++)        // O(2(n + 1))
        rightArray.push_back(array[mid + 1 + j]); // 1 * n

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    { // 3*n + 3*n
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {                                                              // 1
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; // 1
            indexOfSubArrayOne++;                                      // 1
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; // 1
            indexOfSubArrayTwo++;                                       // 1
        }
        indexOfMergedArray++; // 1
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)                       //O(subArrayOne)
    {                                                              // 3*subArrayOne
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; // 1
        indexOfSubArrayOne++;                                      // 1
        indexOfMergedArray++;                                      // 1
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)                        //O(subArrayTwo)
    {                                                               // 3*subArrayTwo
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; // 1
        indexOfSubArrayTwo++;                                       // 1
        indexOfMergedArray++;                                       // 1
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int> &array, int const begin, int const end) //  T(n) => 2*T(n/2) + n =>  O(n logn)
{
    if (begin >= end) // 1
        return;       // 1

    int mid = begin + (end - begin) / 2; // 1
    mergeSort(array, begin, mid);        // O(n/2)
    mergeSort(array, mid + 1, end);      // O(n/2)
    merge(array, begin, mid, end);       // O(n)
}

// Driver code
// int main()
// {
//     srand(time(NULL));
//     int n = 20;

//     for (int i = 0; i < 20; i++)
//     {
//         clock_t start, end;
//         int arr[n];

//         for (int r = 0; r < n; r++)
//         {
//             arr[r] = rand() % n;
//         }

//         cout << "[MERGE SORT] Ordenando instancia de tamanho [" << n << "].\n";
//         start = clock();
//         mergeSort(arr, 0, n - 1);

//         end = clock();
//         cout << "[MERGE SORT] Finalizado.\n";

//         double runtime = (double)(end - start) / CLOCKS_PER_SEC;
//         printf("[MERGE SORT] %.10lfs\n\n", runtime);

//         n = n + (n * 2) / 3;
//     }

//     return 0;
// }

/**
 * Função de complexidade de radixSort
 * - Função Merge -> O(n)
 * - Função MergeSort -> O(n logn)
 * - Para o MergeSort todos os casos apresentarão a mesma complexidade
 * - dado que o algoritimo irá sempre dividir o vetor fornercido até obter
 * - únicos valores e irá juntar os valores comparando-os para ordená-los.
 * - Desse modo, a complexidade sempre será O(n logn).
 */