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

void ShellSort(int *arr, int size)
{
    int k = (size - 1) / 2;
    while (k > 0)
    {
        for (int i = k; i < size; ++i)
        {
            int j = i - k;
            while (j < size && j >= 0 && arr[j + k] < arr[j])
            {
                swap(arr[j], arr[j + k]);
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

void BubbleSort(int *arr, int size)
{
    bool swapped = false;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 1; j < (size - i); ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void ShakerSort(int *arr, int size)
{
    int left = 0;
    int right = size - 1;
    bool swapped = true;
    while (left < right && swapped)
    {
        swapped = false;
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] < arr[i - 1])
            {
                {
                    swap(arr[i], arr[i - 1]);
                    swapped = true;
                }
            }
        }
        for (int i = right - 1; i > 0; --i)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++left;
        --right;
    }
}

int InterpolationSearch(int *arr, int size, int elem)
{
    int low = 0, hight = size - 1;
    while (low <= hight && elem >= arr[low] && arr[hight] >= elem)
    {
        int pos = low + (hight - low) * double((elem - arr[low]) / (arr[hight] - arr[low]));
        if (arr[pos] == elem)
            return pos;
        else if (arr[pos] > elem)
        {
            hight = pos - 1;
        }
        else
            low = pos + 1;
    }
    return -1;
}

void QuickSort(int *arr, int size)
{
    if (size <= 1)
        return;
    int pivot = size / 2;
    int left = 0, right = size - 1;
    while (left <= right)
    {
        while (arr[pivot] > arr[left])
            ++left;
        while (arr[pivot] < arr[right])
            --right;
        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    QuickSort(arr, right + 1);
    QuickSort(&arr[left], size - left);
}

void Merge(int *arr, int low, int mid, int hight)
{
    int i = low, j = mid, k = hight;
    // if (i == j - 1 && j == k)
    //     return;
    if (mid - low - 1 > 0)
    {
        int temp_mid = (mid - 1 + low) / 2;
        if (temp_mid <= low)
            temp_mid = low + 1;
        Merge(arr, low, temp_mid, mid - 1);
    }
    if (hight - mid >= 1)
    {
        int temp_mid = (hight + mid) / 2;
        if (temp_mid <= mid)
            temp_mid = mid + 1;
        Merge(arr, mid, temp_mid, hight);
    }
    while (i <= mid && j <= hight)
    {
        if (arr[j] < arr[i])
        {
            for (int ind = j; ind > i; --ind)
            {
                int copy = arr[ind];
                arr[ind] = arr[ind - 1];
                arr[ind - 1] = copy;
            }
            ++j;
        }
        else
        {
            ++i;
        }
    }
}

void MergeSort(int *arr, int size)
{
    if (size <= 1)
        return;
    int mid = (size / 2);
    Merge(arr, 0, mid, size - 1);
}

int main()
{
    int sarr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort(sarr, 10);
    for (size_t i = 0; i < 10; ++i)
    {
        cout << sarr[i] << endl;
    }
    int res = InterpolationSearch(sarr, 10, 1);
    cout << res;
    return 0;
}