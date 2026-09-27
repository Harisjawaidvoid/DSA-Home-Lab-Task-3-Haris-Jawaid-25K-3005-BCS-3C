//HARIS JAWAID 25K-3005 BCS-3C

#include <iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n, int &swapCount, int &comparisonCount) {
    swapCount = 0;
    comparisonCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }
}

void combSort(int arr[], int n, int &swapCount, int &comparisonCount) {
    int gap = n;
    bool swapped = true;
    swapCount = 0;
    comparisonCount = 0;

    while (gap != 1 || swapped) {
        gap = (int)(gap / 1.3);
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            comparisonCount++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapCount++;
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100], arrCopy[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrCopy[i] = arr[i];
    }

    cout << "\nUnsorted array: ";
    displayArray(arr, n);

    int combSwaps, combComparisons;
    combSort(arr, n, combSwaps, combComparisons);

    cout << "\nSorted array (Comb Sort): ";
    displayArray(arr, n);
    cout << "Comb Sort -> Comparisons: " << combComparisons
         << ", Swaps: " << combSwaps << endl;

    int bubbleSwaps, bubbleComparisons;
    bubbleSort(arrCopy, n, bubbleSwaps, bubbleComparisons);

    cout << "\nSorted array (Bubble Sort): ";
    displayArray(arrCopy, n);
    cout << "Bubble Sort -> Comparisons: " << bubbleComparisons
         << ", Swaps: " << bubbleSwaps << endl;

    cout << "\n(Run this on a reverse-sorted array of 20 elements to see Comb Sort\n";
    cout << "do far fewer swaps/comparisons than Bubble Sort on the same input.)\n";

    return 0;
}
