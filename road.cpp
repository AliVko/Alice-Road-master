#include "msoftcon.h"
#include <stdio.h>
#include <ctime>
#include "car.h"
#include "truck.h"
#include "sport.h"

Road::Road() {
    srand(time(NULL));                      // включение генератора случайных чисел
    playerCar = NULL;                       //нулевая стартовая скорость
    cars = new Car*[CAR_COUNT];

    for (int i=0; i<CAR_COUNT; i++)
        cars[i] = NULL;

    //*  for DEBUG
        ticks = CAR_COUNT;
        crushes = 0;
    //*/

    good = true;
    draw();
}

void Road::draw() {
    if (playerCar != NULL) {
        double ss = playerCar->getSpeed() / KM_PER_CELL;
        ss /= 25;
        playerCar->IncreaceKM(ss);

                //*
        for (int i=0; i<CAR_COUNT; i++) {
            double s = cars[i]->getSpeed() / KM_PER_CELL;
            s /= 25;
            cars[i]->IncreaceKM(s);
            double dif = cars[i]->getKM() - playerCar->getKM();
            cars[i]->setPosition( Point2D(
                cars[i]->getPosition().x,
                playerCar->getPosition().y - (int)dif) );

            if ( cars[i]->getPosition().y > 40 || cars[i]->getPosition().y < -25 ) {
                delete cars[i];
                cars[i] = createCar();
                ticks++;
            }

            if ( cars[i]->isAlive() )
                for (int j=0; j<CAR_COUNT; j++) {
                    if ( i==j ) continue;
                    if ( cars[i]->onMyWay(cars[j]) ) {
                        cars[i]->goby(cars[j]);
                    }
                    if ( cars[i]->hitOtherCar(cars[j]) ) {
                        cars[i]->extremeBreak();
                        cars[j]->extremeBreak();
                        cars[i]->setColor(cDARK_GRAY);
                        cars[j]->setColor(cDARK_GRAY);
                        cars[i]->killCar();
                        cars[j]->killCar();

                        /*
                        crushes+=2;
                        set_cursor_pos(50, 4);
                        set_color(cDARK_GRAY);
                        printf("Total:%6ld",ticks);
                        set_cursor_pos(50, 5);
                        printf("Crashes:%6ld",crushes);
                        set_cursor_pos(50, 6);
                        printf("Per:%6.2lf",(double)crushes/ticks*100);
                        //*/
                    }
                }

            if ( playerCar->hitOtherCar(cars[i])) {
                set_cursor_pos(50, 3);
                set_color(cars[i]->getColor());
                printf("CRASH");
            }

            cars[i]->draw();
        }
        //*/

        playerCar->draw();

        set_color(cWHITE);
        char c;
        int seek = (int)playerCar->getKM();
        for (int i=0; i<25; i++) {
            if ( (i + seek) % 8 < 3) c = 219; else c = 32;
            set_cursor_pos(1, 25-i);
            printf("%c",c);
            set_cursor_pos(45, 25-i);
            printf("%c",c);
        }
        set_cursor_pos(79,25);
    }
}

double Road::getS() {
    if (playerCar != NULL)
        return playerCar->getKM();
    else
        throw new Error;
}

void Road::setPlayerCar(Car* playerCar) {
    this->playerCar = playerCar;
}

Car* Road::getPlayerCar() {
    return playerCar;
}

bool Road::isGood() {
    return good;
}

void Road::go() {
    while (good) {

        if (kbhit()) {
            char symbol = getch();
             switch (symbol)
             {
                 case 'w': { playerCar->IncreaceSpeed(); } break;
                 case 's': { playerCar->DecreaceSpeed(); } break;
                 case 'a': { playerCar->goLeft(1); } break;
                 case 'd': { playerCar->goRight(1); } break;
                 case 'b': { playerCar->extremeBreak(); } break;
                 default : break;
             }
        }
        set_cursor_pos(50, 2);
        set_color(cLIGHT_GRAY);
        printf("Speed: %03d", playerCar->getSpeed());
        //* for DEBUG
        //*/
        draw();

        Sleep(30);
        //getch();
    }
}

Car* Road::createCar() {
    int x = rand()%(45-3-2)+2;

    int flag = rand()%100;
    int y;
    if (flag < BACK_CARS) {
        y = rand()%24+1 + 21;
    } else {
        y = rand()%24+1 - 27;
    }

    int c = rand()%5;
    color col;
    switch(c) {
        case 0: col = cBLUE; break;
        case 1: col = cDARK_GREEN; break;
        case 2: col = cDARK_MAGENTA; break;
        case 3: col = cDARK_RED; break;
        case 4: col = cDARK_CYAN; break;
        default: col = cBROWN;
    }

    int speed = rand()%200 + 50;
    double km = playerCar->getKM() + (playerCar->getPosition().y - y);

    flag = rand()%100;
    Car* tmpCar;
    if (flag < TRUCKS) {
        tmpCar = new Truck(Point2D(x, y), col, this, speed, km);
    } else {
        tmpCar = new Car(Point2D(x, y), col, this, speed, km);
    }
    return tmpCar;
}

Road::~Road() {
    delete [] cars;
}

Car* Road::getCar(short int number) {
    if ( number >= CAR_COUNT || number < 0 )
        return NULL;
    else
       return cars[number];
}

void Road::createCars() {
    for (int i=0; i<CAR_COUNT; i++) {
        if ( cars[i] == NULL )
            cars[i] = createCar();
    }
}
