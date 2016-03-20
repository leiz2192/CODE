// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

template<class T>
void lazyPrintf(const T& t)
{
    for (T::const_iterator iter = t.begin(); iter != t.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << "\n";
}

void quicksort(std::vector<int> &v, int left, int right)
{
    if (left < right) {
        int key = v[left];
        int low = left;
        int high = right;
        while (low < high) {
            while ((low < high) && (v[high] >= key)) {
                --high;
            }
            v[low] = v[high];

            while ((low < high) && (v[low] <= key)) {
                ++low;
            }
            v[high] = v[low];
        }

        v[low] = key;
        quicksort(v, left, low - 1);
        quicksort(v, low + 1, right);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = {2, 8, 7, 1, 3, 8, 10, 5, 6, 4, 2};

    std::vector<int> data(a, a + sizeof(a)/sizeof(int));
    lazyPrintf(data);

    quicksort(data, 0, data.size() - 1);
    lazyPrintf(data);

	return 0;
}

