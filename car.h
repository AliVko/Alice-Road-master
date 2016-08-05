#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include "additions.h"
#include "msoftcon.h"

const short int CAR_COUNT = 6;
const double KM_PER_CELL = 8.0;
const int BACK_CARS = 25;
const int TRUCKS = 20;

class Road;

class Car {
public:
    Car();
    Car(Point2D, color, Road*, int = 0, double = 0.0, int = 150, int = 10);
    //Car(Point2D, color, int = 0, double = 0.0, int = 150, int = 10);
    virtual ~Car();

    virtual void draw();
    bool isAlive();
    void goRight(int);
    void goLeft(int);
    void goUp(int);
    void goDown(int);

    int getSpeed();
    void killCar();
    void IncreaceSpeed();
    void DecreaceSpeed();
    void extremeBreak();

    double getKM();
    void IncreaceKM(double);

    void goby(Car*);
    bool onMyWay(Car*);
    Point2D getPosition();
    void setPosition(Point2D);
    void setColor(color);
    void move(Direction, int = 1);
    void move(int);
    bool hitOtherCar(Car*);
    color getColor();
    Road* getRoad();
    bool hasLeftObstacle();
    bool hasRightObstacle();
private:
    int maxSpeed;
    int speed;
    int velocity;
    bool alive;
    double km;
protected:
    Point2D oldPosition;
    color col;
    Point2D position;
    Road* road;
};

class Road {
public:
    void draw();
    double getS();
    Road();
    ~Road();

    bool isGood();
    void go();

    void setPlayerCar(Car*);
    Car* getPlayerCar();
    Car* getCar(short int);
    void createCars();

private:
    Car* playerCar;
    Car** cars;
    bool good;
    Car* createCar();
    //* for DEBUG
        unsigned long int ticks;
        unsigned long int crushes;
    //*/
};

class Menu {
    private:
        char color1;
        char color2;

    public:
        Menu(char color1, char color2);
        void getcolor();
        void showline();

        };

#endif // CAR_H_INCLUDED
