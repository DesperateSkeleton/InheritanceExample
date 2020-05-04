// Zad2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "creature.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    animal Cow("Stephen", 1, 10, 5, 0.9);
    villager Shepherd("Jack", 1, 20, 1);
    Cow.print();
    Shepherd.print();
    cout << "Cow VS Shepherd\n" << Shepherd.interaction_possibility(Cow) << endl;
    return 0;
}


