#include <iostream>
#include <algorithm>

int sumOfMaxSubArray(int * array, int n);

int main(int argc, char* argv[])
{
    int arrayA[] = {1, -2, 1, 5, -3, 2};
    std::cout << sumOfMaxSubArray(arrayA, sizeof(arrayA) / sizeof(int)) << '\n';

    int arrayB[] = {-9, -2, -3, -5, -6};
    std::cout << sumOfMaxSubArray(arrayB, sizeof(arrayB) / sizeof(int)) << '\n';

    return 0;
}

int sumOfMaxSubArray(int * array, int n)
{
    int start = array[0];
    int maxsum = array[0];
    for (int i = 1; i < (n - 1); ++i) {
        start = std::max(array[i], array[i] + start);
        maxsum = std::max(start, maxsum);
    }

    return maxsum;
}

