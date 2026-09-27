//HARIS JAWAID 25K-3005 BCS-3C


#include <iostream>
#include <ctime>
using namespace std;

unsigned long seed = 12345;
int myRandom(int maxVal) {
    seed = (seed * 1103515245 + 12345) % 2147483648;
    return seed % maxVal;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        int t = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = t;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int i;
            for (i = j; i >= gap && arr[i - gap] > temp; i -= gap)
                arr[i] = arr[i - gap];
            arr[i] = temp;
        }
    }
}

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (int)(gap / 1.3);
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int t = arr[i]; arr[i] = arr[i + gap]; arr[i + gap] = t;
                swapped = true;
            }
        }
    }
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = myRandom(100000);
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

double timeSort(void (*sortFunc)(int[], int), int arr[], int n) {
    int* temp = new int[n];
    copyArray(arr, temp, n);

    clock_t start = clock();
    sortFunc(temp, n);
    clock_t end = clock();

    delete[] temp;
    return double(end - start) * 1000.0 / CLOCKS_PER_SEC; // milliseconds
}

void runAllSorts(int arr[], int n) {
    cout << "Bubble Sort:    " << timeSort(bubbleSort, arr, n) << " ms\n";
    cout << "Selection Sort: " << timeSort(selectionSort, arr, n) << " ms\n";
    cout << "Insertion Sort: " << timeSort(insertionSort, arr, n) << " ms\n";
    cout << "Shell Sort:     " << timeSort(shellSort, arr, n) << " ms\n";
    cout << "Comb Sort:      " << timeSort(combSort, arr, n) << " ms\n";
}

int main() {
    int sizes[] = {100, 1000, 10000, 50000};

    cout << "----- Timing on random arrays -----\n";
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int* arr = new int[n];
        fillRandom(arr, n);

        cout << "\nn = " << n << ":\n";
        runAllSorts(arr, n);

        delete[] arr;
    }

    cout << "\n----- Timing on n = 10000 for random / sorted / reverse-sorted -----\n";
    int n = 10000;
    int* randomArr = new int[n];
    int* sortedArr = new int[n];
    int* reverseArr = new int[n];

    fillRandom(randomArr, n);
    for (int i = 0; i < n; i++) sortedArr[i] = i;
    for (int i = 0; i < n; i++) reverseArr[i] = n - i;

    cout << "\nRandom array:\n";
    runAllSorts(randomArr, n);

    cout << "\nAlready-sorted array:\n";
    runAllSorts(sortedArr, n);

    cout << "\nReverse-sorted array:\n";
    runAllSorts(reverseArr, n);

    delete[] randomArr;
    delete[] sortedArr;
    delete[] reverseArr;

    cout << "\n(Copy the numbers printed above into the results table in your report\n";
    cout << "and plot them on a graph. Bubble, Insertion and Comb Sort are clearly\n";
    cout << "sensitive to input order - they finish much faster on the sorted array -\n";
    cout << "while Selection Sort stays roughly the same regardless of order, since it\n";
    cout << "always scans the whole remaining array on every pass.)\n";

    cout << "\nRecommendation:\n";
    cout << "(a) For a nearly-sorted array of 50 elements, Insertion Sort is the best\n";
    cout << "choice - it runs close to O(n) on nearly-sorted data with almost no\n";
    cout << "overhead. (b) For a random array of 100,000 elements, none of these five\n";
    cout << "is ideal since they are all O(n^2) in the worst/average case except Shell\n";
    cout << "and Comb Sort; between those two, Comb Sort's shrink-factor approach\n";
    cout << "usually edges out Shell Sort here. (c) For an embedded system with very\n";
    cout << "limited memory, Insertion Sort or Shell Sort are good picks since both\n";
    cout << "sort in place with O(1) extra space and very simple code.\n";

    return 0;
}
