#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include "additions.h"
#include "msoftcon.h"
#include "car.h"
#include "truck.h"
//#include "road.h"

class Truck: public Car {
public:
    Truck();
    Truck(Point2D, color, Road*, int = 0, double = 0.0, int = 150, int = 10);
    //Truck(Point2D, color, int = 0, double = 0.0, int = 150, int = 10);
    void draw();
};

#endif // TRUCK_H_INCLUDED
