/*Algorithm:
QUICKSORT(arr, low, high)
1. if (low < high)
2.     pivot_index = PARTITION(arr, low, high)
3.     QUICKSORT(arr, low, pivot_index - 1)
4.     QUICKSORT(arr, pivot_index + 1, high)

PARTITION(arr, low, high)
1. pivot = arr[high]
2. i = low - 1
3. for j = low to high - 1
4.     if (arr[j] <= pivot)
5.         i = i + 1
6.         swap arr[i] and arr[j]
7. swap arr[i + 1] and arr[high]
8. return i + 1*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    srand(time(0));

    cout << "Generated array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        cout << arr[i] << " ";
    }

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken: " << time_taken << " seconds" << endl;

    return 0;
}

/*Sample Output:
Enter number of elements: 10
Generated array: 125 42 58 963 274 12 33 745 421 6 
Sorted array: 6 12 33 42 58 125 274 421 745 963 
Time taken: 0.000002 seconds*/

/*Time Complexity Analysis:
Best Case:	O(n log n)
Average Case:	O(n log n)
Worst Case:	O(n²)*/
