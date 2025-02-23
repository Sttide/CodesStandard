#include  <iostream>

using namespace std;

/* 练习函数模版 */

/* 函数模版定义 */
template <typename T>
void show(const T a, const T b);

/* 函数模版重载 */
template <typename T>
void show(const T a, const T b, const char* c);

/* 函数模版实例化 */
template <> void show<double>(const double a, const double b);
/* 函数模版实例化 */
template <> void show(const char *a, const char *b);

int main()
{
    show(10, 20);
    show(10.5, 20.75);
    show("hello", "world");
    show(7,8,"a");
    show("cc","oo");
    return 0;
}


/* 函数模版定义 */
template <typename T>
void show(const T a, const T b)
{
    cout << a << " " << b << endl;
}

/* 函数模版重载 */
template <typename T>
void show(const T a, const T b, const char* c)
{
    cout << "Tom: " << a << " " << b << endl;
}

/* 函数模版实例化 */
template <> void show<double>(const double a, const double b)
{
    cout << "double: " << a << " " << b << endl;
}

template <> void show(const char *a, const char *b)
{
    cout << "char*: " << a << " " << b << endl;
}