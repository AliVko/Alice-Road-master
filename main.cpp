#include <iostream>
#include"additions.h"
#include "user.h"
#include "statictic.h"
#include "car.h"
#include "truck.h"
#include "msoftcon.h"
#include <ctime>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    Menu menu;
    menu.getcolor();
    menu.showline();

    init_graphics();
//*
    Road r;
    Car car(Point2D(20, 20), cRED, &r, 0, 0, 400, 5);
    r.setPlayerCar(&car);
    r.createCars();
    r.go();
//*/


/*
    Car c;
    c.draw();
    Truck t;
    t.draw();
*/
    getch();
    return 0;
}
