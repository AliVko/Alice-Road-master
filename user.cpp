#include "user.h"

User::User() {
    this->name = "Name";
    this->password = "root";
    this->email = Email("email@post.dom");
    this->statistic = Statistic();
}

void User::setName(std::string name) {
    this->name = name;
}

void User::setPassword(std::string password) {
    this->password = password;
}

void User::setEmail(std::string email) {
    this->email = Email(email);
}

void User::setEmail(Email email) {
    this->email = email;
}

void User::resetStatistic() {
    this->statistic.resetScore();
}
