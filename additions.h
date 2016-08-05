#ifndef ADDITIONS_H_INCLUDED
#define ADDITIONS_H_INCLUDED

#include <string>

const int Q = 8;

class Email {
public:
    std::string userName;
    std::string post;
    std::string domain;

    std::string toString();
    Email();
    Email(std::string);
    Email(std::string, std::string, std::string);

private:
    static int charsInString(std::string, char);
};

class Error {
public:
    static std::string getError(unsigned short int);
};

class IncorrectEmail: public Error {
private:
    unsigned short int code;
public:
    IncorrectEmail(unsigned short int);
    std::string getError();
    unsigned short int getCode();
};

struct Point2D {
    int x;
    int y;
    Point2D() {
        x = y = 0;
    }
    Point2D(int X, int Y) {
        x = X;
        y = Y;
    }
};

enum Direction {RIGHT, LEFT, UP, DOWN};

#endif // ADDITIONS_H_INCLUDED
