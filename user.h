#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>

#include "additions.h"
#include "statictic.h"

using namespace std;

class User {
private:
    string name;
    string password;
    Email email;
    Statistic statistic;
public:
    User();
    void setName(std::string name);
    void setPassword(std::string password);
    void setEmail(std::string email);
    void setEmail(Email email);
    void resetStatistic();
};

#endif // USER_H_INCLUDED
