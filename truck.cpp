#include "truck.h"
#include <stdio.h>

Truck::Truck():Car() {
    setPosition(Point2D(10, 20));

}

//*
Truck::Truck(Point2D position, color col, Road* road, int currentSpeed, double km, int maxSpeed, int velocity):
    Car(position, col, road, currentSpeed, km, maxSpeed, velocity) {
}
//*/

/*
Truck::Truck(Point2D position, color col, int currentSpeed, double km, int maxSpeed, int velocity):
    Car(position, col, currentSpeed, km, maxSpeed, velocity) {
}
//*/

void Truck::draw() {
    set_color(cBLACK);

    set_cursor_pos(oldPosition.x, oldPosition.y);
    printf("   ");
    set_cursor_pos(oldPosition.x+1, oldPosition.y+1);
    printf(" ");
    set_cursor_pos(oldPosition.x, oldPosition.y+2);
    printf("   ");
    set_cursor_pos(oldPosition.x, oldPosition.y+3);
    printf("   ");
    set_cursor_pos(oldPosition.x, oldPosition.y+4);
    printf("   ");

    set_color(this->col);
    if (position.y < 25 && position.y > 0) {
        set_cursor_pos(position.x, position.y);
        printf("%c%c%c",185,178,204);
    }
    if (position.y+1 < 25 && position.y > -1) {
        set_cursor_pos(position.x+1, position.y+1);
        printf("%c",178);
    }
    if (position.y+2 < 25 && position.y > -2) {
        set_cursor_pos(position.x, position.y+2);
        printf("%c%c%c",185,178,204);
    }
    if (position.y+3 < 25 && position.y > -3) {
        set_cursor_pos(position.x, position.y+3);
        printf("%c%c%c",185,178,204);
    }
    if (position.y+4 < 25 && position.y > -4) {
        set_cursor_pos(position.x, position.y+4);
        printf("%c%c%c",185,178,204);
    }
    set_cursor_pos(1,1);
}
