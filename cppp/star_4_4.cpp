#include <iostream>

class Marine
{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

public:
    Marine();
    Marine(int x, int y);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};

Marine::Marine() : hp(50),
                   coord_x(0),
                   coord_y(0),
                   damage(0),
                   is_dead(false) {}
/*
: 을 해주고 해주면 이는 초기화 리스트이다.
생성자 호출과 동시에 멤버 변수들을 초기화 해주게 된다.
멤버초기화 리스트의 일반적인 꼴은
(생성자 이름) : var1(arg1), var2(arg2) {}
인데
멤버 변수들을 지칭하는 var1 2 들은
무엇으로 초기화 하는 과정에서
이름이 같아도 오류가 나지 않는다.

단 {
    중괄호로 열어서 한 경우에는 오류가 발생한다.

}

*/

Marine::Marine(int x, int y) : hp(50),
                               coord_x(x),
                               coord_y(y),
                               damage(0),
                               is_dead(false) {}
void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;
}
void Marine::show_status()
{
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : (" << coord_x << "," << coord_y << " )" << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main()
{

    Marine *marines[100];

    marines[0] = new Marine(2, 3);
    marines[1] = new Marine();

    marines[1]->show_status();
    std::cout << "마린1이 마린2을 공격!!" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());
    marines[0]->show_status();
    marines[1]->show_status();
}