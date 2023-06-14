#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> SubtractVectors(const vector<double> &vec1, const vector<double> &vec2)
{
    vector<double> result;

    // Verifica se os vetores têm o mesmo tamanho
    if (vec1.size() != vec2.size())
    {
        cout << "Erro: Os vetores têm tamanhos diferentes!" << endl;
        return result;
    }

    for (size_t i = 0; i < vec1.size(); ++i)
        result.push_back(vec1[i] - vec2[i]);

    return result;
}

double CalcularMedia(const vector<double> &tempos)
{
    double soma = 0.0;
    for (const auto &tempo : tempos)
    {
        soma += tempo;
    }
    return soma / tempos.size();
}

double CalcularDesvioPadrao(const vector<double> &tempos)
{
    double media = CalcularMedia(tempos);
    double desvio_padrao = 0.0;
    for (const auto &tempo : tempos)
    {
        desvio_padrao += pow(tempo - media, 2);
    }

    return sqrt(desvio_padrao / (tempos.size() - 1));
}

double *CalcularTesteTPareado(double desvioPadrao, double media, int size) // LEMBRAR DE LIBERAR MEMÓRIA
{   
    // ordem dos valores de 0 a 11 => 19 ,99, 199, 399, 799, 1.599, 3.199, 6.399, 12.799, 25.599, 51.199
    vector<int> index = {19, 99, 199, 399, 799, 1599, 3199, 6399, 12799, 25599, 51199};
    vector<double> t = {2.093, 1.984, 1.972, 1.965, 1.960, 1.957, 1.955, 1.953, 1.952, 1.951, 1.950};
    int pos = -1;

    auto it = find(index.begin(), index.end(), (size - 1));
    if (it != index.end()) pos = distance(index.begin(), it);

    double *TPareado = new double[2];
    TPareado[0] = media - t[pos] * ((desvioPadrao) / sqrt(size));
    TPareado[1] = media + t[pos] * ((desvioPadrao) / sqrt(size));

    return TPareado;
}
