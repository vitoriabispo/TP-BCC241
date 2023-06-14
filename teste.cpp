#include <iostream>
#include "calculations.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> values1 = {5.4, 16.6, 0.6, 1.4, 0.6, 7.3};
    vector<double> values2 = {19.1, 3.5, 3.4, 2.5, 3.6, 1.7};

    vector<double> values = SubtractVectors(values1, values2);
    double mean = CalcularMedia(values);
    double standardDeviation = CalcularDesvioPadrao(values);
    double * result = new double[2];
    result = CalcularTesteTPareado(standardDeviation, mean, values.size());
    
    cout << setprecision(3) << standardDeviation << endl;
    cout << setprecision(3) << mean << endl;

    cout << setprecision(3) << result[0] << "\n";
    cout << setprecision(3) << result[1] << "\n";

    delete[] result;

    return 0;
}