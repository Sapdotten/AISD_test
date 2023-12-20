#include <iostream>
#include <stdexcept>

template <typename T>
int FindPredMax(const T *arr, size_t size)
// Возвращает индекс предмаксимального элемента или -1, если его нет
{
    if (size <= 1)
        throw std::invalid_argument("Size can't be less then 1");
    int maxind = 0, predmaxind = -1;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] >= arr[maxind])
        {
            if (arr[i] != arr[maxind])
            {
                predmaxind = maxind;
            }

            maxind = i;
        }
        else if (predmaxind == -1 or arr[predmaxind] < arr[i])
            predmaxind = i;
    }
    return predmaxind;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1, 1};
    std::cout << FindPredMax<int>(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}