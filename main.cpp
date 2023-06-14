#include <iostream>
#include <random>
#include <algorithm>
#include "merge-sort.cpp"
#include "radix-sort.cpp"
#include "insertion-sort.cpp"
#include "calculations.cpp"

using namespace std;

void PrintVector(const vector<int> &arr)
{
    for (int i = 0; i < int(arr.size()); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintVectorDouble(const vector<double> &arr)
{
    for (int i = 0; i < int(arr.size()); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> CreateRandomArray(int n)
{
    vector<int> arr;
    random_device rd;                            // Gera uma semente aleatória
    mt19937 gen(time(NULL));                     // Mersenne Twister 19937 gerador de números aleatórios
    uniform_int_distribution<int> dist(1, 1000); // Faixa de valores aleatórios (1 a 100)

    for (int i = 0; i < n; i++)
    {
        int randomNum = dist(gen); // Gera um número aleatório usando a distribuição

        arr.push_back(randomNum); // Adiciona o número ao vetor
    }

    return arr;
}

int main()
{
    int n = 100;
    int op = 1;

    double *TPareado = new double[2];

    for (int i = 0; i < 10; i++)
    {
        vector<int> arrVector = CreateRandomArray(n);
        int size = arrVector.size();
        // int *arrDinamico = new int[size];
        // copy(vetor.begin(), vetor.end(), arrayEstatico);
        if(op == 1) {
            for (int j = 0; j < 3; j++)
            {

                vector<double> times1;
                vector<double> times2;

                for (int k = 0; k < 20; k++)
                {
                    clock_t start1, end1, start2, end2;
                    if (j == 0)
                    { // INSERTION+MERGE
                        start1 = clock();
                        insertionSort(arrVector, size);
                        end1 = clock();

                        start2 = clock();
                        mergeSort(arrVector, 0, n - 1);
                        end2 = clock();
                    }
                    else if (j == 1)
                    { // INSERTION+RADIX
                        start1 = clock();
                        insertionSort(arrVector, size);
                        end1 = clock();

                        start2 = clock();
                        RadixSort(arrVector);
                        end2 = clock();
                    }
                    else if (j == 2)
                    { // MERGE+RADIX
                        start1 = clock();
                        mergeSort(arrVector, 0, n - 1);
                        end1 = clock();

                        start2 = clock();
                        RadixSort(arrVector);
                        end2 = clock();
                    }

                    double runtime1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    double runtime2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
                    times1.push_back(runtime1);
                    times2.push_back(runtime2);
                }

                vector<double> times = SubtractVectors(times1, times2);
                double mean = CalcularMedia(times);
                double standardDeviation = CalcularDesvioPadrao(times);
                TPareado = CalcularTesteTPareado(standardDeviation, mean, times.size());

                if (j == 0)
                    cout << "\nINSERTION+MERGE ";
                else if (j == 1)
                    cout << "\nINSERTION+RADIX ";
                else if (j == 2)
                    cout << "\nMERGE+RADIX ";

                cout << "(" << n << ")" << endl;
                cout << "[" << setprecision(3) << TPareado[0] << ", ";
                cout << setprecision(3) << TPareado[1] << "]\n";
            }
        }else if(op == 2) {
            for (int j = 0; j < 3; j++)
            {
                vector<double> times1;

                for (int k = 0; k < 20; k++)
                {
                    clock_t start1, end1, start2, end2;
                    if (j == 0)
                    { // INSERTION
                        start1 = clock();
                        insertionSort(arrVector, size);
                        end1 = clock();
                    }
                    else if (j == 1)
                    { //RADIX
                        start1 = clock();
                        RadixSort(arrVector);
                        end1 = clock();
                    }
                    else if (j == 2)
                    { // MERGE
                        start1 = clock();
                        mergeSort(arrVector, 0, n - 1);
                        end1 = clock();
                    }

                    double runtime1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
                    times1.push_back(runtime1);
                }

                double mean = CalcularMedia(times1);
                double standardDeviation = CalcularDesvioPadrao(times1);
                TPareado = CalcularTesteTPareado(standardDeviation, mean, times1.size());

                if (j == 0)
                    cout << "\nINSERTION ";
                else if (j == 1)
                    cout << "\nRADIX ";
                else if (j == 2)
                    cout << "\nMERGE ";

                cout << "(" << n << ")" << endl;
                cout << "[" << setprecision(3) << TPareado[0] << ", ";
                cout << setprecision(3) << TPareado[1] << "]\n";
            }
        }
       
        
        n *= 2;
    }

    delete[] TPareado;

    return 0;
}