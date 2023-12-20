#include <iostream>
#include <vector>
using namespace std;

void SimpleInclusionSort(vector<int> &arr)
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

int main()
{
    int arr_s[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr(arr_s, arr_s + sizeof(arr_s) / sizeof(arr_s[0]));
    SimpleInclusionSort(arr);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << endl;
    }
    return 0;
}