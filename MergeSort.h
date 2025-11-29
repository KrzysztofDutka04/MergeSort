#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template<typename T>
class MergeSort {
private:
    std::vector<T> array;
    
public:
    MergeSort(const std::vector<T>& inputArray);
    void sort();
    void display() const;
};

#endif
