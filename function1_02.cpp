#include <iostream>

using namespace std;

/* 练习函数重载 */

// 主要用于函数功能想同，处理的数据类型不同，或者处理的数据个数不同。


int caluValue(int base, int bei)
{
    return base * bei;
}

double caluValue(double base, double bei)
{
    return base * bei;
}


int main()
{
    int sum;
    sum = caluValue(5,2);
    cout << sum << endl;

    double sum2;
    sum2 = caluValue(5.1, 3.2);
    cout << sum2 << endl;
    return 0;
}