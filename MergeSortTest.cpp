#include <gtest/gtest.h>
#include <vector>
#include "mergesort.h"

TEST(TestSortowania, SortowanieTablicyInt) {
    std::vector<int> wejscie = { 64, 34, 25, 12, 22, 11, 90, 5 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    // Sprawdź czy tablica jest posortowana
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

TEST(TestSortowania, SortowanieTablicyDouble) {
    std::vector<double> wejscie = { 64.5, 34.2, 25.1, 12.7 };

    MergeSort<double> sorter(wejscie);
    sorter.sort();

    // Sprawdź czy elementy są w dobrej kolejności
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

TEST(TestSortowania, PustaTablica) {
    std::vector<int> wejscie;

    MergeSort<int> sorter(wejscie);
    sorter.sort(); // Nie powinno powodować błędu

    SUCCEED(); // Jeśli doszliśmy tutaj, test przeszedł
}

TEST(TestSortowania, JedenElement) {
    std::vector<int> wejscie = { 42 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_EQ(wejscie[0], 42);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
