#include<iostream>
#include <vector>
#include "time.h"
#include "stdlib.h"
#include <chrono>
#define ArraySize 20000
using namespace std;
using namespace std::chrono;


template<typename T>
void insertionsort(T a, int n)
{
    for (int j = 2; j <= n; j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i > 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}
//void countSort(vector <int>& arr)
//{
//    int max = *max_element(arr.begin(), arr.end());
//    int min = *min_element(arr.begin(), arr.end());
//    int range = max - min + 1;
//
//    vector<int> count(range), output(arr.size());
//    for (int i = 0; i < arr.size(); i++)
//        count[arr[i] - min]++;
//
//    for (int i = 1; i < count.size(); i++)
//        count[i] += count[i - 1];
//
//    for (int i = arr.size() - 1; i >= 0; i--)
//    {
//        output[count[arr[i] - min] - 1] = arr[i];
//        count[arr[i] - min]--;
//    }
//
//    for (int i = 0; i < arr.size(); i++)
//        arr[i] = output[i];
//}
//
//void printArray(vector <int> & arr)
//{
//    for (int i = 0; i < arr.size(); i++)
//        cout << arr[i] << " ";
//    cout << "\n";
//}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R=new int [n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int Partition(int A[], int l, int r)
{
    int p = A[l];
    int i = l + 1;
    int j = r;
    while (1)
    {
        while (A[i] <= p && i < r) ++i;
        while (A[j] >= p && j > l) --j;
        if (i >= j)
        {
            swap(A[j], A[l]);
            return j;
        }
        else swap(A[i], A[j]);
    }
}
void Quicksort(int A[], int l, int r)
{
    if (l < r)
    {
        int    h = Partition(A, l, r);
        Quicksort(A, l, h - 1);
        Quicksort(A, h + 1, r);
    }
}
void selectionSort(int a[], int n)
{
    for (int i = 0; i<n - 1; i++)
    {
        int min = a[i];
        int loc = i;
        for (int j = i + 1; j<n; j++)
        {
            if (min>a[j])
            {
                min = a[j];
                loc = j;
            }
        }
        
        int temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }
}
void countSort(int *a, int n, int k)
{
    int *c = new int[k];
    int *b = new int[n];
    for (int i = 0; i <= k; i++)c[i] = 0;
    for (int j = 0; j < n; j++)
        c[a[j]] = c[a[j]] + 1;
    for (int i = 1; i <= k; i++)
        c[i] = c[i] + c[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    for (int i = 0; i < sizeof(a); i++)
        a[i] = b[i];
    
}


int main()
{
    
    int *in = new int[ArraySize];
    int *h = new int[ArraySize];
    int *co = new int[ArraySize];
    int *m = new int[ArraySize];
    int *s = new int[ArraySize];
    int *q = new int[ArraySize];
    for (int i = 0; i<ArraySize; i++)
    {
        int x = rand() % 100 + 1;
        in[i] = x;
        h[i] = x;
        co[i] = x;
        m[i] = x;
        s[i] = x;
        q[i] = x;
    }
    
    cout << "1)selectionSort\n";
    cout << "2)count Sort\n";
    cout << "3)insertion sort\n";
    cout << "4)merge Sort\n";
    cout << "5)Quicksort\n";
    cout << "6)heap Sort\n";
    cout << "0)Exit\n";
    int cho;
    while (1)
    {
        cout << "enter :"; cin >> cho;
        switch (cho)
        {
            case 3:
            {
                auto start = high_resolution_clock::now();
                insertionsort(in, ArraySize - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by insertionsort: " << duration.count() << " microseconds" << endl;
                cout << endl << endl; break;
            }
            case 6:
            {
                auto start = high_resolution_clock::now();
                heapSort(h, ArraySize);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by heapSort: " << duration.count() << " microseconds" << endl;
                cout << endl << endl; break;
            }
            case 2:
            {
                
                
                auto start = high_resolution_clock::now();
                countSort(co, ArraySize, 100);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by countSort: "<< duration.count() << " microseconds" << endl;
                cout << endl << endl; break;
            }
                //countSort(arr);
                //printArray(arr);
            case 4:
            {
                auto start = high_resolution_clock::now();
                mergeSort(m, 0, ArraySize);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by mergeSort: " << duration.count() << " microseconds" << endl;
                cout << endl << endl; break;
            }
            case 5:
            {
                
                auto start = high_resolution_clock::now();
                Quicksort(q, 0, ArraySize);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by Quicksort: " << duration.count() << " microseconds" << endl;
                cout << endl << endl; break;
            }
                
            case 1:
            {
                auto start = high_resolution_clock::now();
                selectionSort(s, ArraySize);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by selectionSort: " << duration.count() << " microseconds" << endl;
                cout << endl << endl;
                break;
            }
            case 0: {exit(0); }
            default: {cout << "try again :"; break; }
        }
    }
    
    /*for (int i = 0; i < ArraySize; i++)
     {
     cout <<"a["<<i<<"] = "<<a[i];
     cout << endl;
     }*/
    //cout <<"test\n";
    //system("pause");
}

