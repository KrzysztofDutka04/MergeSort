#include "mergesort.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
MergeSort<T>::MergeSort(vector<T>& inputArray) : array(inputArray) {}  // Inicjalizacja referencji

template<typename T>
void MergeSort<T>::sort() {
    if (array.size() > 1) {
        mergeSort(0, static_cast<int>(array.size() - 1));
    }
}

template<typename T>
void MergeSort<T>::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

template<typename T>
void MergeSort<T>::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void MergeSort<T>::display() const {
    for (size_t i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Jawne instancje szablonów
template class MergeSort<int>;
template class MergeSort<double>;
template class MergeSort<long>;
template class MergeSort<float>;
