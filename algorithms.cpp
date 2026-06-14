#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    cout << "Bubble Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
    int i=0, j=0, k=l;
    while (i<(int)left.size() && j<(int)right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i<(int)left.size()) arr[k++] = left[i++];
    while (j<(int)right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low-1;
    for (int j=low; j<high; j++)
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int binarySearch(vector<int>& arr, int target) {
    int low=0, high=arr.size()-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

vector<long long> fibonacci(int n) {
    vector<long long> fib(n);
    fib[0]=0; if(n>1) fib[1]=1;
    for (int i=2; i<n; i++) fib[i] = fib[i-1]+fib[i-2];
    return fib;
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i*i<=n; i++)
        if (is_prime[i])
            for (int j=i*i; j<=n; j+=i)
                is_prime[j] = false;
    vector<int> primes;
    for (int i=2; i<=n; i++)
        if (is_prime[i]) primes.push_back(i);
    return primes;
}

int main() {
    cout << "=== ALGORITHMS IN C++ ===" << endl << endl;

    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Input: ";
    for (int x : arr) cout << x << " ";
    cout << endl << endl;

    cout << "--- Sorting ---" << endl;
    bubbleSort(arr);

    vector<int> arr2 = arr;
    mergeSort(arr2, 0, arr2.size()-1);
    cout << "Merge Sort:  ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    vector<int> arr3 = arr;
    quickSort(arr3, 0, arr3.size()-1);
    cout << "Quick Sort:  ";
    for (int x : arr3) cout << x << " ";
    cout << endl;

    cout << "\n--- Binary Search ---" << endl;
    vector<int> sorted = {11, 12, 22, 25, 34, 64, 90};
    int idx = binarySearch(sorted, 25);
    cout << "Search 25 -> index: " << idx << endl;

    cout << "\n--- Fibonacci (n=10) ---" << endl;
    vector<long long> fib = fibonacci(10);
    for (long long x : fib) cout << x << " ";
    cout << endl;

    cout << "\n--- Primes up to 50 ---" << endl;
    vector<int> primes = sieve(50);
    for (int x : primes) cout << x << " ";
    cout << endl;

    cout << "\n=== DONE ===" << endl;
    return 0;
}