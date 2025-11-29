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
    vector<int> oczekiwane = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 2: Sortuje tablicę posortowaną w odwrotnej kolejności
TEST(TestSortowania, SortujeOdwrotniePosortowana) {
    vector<int> wejscie = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 3: Sortuje losową tablicę liczb
TEST(TestSortowania, SortujeLosowaTablice) {
    vector<int> wejscie = { 64, 34, 25, 12, 22, 11, 90, 5, 77, 30 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 4: Sortuje tablice tylko z liczbami ujemnymi
TEST(TestSortowania, SortujeTylkoUjemne) {
    vector<int> wejscie = { -5, -2, -8, -1, -3, -7, -4, -6, -9, -10 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 5: Sortuje tablice z liczbami ujemnymi i dodatnimi
TEST(TestSortowania, SortujeUjemneIDodatnie) {
    vector<int> wejscie = { -5, 2, -8, 1, -3, 7, -4, 0, -6, 10 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 6: Obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(TestSortowania, ObslugujePustaTablica) {
    vector<int> wejscie;

    MergeSort<int> sorter(wejscie);
    EXPECT_NO_THROW(sorter.sort());

    SUCCEED();
}

// Test 7: Nie zmienia tablicy z jednym elementem
TEST(TestSortowania, NieZmieniaJedenElement) {
    vector<int> wejscie = { 42 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_EQ(wejscie.size(), 1);
    EXPECT_EQ(wejscie[0], 42);
}

// Test 8: Sortuje tablicę z duplikatami liczb
TEST(TestSortowania, SortujeZDuplikatami) {
    vector<int> wejscie = { 5, 2, 8, 2, 5, 1, 8, 1, 3, 3 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 9: Sortuje tablicę ujemną z duplikatami
TEST(TestSortowania, SortujeUjemnaZDuplikatami) {
    vector<int> wejscie = { -5, -2, -5, -1, -3, -2, -1, -3, -5, -2 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 10: Sortuje tablicę z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(TestSortowania, SortujeUjemneDodatnieDuplikaty) {
    vector<int> wejscie = { -5, 2, -5, 0, -3, 2, 0, -3, 5, -2 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 11: Sortuje tablicę z dwoma elementami w kolejności rosnącej
TEST(TestSortowania, SortujeDwaElementyRosnaco) {
    vector<int> wejscie = { 1, 2 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_LE(wejscie[0], wejscie[1]);
}

// Test 12: Sortuje tablicę z dwoma elementami w kolejności malejącej
TEST(TestSortowania, SortujeDwaElementyMalejaco) {
    vector<int> wejscie = { 2, 1 };

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    EXPECT_LE(wejscie[0], wejscie[1]);
}

// Test 13: Sortuje dużą tablicę (ponad 100 elementów)
TEST(TestSortowania, SortujeDuzaTablica) {
    vector<int> wejscie;
    for (int i = 0; i < 150; i++) {
        wejscie.push_back(rand() % 1000);
    }

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test 14: Sortuje dużą tablicę z liczbami ujemnymi, dodatnimi i duplikatami
TEST(TestSortowania, SortujeDuzaTablicaMieszana) {
    vector<int> wejscie;
    srand(time(0));

    for (int i = 0; i < 200; i++) {
        int liczba = (rand() % 200) - 100; // liczby od -100 do 100
        wejscie.push_back(liczba);
    }

    // Dodajemy kilka duplikatów
    for (int i = 0; i < 20; i++) {
        wejscie.push_back(0);
        wejscie.push_back(-50);
        wejscie.push_back(50);
    }

    MergeSort<int> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test dla typu double
TEST(TestSortowaniaDouble, SortujeDouble) {
    vector<double> wejscie = { 64.5, 34.2, 25.1, 12.7, 22.8, 11.9, 90.3, 5.6 };

    MergeSort<double> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

// Test dla typu float
TEST(TestSortowaniaFloat, SortujeFloat) {
    vector<float> wejscie = { 3.14f, 2.71f, 1.41f, 1.73f, 0.57f, 2.35f };

    MergeSort<float> sorter(wejscie);
    sorter.sort();

    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
