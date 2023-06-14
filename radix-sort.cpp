#include <vector>
#include <time.h>

using namespace std;

int GetMax(const vector<int> &arr) // O (n)
{
    int max = arr[0];                         // 1
    for (int i = 1; i < int(arr.size()); i++) // 3 * (n)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void CountingSort(vector<int> &arr, int div) // O(q + n)
{
    const int size = int(arr.size()); // 1
    vector<int> output(size);         // 1
    vector<int> count(10, 0);         // q

    for (int i = 0; i < size; i++)    // 3 * (n)
        count[(arr[i] / div) % 10]++; // 2 * (n - 1)

    for (int i = 1; i < 10; i++)  // 3 * (q)
        count[i] += count[i - 1]; // 2 * (q - 1)

    for (int i = size - 1; i >= 0; i--) // 3 * (n)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i]; // 3 * (n)
        count[(arr[i] / div) % 10]--;                    // 2 * (n - 1)
    }

    for (int i = 0; i < size; i++) // 3 * (n)
        arr[i] = output[i];        // 1 * (n - 1)
}

void RadixSort(vector<int> &arr) // O(n) + k * O(q + n) => O(n) +  O(k *(q + n)) => O(k *(q + n))
{
    int max = GetMax(arr); // O(n)

    for (int div = 1; max / div > 0; div *= 10) // k
        CountingSort(arr, div);                 // O(q + n)
}

/**
 * Função de complexidade de radixSort
 * - Função GetMax(...) -> O(n)
 * - Função CountingSort -> O(q + n)
 * - Função radixSort -> O(n) + k * O(q + n) -> P * O(n + k) = O(k *(q + n))
 * - Onde n é o número de itens a classificar, k é o número de dígitos no número máximo,
 * - e q é o número de valores que cada dígito pode ter.
 * - Se ambos k e q são constantes, complexidade é O(n)
 * - melhor caso = pior caso = caso médio = O(K * (N + b))
 * - PIOR CASO
 * - Ocorre quando todos os elementos têm o mesmo número de dígitos, exceto um elemento
 * - que possui um número significativamente grande de dígitos. Se o número de dígitos no
 * - maior elemento for igual a n, o tempo de execução será O(n^2)
 * - MELHOR CASO
 * - Ocorre quando todos os elementos têm o mesmo número de dígitos. Se b for O(n)
 * - a complexidade de tempo é O(d * n).
 * - CASO MÉDIO
 * - ocorre quando os elementos do vetor de entrada estão distribuídos de forma aleatória.
 * - Nesse caso, o desempenho do algoritmo depende da distribuição dos valores e da
 * - quantidade de dígitos dos elementos. O(d * n) a constante multiplicativa pode variar
 * - dependendo da distribuição dos valores.
 */