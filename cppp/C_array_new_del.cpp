#include <iostream>


typedef struct animal{
char name[30];
int age;

int health;
int clean;
int food;

}animal;

void create_animal(animal *animal){

std::cout << "동물의 이름을 지어주세용! : ";
std::cin >> animal->name;

std::cout << " 동물의 나이는 ?  : ";
std::cin >> animal->age;

animal->health=100;
animal->clean=100;
animal->food=100;

}
void play(animal *animal){
    animal->health+=10;
    animal->food-=20;
    animal->clean-=30;

}

void one_day_pass(animal *animal){
    animal->health-=10;
    animal->clean-=20;
    animal->food-=30;
}

void show_stat(animal *animal){
    std::cout << animal->name << "의 상태 : "<<std::endl;
    std::cout << "체력 : " << animal->health << std::endl;
    std::cout << "포만감 : " << animal->food << std::endl;
    std::cout << "청결함 : " << animal->clean << std::endl;
}
int main(){
    animal *list[10];
    int animal_num=0;
    for(;;){
        std::cout <<"1. 동물 추가하기"<<std::endl;
        std::cout <<"2. 놀기"<<std::endl;
        std::cout <<"3. 상태 보기"<<std::endl;
        int input;
        std::cin>>input;
        switch(input){
            case 1:
                list[animal_num]=new animal;
                create_animal(list[animal_num]);

                animal_num++;
                break;
            case 2:
                int who;

                std::cout << "누구랑 놀고싶니?";
                std::cin >> who;

                if(who<animal_num) play(list[who]);
                break;
            case 3:
                int num;
                std::cout << "어떤 동물의 상태를 보고싶니?";
                std::cin>>num;
                if(num<animal_num) show_stat(list[num]);
                break; 

        }
        for(int i=0; i!=animal_num;i++){
            one_day_pass(list[i]);

        }
    }
        for(int i=0;i!=animal_num;i++){
            delete list[i];
        }
    
}