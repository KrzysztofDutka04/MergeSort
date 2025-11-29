#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

int main() {
    // Test z liczbami całkowitymi (int)
    vector<int> intArray;
    intArray.push_back(64);
    intArray.push_back(34);
    intArray.push_back(25);
    intArray.push_back(12);
    intArray.push_back(22);
    intArray.push_back(11);
    intArray.push_back(90);
    intArray.push_back(5);
    intArray.push_back(77);
    intArray.push_back(30);
    
    cout << "Tablica int przed sortowaniem:" << endl;
    for (size_t i = 0; i < intArray.size(); i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    MergeSort<int> intSorter(intArray);
    intSorter.sort();
    
    cout << "Tablica int po sortowaniu:" << endl;
    intSorter.display();
    cout << endl;

    // Test z liczbami zmiennoprzecinkowymi (double)
    vector<double> doubleArray;
    doubleArray.push_back(64.5);
    doubleArray.push_back(34.2);
    doubleArray.push_back(25.1);
    doubleArray.push_back(12.7);
    doubleArray.push_back(22.8);
    doubleArray.push_back(11.9);
    doubleArray.push_back(90.3);
    doubleArray.push_back(5.6);
    doubleArray.push_back(77.4);
    doubleArray.push_back(30.0);
    
    cout << "Tablica double przed sortowaniem:" << endl;
    for (size_t i = 0; i < doubleArray.size(); i++) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    MergeSort<double> doubleSorter(doubleArray);
    doubleSorter.sort();
    
    cout << "Tablica double po sortowaniu:" << endl;
    doubleSorter.display();
    cout << endl;

    // Dodatkowe testy z innymi typami
    vector<long> longArray;
    longArray.push_back(1000L);
    longArray.push_back(500L);
    longArray.push_back(2000L);
    longArray.push_back(100L);
    longArray.push_back(3000L);
    
    cout << "Tablica long przed sortowaniem:" << endl;
    for (size_t i = 0; i < longArray.size(); i++) {
        cout << longArray[i] << " ";
    }
    cout << endl;

    MergeSort<long> longSorter(longArray);
    longSorter.sort();
    
    cout << "Tablica long po sortowaniu:" << endl;
    longSorter.display();
    cout << endl;

    vector<float> floatArray;
    floatArray.push_back(3.14f);
    floatArray.push_back(2.71f);
    floatArray.push_back(1.41f);
    floatArray.push_back(1.73f);
    floatArray.push_back(0.57f);
    
    cout << "Tablica float przed sortowaniem:" << endl;
    for (size_t i = 0; i < floatArray.size(); i++) {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    MergeSort<float> floatSorter(floatArray);
    floatSorter.sort();
    
    cout << "Tablica float po sortowaniu:" << endl;
    floatSorter.display();
    cout << endl;

    return 0;
}
