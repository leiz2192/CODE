#include <iostream>
#include <algorithm>
#include <string>

void BackPackWithoutReptition();
void BackPackRepeatable();
inline void coutResult(const std::string &func, int resuslt);

int main(int argc, char* argv[])
{
    BackPackRepeatable();

    BackPackWithoutReptition();

    return 0;
}

inline void coutResult(const std::string &func, int result)
{
    std::cout << __DATE__ << " " << __TIME__ << ": <" << func << ": " << result << ">\n";
}


void BackPackRepeatable()
{
    int cubage[] = { 3, 5, 2, 7, 4 };
    int value[] = { 2, 4, 1, 6, 5 };
    int weight[11] = { 0 };

    for (int i = 0; i < sizeof(cubage) / sizeof(int); ++i) {
        for (int j = 0; j < 11; ++j) {
            if (cubage[i] <= j) {
                weight[j] = std::max(weight[j], weight[(j - cubage[i])] + value[i]);
            }
        }
    }

    coutResult(__FUNCTION__, weight[10]);
}

void BackPackWithoutReptition()
{
    int c[6] = { 0, 3, 5, 2, 7, 4 };
    int v[6] = { 0, 2, 4, 1, 6, 5 };
    int f[6][11] = { 0 };
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 11; j++) {
            if (c[i] > j) {//如果背包的容量，放不下c[i]，则不选c[i]
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = std::max(f[i - 1][j], f[i - 1][j - c[i]] + v[i]);//转移方程式
            }
        }
    }
    coutResult(__FUNCTION__, f[5][10]);
}

