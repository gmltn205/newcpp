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
    Marine &be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};

Marine::Marine()
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y)
{
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
Marine &Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    if (hp <= 0)
        is_dead = true;

    return *this;
    /* 이 this 또 무슨...
     객체 자기 자신을 가르키는 포인터 역할.
    즉 this->hp -= damage_earn;
    뭐 쨋든 동일해진다.
    */
    if (this->hp < = 0)
        this->is_dead = true;
}
void Marine::show_status()
{
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : (" << coord_x << "," << coord_y << " )" << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main()
{
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std ::endl
              << "marine1 attacks marine2" << std::endl;

    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}