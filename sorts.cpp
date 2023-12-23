#include <iostream>
#include <vector>
using namespace std;

void SimpleInsertSort(int *arr, int size)
// Сортировка простым включением
{
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        while (j >= 0 && arr[j + 1] < arr[j])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

void InsertElement(int *arr, int beg, int end, int elem_ind)
{
    int i;
    while (beg <= end)
    {
        i = (end + beg) / 2;
        if (arr[i] == arr[elem_ind])
        {
            i += 1;
            break;
        }
        else if (arr[i] > arr[elem_ind])
        {
            end = i - 1;
        }
        else
        {
            beg = i + 1;
        }
    }
    while (i != elem_ind)
    {
        swap(arr[elem_ind], arr[elem_ind - 1]);
        --elem_ind;
    }
}

void BinaryInsertSort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int elem = arr[i];
        InsertElement(arr, 0, i - 1, i);
    }
}

void ShellSort(vector<int> &arr)
{
    int k = (arr.size() - 1) / 2;
    while (k > 0)
    {
        for (int i = k; i < arr.size(); ++i)
        {
            int j = i - k;
            int temp = arr.at(i);
            while (j < arr.size() && j >= 0 && temp < arr.at(j))
            {
                swap(arr.at(j), arr.at(j + k));
                j--;
            }
        }
        k = k / 2;
    }
}

void SimpleSelectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_ind = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
}

void BubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 1; j < (arr.size() - i); ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void ShakerSort(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        for (int i = right - 1; i > 0; --i)
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        ++left;
        --right;
    }
}

int main()
{
    int sarr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    BinaryInsertSort(sarr, 10);
    for (size_t i = 0; i < 10; ++i)
    {
        cout << sarr[i] << endl;
    }
    return 0;
}