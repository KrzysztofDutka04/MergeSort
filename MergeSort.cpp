/**
 * @file mergesort.cpp
 * @brief Implementacja klasy MergeSort
 */

#include "mergesort.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Konstruktor klasy MergeSort
 * @param inputArray Referencja do tablicy wejściowej
 */
template<typename T>
MergeSort<T>::MergeSort(vector<T>& inputArray) : array(inputArray) {}

/**
 * @brief Główna funkcja sortująca
 * 
 * Rozpoczyna proces sortowania przez scalanie jeśli tablica ma więcej niż 1 element.
 * W przeciwnym razie tablica jest już posortowana.
 */
template<typename T>
void MergeSort<T>::sort() {
    if (array.size() > 1) {
        mergeSort(0, static_cast<int>(array.size() - 1));
    }
}

/**
 * @brief Rekurencyjna funkcja dzieląca tablicę na mniejsze części
 * @param left Indeks lewego krańca aktualnego fragmentu tablicy
 * @param right Indeks prawego krańca aktualnego fragmentu tablicy
 * 
 * Algorytm dzieli tablicę na dwie części rekurencyjnie aż do uzyskania pojedynczych elementów,
 * a następnie scala je w posortowane fragmenty.
 */
template<typename T>
void MergeSort<T>::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  ///< Środek tablicy (bez przepełnienia)
        mergeSort(left, mid);      ///< Sortowanie lewej połowy
        mergeSort(mid + 1, right); ///< Sortowanie prawej połowy
        merge(left, mid, right);   ///< Scalanie posortowanych połówek
    }
}

/**
 * @brief Funkcja scalająca dwie posortowane podtablice
 * @param left Indeks początku lewej podtablicy
 * @param mid Indeks końca lewej podtablicy i początku prawej podtablicy
 * @param right Indeks końca prawej podtablicy
 * 
 * Tworzy tymczasowe tablice L i R, następnie scala je w oryginalnej tablicy
 * w porządku rosnącym.
 */
template<typename T>
void MergeSort<T>::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;  ///< Rozmiar lewej podtablicy
    int n2 = right - mid;     ///< Rozmiar prawej podtablicy
    
    vector<T> L(n1), R(n2);   ///< Tymczasowe tablice pomocnicze
    
    // Kopiowanie danych do tymczasowych tablic L[] i R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
        
    int i = 0;      ///< Indeks dla lewej podtablicy
    int j = 0;      ///< Indeks dla prawej podtablicy  
    int k = left;   ///< Indeks dla scalonej tablicy
    
    // Scalanie tymczasowych tablic z powrotem do array[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Kopiowanie pozostałych elementów z L[], jeśli jakieś zostały
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    
    // Kopiowanie pozostałych elementów z R[], jeśli jakieś zostały
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Wyświetla zawartość tablicy
 * 
 * Format wyjściowy: element1 element2 element3 ...
 */
template<typename T>
void MergeSort<T>::display() const {
    for (size_t i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Jawne instancje szablonów dla różnych typów danych
template class MergeSort<int>;      ///< Instancja dla typu int
template class MergeSort<double>;   ///< Instancja dla typu double  
template class MergeSort<long>;     ///< Instancja dla typu long
template class MergeSort<float>;    ///< Instancja dla typu float
