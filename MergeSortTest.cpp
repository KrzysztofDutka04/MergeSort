#include <gtest/gtest.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "mergesort.h"

using namespace std;

// Test 1: Zachowuje tablicę niezmienioną, gdy jest już posortowana rosnąco
TEST(TestSortowania, ZachowujePosortowanaRosnaco) {
    vector<int> wejscie = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> kopia = wejscie; // Zachowujemy kopię do porównania

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    // Sprawdzamy czy tablica jest posortowana
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }

    // Sprawdzamy czy elementy się nie zmieniły (tylko kolejność może być taka sama)
    sort(kopia.begin(), kopia.end());
    sort(wejscie.begin(), wejscie.end());
    EXPECT_EQ(wejscie, kopia);
}

// Test 2: Sortuje tablicę posortowaną w odwrotnej kolejności
TEST(TestSortowania, SortujeOdwrotniePosortowana) {
    vector<int> wejscie = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }

    // Sprawdzamy czy zawiera te same elementy
    vector<int> oczekiwane = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EXPECT_EQ(wejscie, oczekiwane);
}

// Test 3: Sortuje losową tablicę liczb
TEST(TestSortowania, SortujeLosowaTablice) {
    vector<int> wejscie = { 64, 34, 25, 12, 22, 11, 90, 5, 77, 30 };
    vector<int> kopia = wejscie;

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }

    // Sprawdzamy czy zawiera te same elementy
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

// Test 4: Sortuje tablice tylko z liczbami ujemnymi
TEST(TestSortowania, SortujeTylkoUjemne) {
    vector<int> wejscie = { -5, -2, -8, -1, -3, -7, -4, -6, -9, -10 };
    vector<int> kopia = wejscie;

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }

    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

// Test 8: Sortuje tablicę z duplikatami liczb
TEST(TestSortowania, SortujeZDuplikatami) {
    vector<int> wejscie = { 5, 2, 8, 2, 5, 1, 8, 1, 3, 3 };
    vector<int> oczekiwane = { 1, 1, 2, 2, 3, 3, 5, 5, 8, 8 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_EQ(wejscie, oczekiwane);
}

// Test 11: Sortuje tablicę z dwoma elementami w kolejności rosnącej
TEST(TestSortowania, SortujeDwaElementyRosnaco) {
    vector<int> wejscie = { 1, 2 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_LE(wejscie[0], wejscie[1]);
    EXPECT_EQ(wejscie[0], 1);
    EXPECT_EQ(wejscie[1], 2);
}

// Test 12: Sortuje tablicę z dwoma elementami w kolejności malejącej
TEST(TestSortowania, SortujeDwaElementyMalejaco) {
    vector<int> wejscie = { 2, 1 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_LE(wejscie[0], wejscie[1]);
    EXPECT_EQ(wejscie[0], 1);
    EXPECT_EQ(wejscie[1], 2);
}

// Pozostałe testy pozostają bez zmian...

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
