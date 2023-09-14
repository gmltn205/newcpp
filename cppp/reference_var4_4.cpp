#include <iostream>

class A
{
    int x;

public:
    A(int c) : x(c) {}

    int &access_x() { return x; } // 레퍼런스 리턴
    int get_x() { return x; }     // x의 값을 리턴
    void show_x() { std::cout << x << std::endl; }
};
int main()
{
    A a(5);
    a.show_x();

    int &c = a.access_x();
    c = 4;
    /* c는 x의 별명으로 태어남. 즉 int &c=x;
     즉 a의 x값을 바꾸는것과 동일한데
     아래에서 d는
     단순히 넣어주기만 함.

    */
    a.show_x();

    int d = a.access_x();
    d = 3;
    a.show_x();

    int f = a.get_x();
    std::cout << f << std::endl;
    f = 1;
    a.show_x();
}