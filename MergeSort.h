/**
 * @file mergesort.h
 * @brief Deklaracja klasy MergeSort implementującej algorytm sortowania przez scalanie
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/**
 * @class MergeSort
 * @brief Klasa implementująca algorytm sortowania przez scalanie
 * 
 * @tparam T Typ danych do sortowania (musi obsługiwać operator <=)
 */
template<typename T>
class MergeSort {
private:
    std::vector<T>& array;  ///< Referencja do tablicy do posortowania
    
    /**
     * @brief Scalanie dwóch posortowanych podtablic
     * @param left Indeks lewego krańca tablicy
     * @param mid Indeks środkowego elementu
     * @param right Indeks prawego krańca tablicy
     */
    void merge(int left, int mid, int right);
    
    /**
     * @brief Rekurencyjna funkcja sortowania przez scalanie
     * @param left Indeks lewego krańca tablicy do posortowania
     * @param right Indeks prawego krańca tablicy do posortowania
     */
    void mergeSort(int left, int right);
    
public:
    /**
     * @brief Konstruktor klasy MergeSort
     * @param inputArray Referencja do tablicy wejściowej do posortowania
     */
    MergeSort(std::vector<T>& inputArray);
    
    /**
     * @brief Główna funkcja rozpoczynająca proces sortowania
     */
    void sort();
    
    /**
     * @brief Wyświetla zawartość tablicy
     */
    void display() const;
};

#endif
