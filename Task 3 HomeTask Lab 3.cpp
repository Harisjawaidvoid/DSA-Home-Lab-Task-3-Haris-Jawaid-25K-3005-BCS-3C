//HARIS JAWAID 25K-3005 BCS-3C

#include <iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int iterations = 0;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        iterations++;

        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        cout << "Iteration " << iterations << ": pos = " << pos
             << " (value = " << arr[pos] << ")" << endl;

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n1 = 20;
    int uniformArr[20];
    for (int i = 0; i < n1; i++)
        uniformArr[i] = (i + 1) * 5; // 5, 10, 15, ..., 100

    cout << "Uniform array: ";
    displayArray(uniformArr, n1);

    int key1 = 55;
    cout << "\nSearching for " << key1 << " (exists):\n";
    int result1 = interpolationSearch(uniformArr, n1, key1);
    cout << (result1 != -1 ? "Found at index " : "Not found");
    if (result1 != -1) cout << result1;
    cout << endl;

    int key2 = 999;
    cout << "\nSearching for " << key2 << " (missing):\n";
    int result2 = interpolationSearch(uniformArr, n1, key2);
    cout << (result2 != -1 ? "Found at index " : "Not found");
    if (result2 != -1) cout << result2;
    cout << endl;

    int nonUniformArr[6] = {1, 2, 3, 4, 5, 1000};
    cout << "\nNon-uniform array: ";
    displayArray(nonUniformArr, 6);

    int key3 = 1000;
    cout << "\nSearching for " << key3 << " in non-uniform array:\n";
    int result3 = interpolationSearch(nonUniformArr, 6, key3);
    cout << (result3 != -1 ? "Found at index " : "Not found");
    if (result3 != -1) cout << result3;
    cout << endl;

    cout << "\n(Binary Search would take about 3 iterations on this 6-element array,\n";
    cout << "while Interpolation Search takes noticeably more here because its guess\n";
    cout << "is thrown off by the outlier value 1000.)\n";

    cout << "\nInterpolation Search averages O(log log n) on uniformly distributed\n";
    cout << "data because each guessed position lands very close to the key. On\n";
    cout << "non-uniform data (like the outlier above) the guess can be far off,\n";
    cout << "so the search ends up moving roughly one position at a time and\n";
    cout << "degrades toward O(n).\n";

    return 0;
}
