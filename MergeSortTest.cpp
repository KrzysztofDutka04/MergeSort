/**
 * @file MergeSortTest.cpp
 * @brief Testy jednostkowe dla klasy MergeSort przy użyciu Google Test
 */

#include <gtest/gtest.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "mergesort.h"

using namespace std;

/**
 * @test Test sprawdzający czy algorytm zachowuje już posortowaną tablicę
 */
TEST(TestSortowania, ZachowujePosortowanaRosnaco) {
    vector<int> wejscie = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    sort(wejscie.begin(), wejscie.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania tablicy posortowanej w odwrotnej kolejności
 */
TEST(TestSortowania, SortujeOdwrotniePosortowana) {
    vector<int> wejscie = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    vector<int> oczekiwane = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(wejscie, oczekiwane);
}

/**
 * @test Test sortowania losowej tablicy liczb
 */
TEST(TestSortowania, SortujeLosowaTablice) {
    vector<int> wejscie = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania tablicy zawierającej tylko liczby ujemne
 */
TEST(TestSortowania, SortujeTylkoUjemne) {
    vector<int> wejscie = {-5, -2, -8, -1, -3, -7, -4, -6, -9, -10};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania tablicy z liczbami ujemnymi i dodatnimi
 */
TEST(TestSortowania, SortujeUjemneIDodatnie) {
    vector<int> wejscie = {-5, 2, -8, 1, -3, 7, -4, 0, -6, 10};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test obsługi pustej tablicy
 */
TEST(TestSortowania, ObslugujePustaTablica) {
    vector<int> wejscie;
    
    MergeSort<int> sorter(wejscie);
    EXPECT_NO_THROW(sorter.sort());
    
    SUCCEED();
}

/**
 * @test Test tablicy z jednym elementem
 */
TEST(TestSortowania, NieZmieniaJedenElement) {
    vector<int> wejscie = {42};
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    EXPECT_EQ(wejscie.size(), 1);
    EXPECT_EQ(wejscie[0], 42);
}

/**
 * @test Test sortowania tablicy z duplikatami liczb
 */
TEST(TestSortowania, SortujeZDuplikatami) {
    vector<int> wejscie = {5, 2, 8, 2, 5, 1, 8, 1, 3, 3};
    vector<int> oczekiwane = {1, 1, 2, 2, 3, 3, 5, 5, 8, 8};
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    EXPECT_EQ(wejscie, oczekiwane);
}

/**
 * @test Test sortowania tablicy ujemnej z duplikatami
 */
TEST(TestSortowania, SortujeUjemnaZDuplikatami) {
    vector<int> wejscie = {-5, -2, -5, -1, -3, -2, -1, -3, -5, -2};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania tablicy z liczbami ujemnymi, dodatnimi oraz duplikatami
 */
TEST(TestSortowania, SortujeUjemneDodatnieDuplikaty) {
    vector<int> wejscie = {-5, 2, -5, 0, -3, 2, 0, -3, 5, -2};
    vector<int> kopia = wejscie;
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania tablicy z dwoma elementami w kolejności rosnącej
 */
TEST(TestSortowania, SortujeDwaElementyRosnaco) {
    vector<int> wejscie = {1, 2};
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    EXPECT_LE(wejscie[0], wejscie[1]);
    EXPECT_EQ(wejscie[0], 1);
    EXPECT_EQ(wejscie[1], 2);
}

/**
 * @test Test sortowania tablicy z dwoma elementami w kolejności malejącej
 */
TEST(TestSortowania, SortujeDwaElementyMalejaco) {
    vector<int> wejscie = {2, 1};
    
    MergeSort<int> sorter(wejscie);
    sorter.sort();
    
    EXPECT_LE(wejscie[0], wejscie[1]);
    EXPECT_EQ(wejscie[0], 1);
    EXPECT_EQ(wejscie[1], 2);
}

/**
 * @test Test sortowania dużej tablicy (ponad 100 elementów)
 */
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

/**
 * @test Test sortowania dużej tablicy z liczbami ujemnymi, dodatnimi i duplikatami
 */
TEST(TestSortowania, SortujeDuzaTablicaMieszana) {
    vector<int> wejscie;
    srand(time(0));
    
    for (int i = 0; i < 200; i++) {
        int liczba = (rand() % 200) - 100;
        wejscie.push_back(liczba);
    }
    
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

/**
 * @test Test sortowania dla typu double
 */
TEST(TestSortowaniaDouble, SortujeDouble) {
    vector<double> wejscie = {64.5, 34.2, 25.1, 12.7, 22.8, 11.9, 90.3, 5.6};
    vector<double> kopia = wejscie;
    
    MergeSort<double> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @test Test sortowania dla typu float
 */
TEST(TestSortowaniaFloat, SortujeFloat) {
    vector<float> wejscie = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f, 2.35f};
    vector<float> kopia = wejscie;
    
    MergeSort<float> sorter(wejscie);
    sorter.sort();
    
    for (size_t i = 0; i < wejscie.size() - 1; i++) {
        EXPECT_LE(wejscie[i], wejscie[i + 1]);
    }
    
    sort(kopia.begin(), kopia.end());
    EXPECT_EQ(wejscie, kopia);
}

/**
 * @brief Główna funkcja uruchamiająca testy
 * @param argc Liczba argumentów
 * @param argv Tablica argumentów
 * @return Kod powrotu aplikacji
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
