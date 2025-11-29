#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

int main() {
    // Test z liczbami ca³kowitymi (int)
    vector<int> intArray = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    
    cout << "Tablica int przed sortowaniem:" << endl;
    for (const auto& num : intArray) {
        cout << num << " ";
    }
    cout << endl;

    MergeSort<int> intSorter(intArray);
    intSorter.sort();
    
    cout << "Tablica int po sortowaniu:" << endl;
    intSorter.display();
    cout << endl;

    // Test z liczbami zmiennoprzecinkowymi (double)
    vector<double> doubleArray = {64.5, 34.2, 25.1, 12.7, 22.8, 11.9, 90.3, 5.6, 77.4, 30.0};
    
    cout << "Tablica double przed sortowaniem:" << endl;
    for (const auto& num : doubleArray) {
        cout << num << " ";
    }
    cout << endl;

    MergeSort<double> doubleSorter(doubleArray);
    doubleSorter.sort();
    
    cout << "Tablica double po sortowaniu:" << endl;
    doubleSorter.display();
    cout << endl;

    // Dodatkowe testy z innymi typami
    vector<long> longArray = {1000L, 500L, 2000L, 100L, 3000L};
    MergeSort<long> longSorter(longArray);
    longSorter.sort();
    
    cout << "Tablica long po sortowaniu:" << endl;
    longSorter.display();
    cout << endl;

    vector<float> floatArray = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f};
    MergeSort<float> floatSorter(floatArray);
    floatSorter.sort();
    
    cout << "Tablica float po sortowaniu:" << endl;
    floatSorter.display();

    return 0;
}
