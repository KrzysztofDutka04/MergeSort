#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<typename T>
class MergeSort {
private:
    std::vector<T>& array;  // Referencja do oryginalnej tablicy!
    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

public:
    MergeSort(std::vector<T>& inputArray);  // Brak const - będziemy modyfikować
    void sort();
    void display() const;
};

#endif
