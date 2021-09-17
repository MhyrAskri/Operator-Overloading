#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os , const MyString &rhs) {

    os << rhs.str;
    return os;

}

// overloaded extraction operator
std::istream &operator>>(std::istream &is , MyString &rhs) {

    char *buff = new char[1000];
    is >> buff;
    rhs = MyString {buff};
    delete [] buff;
    return is;

}

// no-args constructor
MyString::MyString()
    :str {nullptr} {

    str = new char [1];
    *str = '\0';

}

// overloaded constructor
MyString::MyString(const char *s)
    :str {nullptr} {

    if (s == nullptr) {

        str = new char [1];
        *str = '\0';

    } else {

        str = new char [strlen(s) + 1];
        strcpy(str , s);

    }

}

// copy constructor
MyString::MyString(const MyString &source)
    :str {nullptr} {

    str = new char[strlen(source.str) + 1];
    strcpy(str , source.str);

}

// move constructor
MyString::MyString(MyString &&source)
    :str {source.str} {

    source.str = nullptr;

}

// destructor
MyString::~MyString() {

    delete [] str;

}

// copy assignment
MyString &MyString::operator=(const MyString &rhs) {

    if (this == &rhs) {

        return *this;

    }

    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str , rhs.str);
    return *this;

}

// move assignment
MyString &MyString::operator=(MyString &&rhs) {

    if (this == &rhs) {

        return *this;

    }

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;

}

// display method
void MyString::display() const {

    cout << str << " : " << getLength() << endl;

}

// length getter
int MyString::getLength() const {

    return strlen(str);

}

// string getter
const char *MyString::getStr() const {

    return str;

}

// start of overloaded operator non-member methods

// equals
bool operator==(const MyString &lhs , const MyString &rhs) {

    return (strcmp(lhs.str , rhs.str) == 0);

}

// not equals
bool operator!=(const MyString &lhs , const MyString &rhs) {

    return (strcmp(lhs.str , rhs.str) != 0);

}

// less than
bool operator<(const MyString &lhs , const MyString &rhs) {

    return (strcmp(lhs.str , rhs.str) < 0);

}

// greater than
bool operator>(const MyString &lhs , const MyString &rhs) {

    return (strcmp(lhs.str , rhs.str) > 0);

}

// make lowercase
MyString operator-(const MyString &obj){

    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff , obj.str);
    for (size_t i = 0 ; i < strlen(buff) ; i++) {

        buff[i] = tolower(buff[i]);

    }
    MyString temp {buff};
    delete [] buff;
    return temp;

}

// concatenate
MyString operator+(const MyString &lhs , const MyString &rhs) {

    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff , lhs.str);
    strcat(buff , rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;

}

// concat & assign
MyString &operator+=(MyString &lhs , const MyString &rhs) {

    lhs = lhs + rhs;
    return lhs;

}

// repeat
MyString operator*(const MyString &lhs , int n) {

    MyString temp;
    for (int i = 1 ; i <= n ; i++) {

        temp = temp + lhs;

    }
    return temp;

}

// repeat & assign
MyString &operator*=(MyString &lhs , int n) {

    lhs = lhs * n;
    return lhs;

}

// pre-increment (make the string upper-case)
MyString &operator++(MyString &obj) {

    for (size_t i = 0 ; i < strlen(obj.str) ; i++) {

        obj.str[i] = toupper(obj.str[i]);

    }
    return obj;

}

// post-increment (make the string upper-case)
MyString operator++(MyString &obj , int) {

    MyString temp {obj};      // make a copy
    ++obj;               // call pre-increment
    return temp;                // return the old value

}

// end of overloaded operator non-member methods

// start of overloaded operator methods
/*
// equals
bool MyString::operator==(const MyString &rhs) const {

    return (strcmp(str , rhs.str) == 0);

}

// not equals
bool MyString::operator!=(const MyString &rhs) const {

    return (strcmp(str , rhs.str) != 0);

}

// less than
bool MyString::operator<(const MyString &rhs) const {

    return (strcmp(str , rhs.str) < 0);

}

// greater than
bool MyString::operator>(const MyString &rhs) const {

    return (strcmp(str , rhs.str) > 0);

}

// make lowercase
MyString MyString::operator-() const {

    char *buff = new char[strlen(str) + 1];
    strcpy(buff , str);
    for (size_t i = 0 ; i < strlen(buff) ; i++) {

        buff[i] = tolower(buff[i]);

    }
    MyString temp {buff};
    delete [] buff;
    return temp;

}

// concatenate
MyString MyString::operator+(const MyString &rhs) const {

    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff , str);
    strcat(buff , rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;

}

// concat & assign
MyString &MyString::operator+=(const MyString &rhs) {

    *this = *this + rhs;
    return *this;

}

// repeat
MyString MyString::operator*(int n) const {

    MyString temp;
    for (int i = 1 ; i <= n ; i++) {

        temp = temp + *this;

    }
    return temp;

}

// repeat & assign
MyString &MyString::operator*=(int n) {

    *this = *this * n;
    return *this;

}

// pre-increment (make the string upper-case)
MyString &MyString::operator++() {

    for (size_t i = 0 ; i < strlen(str) ; i++) {

        str[i] = toupper(str[i]);

    }
    return *this;

}

// post-increment (make the string upper-case)
MyString MyString::operator++(int) {

    MyString temp (*this);      // make a copy
    operator++();               // call pre-increment
    return temp;                // return the old value

}
*/
// end of overloaded operator methods