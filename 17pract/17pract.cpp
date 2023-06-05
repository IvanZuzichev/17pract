#include <Windows.h>
#include <iostream>
#include <thread>

using namespace std;

class MergeSort {
public:
    static void Sort(int* massive, int size) {
        if (size < 2)
            return;
        int mid = size / 2;
        Sort(massive, mid);
        Sort(massive + mid, size - mid);
        Merge(massive, mid, massive + mid, size - mid);
    }
private:
    static void Merge(int* left, int lSize, int* right, int rSize) {
        int* array = new int[lSize + rSize];
        int i = 0, j = 0, k = 0;
        while (i < lSize && j < rSize) {
            if (left[i] < right[j])
            {
                array[k++] = left[i++];
            }
            else
            {
                array[k++] = right[j++];
            }
        }
        while (i < lSize)
        {
            array[k++] = left[i++];
        }
        while (j < rSize)
        {
            array[k++] = right[j++];
        }
        for (i = 0; i < lSize + rSize; i++)
        {
            left[i] = array[i];
        }
    }
};

int main() {
    SetConsoleCP(1251);
    setlocale(0, "");

    const int Size = 10;
    int array[Size]{};
    cout << "Введите 10 чисел для сортировки: ";
    for (int i = 0; i < Size; i++)
    {
        cin >> array[i];
    }
    auto a = MergeSort();
    // анонимная функция
    thread sortThread([&]() { a.Sort(array, Size); });
    sortThread.join();
    cout << "Отсортированный список: ";
    for (int i = 0; i < Size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
