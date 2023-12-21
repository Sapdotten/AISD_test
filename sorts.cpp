#include <iostream>
#include <vector>
using namespace std;

void SimpleInclusionSort(vector<int> &arr)
// Сортировка простым включением
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int j = i - 1;
        int temp = arr.at(i);
        while (j >= 0 && temp < arr.at(j))
        {
            swap(arr.at(j), arr.at(j + 1));
            j--;
        }
    }
}

void InsertElement(vector<int> &arr, vector<int>::iterator start, vector<int>::iterator end, int elem)
// Вставляет элемент в отсортированный массив с помощью бинарного поиска
{
    while (end - start > 0)
    {
        size_t i = (end - start) / 2;
        if (*(start + i) == elem)
        {
            arr.insert(start + i, elem);
            break;
        }
        else if (*(start + i) > elem)
        {
            end = start + i;
        }
        else
        {
            start = start + i + 1;
        }
    }
    arr.insert(start, elem);
}
void BinaryInsertSort(vector<int> &arr)
// Бинарная сортировка - вариант сортировки включениями
// Отличается тем, что в ней вставка элемента в отсортированную часть
// производится с помощью бинарного поиска
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        int elem = arr.at(i);
        arr.erase(arr.begin() + i);
        InsertElement(arr, arr.begin(), arr.begin() + i, elem);
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

void SimpleSelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int min_ind = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
}

int main()
{
    vector<int> arr;
    for (int i = 10; i >= 0; --i)
    {
        arr.push_back(i);
    }
    SimpleSelectionSort(arr);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr.at(i) << endl;
    }
    return 0;
}