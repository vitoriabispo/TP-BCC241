#include <iostream>
#include <vector>

using namespace std;

// insertionSort
void swap(vector<int> &vector, int i, int j)
{ // 6
    if (i != j)
    {                          // 1
        int aux;               // 1
        aux = vector[i];       // 1
        vector[i] = vector[j]; // 1
        vector[j] = aux;       // 1
    }
}

void insertionSort(vector<int> &vector, int size)
{
    for (int i = 0; i < size; i++)
    {              // 3 * (size+1)
        int j = i; // 1 * size
        while (j > 0 && vector[j - 1] > vector[j])
        {                           // 2 * ti+1 p/ i
            swap(vector, j, j - 1); // 5  * ti
            j -= 1;                 // 1 * ti
        }
    }
}

/* Função de complexidade - InsertionSort
 *   - Função swap() -> T(n) = 6
 *   - Função insertionSort() -> T(n) = 6n + 3 + 8(0 + ... + n-1)*ti !!! como represento isso????????
 *
 * PIOR CASO -> T(n) = 4n^2 - 6n + 11
 *  - Ocorre quando o vetor fornecido está na ordem decrescente, tornando
 *    necessário percorrer e ordenar todo o vetor. Nesse caso, o é o maior
 *    valor possível, ti = i - 1, de forma que variam de 0 até i-1.
 *
 * MELHOR CASO -> T(n) = 6n + 3
 *  - Ocorre quando o vetor já está ordenado. Dessa forma, o único trabalho
 *    realizado é percorrer o vetor uma única vez e a estrutura de repetição
 *    interna (while) não será executada. Por isso, o ti = 0.
 *
 * CASO MÉDIO -> T(n) = 2n^2 + 7
 *  - Ocorre quando os valores estão distribuídos de forma aleatória, uma vez
 *    que são assumidas possibilidades iguais para a distribuição dos valores.
 *    Para representar essa possibilidade, realiza-se uma média para saber quantas
 *    vezes a estrutura de repetição interna é executada. Nesse caso, o ti = (i-1)/2.
 *
 */