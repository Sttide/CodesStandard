#include <iostream>

using namespace std;

class window
{
private:
    int m_length;
    int m_width;
    int m_square;
public:
    window();
    window(int l, int w){
        m_length = l;
        m_width = w;
        calculate_square();
    }
    ~window();
    void set_length(int l);
    void set_width(int w);
    void calculate_square();
    void show_square();
};

window::window()
{
    m_length = 0;
    m_width = 0;
    calculate_square();
}

void window::set_length(int l)
{
    m_length = l;
    return;
}

void window::set_width(int w)
{
    m_width = w;
    return;
}

void window::calculate_square()
{
    m_square = m_length * m_width;
    return;
}

void window::show_square()
{
    cout << "Square of window is: " << m_square << endl;
    return;
}

window::~window()
{
    cout << "Destructor called: " << m_length << "!"<< endl;
}

int main()
{
    {
        window w1(5, 10);
        w1.show_square();
        window w2;
        w2.show_square();
        window w3;
        w3.set_length(15);
        w3.set_width(20);
        w3.show_square();
    }
    return 0;
}