#include "additions.h"
#include <string>

using namespace std;

string Email::toString() {
    return userName + '@' + post + '.' + domain;
}

Email::Email() {
    this->userName = "User";
    this->post = "post";
    this->domain = "dom";
}

Email::Email(string userName, string post, string domain) {
    this->userName = userName;
    this->post = post;
    this->domain = domain;
}

Email::Email(string s) {
    if ( Email::charsInString(s, '@') != 1 )
        throw new IncorrectEmail(17); // @ must be 1
    int pos = s.find('@');
    this->userName = s.substr(0, pos);
    s.erase(0, pos+1);

    if ( Email::charsInString(s, '.') ) {
        int pos = s.find('.');
        this->post = s.substr(0, pos);
        s.erase(0, pos+1);
        if (s.length() > 0) {
            this->domain = s;
        }  else
            throw new IncorrectEmail(19); // no domain
    } else
        throw new IncorrectEmail(18); // no post
}

int Email::charsInString(string s, char ch) {
    int n = 0;
    for (size_t i=0; i<s.length(); i++)
        if (s.at(i) == ch) n++;
    return n;
}

IncorrectEmail::IncorrectEmail(unsigned short int code) {
    this->code = code;
}

string IncorrectEmail::getError() {
    return this->Error::getError(this->code);
}

string Error::getError(unsigned short int code) {
    switch ( code ) {
        case 17: return "Count of @ must be 1";
        case 18: return "No post";
        case 19: return "No domain";
        default: return "Unexpected error";
    }
}
