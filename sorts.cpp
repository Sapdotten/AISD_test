#include <iostream>
#include <vector>
using namespace std;

void SimpleInclusionSort(vector<int> &arr)
// Сортировка простым включением
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int j = i - 1;
        int temp = arr[i];
        while (temp < arr[j] && j >= 0)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
        arr[j] = temp;
    }
}

void InsertElement(vector<int> &arr, vector<int>::iterator start, vector<int>::iterator end, int elem)
// Вставляет элемент в отсортированный массив с помощью бинарного поиска
{
    while (start - end > 0)
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

int main()
{
    vector<int> arr;
    for (int i = 10; i >= 0; --i)
    {
        arr.push_back(i);
    }
    BinaryInsertSort(arr);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr.at(i) << endl;
    }
    return 0;
}