#include <iostream>
/*
마린의 수를 세고싶다
그럼 배열을만들까? => 크기가 자유자재로 변하는..
배열을 따로 만들어야된다고? ( 마린이 죽으면 1빼고 살면 1더하고..)

그럼 변수를만들자!
=> 지역변수로 해야되는데 그럼 오류가 생길 가능성 농후하잖아

그렇다면 여기서 static 멤버 변수를 만들자

static / 객체 소멸시 소멸되는 것이 아닌
프로그램이 종료될 때 소멸하는 것

그렇다면 함수도 똑같다

static 함수를 만들면

main 함수에서
marine::show_totoal..() 이렇게 바로 호출이 가능
*/
class Marine
{
    // 그럼 static 을 이용해보자
    static int total_marine_num;
    // 너가 만약 얘를 여기서 초기화해주고싶으면
    //  const를 써줘야 함..
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

    ~Marine() { total_marine_num--; }
};

Marine::Marine()
    : hp(50),
      coord_x(0),
      coord_y(0),
      damage(0),
      is_dead(false)
{
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : hp(50),
      coord_x(x),
      coord_y(y),
      damage(0),
      is_dead(false) { total_marine_num++; }
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