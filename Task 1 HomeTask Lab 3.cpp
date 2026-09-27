//HARIS JAWAID 25K-3005 BCS-3C

#include <iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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

        cout << "After gap = " << gap << ": ";
        displayArray(arr, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nUnsorted array: ";
    displayArray(arr, n);
    cout << endl;

    shellSort(arr, n);

    cout << "\nSorted array: ";
    displayArray(arr, n);

    cout << "\n(Test with {12, 34, 54, 2, 3} -> should sort to {2, 3, 12, 34, 54})\n";

    cout << "\nShell Sort generally beats plain Insertion Sort because the large\n";
    cout << "initial gaps move far-out-of-place elements much closer to their final\n";
    cout << "position in one move, instead of one step at a time, so it does far\n";
    cout << "fewer total shifts in practice even though its worst case is still O(n^2).\n";

    return 0;
}
