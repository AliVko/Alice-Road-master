#include "car.h"
#include <stdio.h>
#include <cmath>
#include <iostream>

Car::Car() {
    col = cLIGHT_GRAY;
    alive = true;
    maxSpeed = 100;
    velocity = 5;
    speed = 0;
    position.x = 10;
    position.y = 10;
    this->oldPosition = position;
    road = NULL;
}

Car::Car(Point2D position, color col, Road* road, int currentSpeed, double km, int maxSpeed, int velocity) {
//Car::Car(Point2D position, color col, int currentSpeed, double km, int maxSpeed, int velocity) {
    alive = true;
    this->maxSpeed = maxSpeed;
    this->speed = currentSpeed;
    this->velocity = velocity;
    this->col = col;
    this->km = km;
    this->oldPosition = position;
    this->position = position;
    this->road = road;this->
}

void Car::draw() {
    set_color(cBLACK);

    set_cursor_pos(oldPosition.x+1, oldPosition.y);
    printf(" ");
    set_cursor_pos(oldPosition.x, oldPosition.y+1);
    printf("   ");
    set_cursor_pos(oldPosition.x+1, oldPosition.y+2);
    printf(" ");
    set_cursor_pos(oldPosition.x, oldPosition.y+3);
    printf("   ");

    set_color(this->col);
    if (position.y < 25 && position.y > 0) {
        set_cursor_pos(position.x+1, position.y);
        //printf("%c", 202);
        printf("X");
    }
    if (position.y+1 < 25 && position.y > -1) {
        set_cursor_pos(position.x, position.y+1);
        //printf("%c%c%c",185,178,204);
        printf("XXX");
    }
    if (position.y+2 < 25 && position.y > -2) {
        set_cursor_pos(position.x+1, position.y+2);
        printf("X");
    }
    if (position.y+3 < 25 && position.y > -3) {
        set_cursor_pos(position.x, position.y+3);
        //printf("%c%c%c",185,178,204);
        printf("XXX");
    }
    set_cursor_pos(1,1);
}

bool Car::isAlive() {
    return this->alive;
}

void Car::goRight(int n) {
    int x;
    if ((position.x + n) > 42) x = 42;
    else x = position.x + n;
    setPosition( Point2D(x, position.y) );
    draw();
}

void Car::goLeft(int n) {
    int x;
    if ((position.x - n) < 2) x = 2;
    else x = position.x - n;
    setPosition( Point2D(x, position.y) );
    draw();
}

void Car::goUp(int n) {
    setPosition( Point2D(position.x, position.y - n) );
    draw();
}

void Car::goDown(int n) {
    setPosition( Point2D(position.x, position.y + n) );
    draw();
}

void Car::setPosition(Point2D position) {
    this->oldPosition = this->position;
    this->position = position;
    draw();
}

Point2D Car::getPosition() {
    return position;
}

void Car::setColor(color col) {
    this->col = col;
}

void Car::move(Direction dir, int n) {
    switch (dir) {
        case RIGHT: goRight(n); break;
        case LEFT: goLeft(n); break;
        case UP: goUp(n); break;
        case DOWN: goDown(n); break;
        default: break;
    }
}

void Car::move(int d) {
    switch (d) {
        case 0: move(RIGHT); break;
        case 1: move(LEFT); break;
        case 2: move(UP); break;
        case 3: move(DOWN); break;
        default: break;
    }
}

int Car::getSpeed() {
    return this->speed;
}

void Car::IncreaceSpeed() {
    this->speed += velocity;
    if (this->speed > maxSpeed) this->speed = maxSpeed;
}
void Car::DecreaceSpeed() {
    this->speed -= velocity;
    if (this->speed < 0) this->speed = 0;
}

double Car::getKM() {
    return km;
}


void Car::IncreaceKM(double km) {
    this->km += km;
}

void Car::extremeBreak() {
    this->speed = 0;
}

Car::~Car() {
}

bool Car::hitOtherCar(Car* car) {
    int xx = abs(this->position.x - car->getPosition().x);
    int yy = abs(this->position.y - car->getPosition().y);
    return xx < 3 && yy < 4;
}

color Car::getColor() {
    return this->col;
}

void Car::killCar() {
    alive = false;
}

void Car::goby(Car* car) {
    if (car->getPosition().x < 4) {
        if ( !hasRightObstacle() )
            goRight(1);
        else
            DecreaceSpeed();
    }
    else
        if ( !hasLeftObstacle() )
            goLeft(1);
        else
            DecreaceSpeed();
}

bool Car::onMyWay(Car* car) {
    bool b1 = this->getPosition().y > car->getPosition().y;
    return ( b1 && abs(this->position.x - car->getPosition().x) < 4
             && this->speed > car->getSpeed());
}

Road* Car::getRoad() {
    return this->road;
}

bool Car::hasLeftObstacle() {
    for (int i=0; i<CAR_COUNT; i++) {
        Car* car = road->getCar(i);
        if ( car != NULL) {
            int x = position.x - car->getPosition().x;
            int y = abs(position.y - car->getPosition().y);
            return x < 3 && y < 7;
        }
    }
    return false;
}

bool Car::hasRightObstacle() {
    for (int i=0; i<CAR_COUNT; i++) {
        Car* car = road->getCar(i);
        if ( car != NULL) {
            int x = car->getPosition().x - position.x;
            int y = abs(position.y - car->getPosition().y);
            return x < 3 && y < 7;
        }
    }
    return false;
}

Menu::Menu(color1 col1, color2 col2){
    col1 = "red";
    col2 ="green";
}
    void Menu::getcolor(col1, col2){
    col1 = cRED;
    col2 = cDARK_GREEN;
    }

    void Menu::showline(){
        cout << col1 << endl;
        cout << col2;
        return 0;
    }
