#include <iostream>

using namespace std;

/* 练习默认参数 */

// 默认参数必须从右向左依次设定，不能跳过中间的参数设定默认值

int caluValue(int base, int bei = 2)
{
    return base * bei;
}

int main()
{
    int sum;
    sum = caluValue(5);
    cout << sum << endl;
    sum = caluValue(5, 3);
    cout << sum << endl;
    return 0;
}