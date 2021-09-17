#ifndef OPERATOROVERLOADING_MYSTRING_H
#define OPERATOROVERLOADING_MYSTRING_H

#include <iostream>

class MyString {

private:

    char *str;      // pointer to a char[] that hold a c-style string

public:

    MyString();                             // no-args constructor
    MyString(const char *s);                // overloaded constructor
    MyString(const MyString &source);       // copy constructor
    MyString(MyString &&source);            // move constructor
    ~MyString();                            // destructor

    MyString &operator=(const MyString &rhs);   // copy assignment
    MyString &operator=(MyString &&rhs);        // move assignment

    void display() const;       // display

    int getLength() const;          // string length getter
    const char *getStr() const;     // string's value getter

    // overloaded operator non-member methods
    friend std::ostream &operator<<(std::ostream &os , const MyString &rhs);
    friend std::istream &operator>>(std::istream &is , MyString &rhs);
    friend MyString operator-(const MyString &obj);                             // make lowercase
    friend MyString operator+(const MyString &lhs , const MyString &rhs);       // concatenate
    friend bool operator==(const MyString &lhs , const MyString &rhs);          // equals
    friend bool operator!=(const MyString &lhs , const MyString &rhs);          // not equals
    friend bool operator<(const MyString &lhs , const MyString &rhs);           // less than
    friend bool operator>(const MyString &lhs , const MyString &rhs);           // greater than
    friend MyString &operator+=(MyString &lhs , const MyString &rhs);           // concat & assign
    friend MyString operator*(const MyString &lhs , int n);                     // repeat string for 'n' times
    friend MyString &operator*=(MyString &lhs , int n);                         // a *= 3 ----> a = a * 3 (repeat & assign)
    friend MyString &operator++(MyString &obj);                                 // pre-increment ----> ++a
    friend MyString operator++(MyString &obj , int);                            // post-increment ----> a++
    /*
    // overloaded operator member methods
    MyString operator-() const;                          // make lowercase
    MyString operator+(const MyString &rhs) const;       // concatenate
    bool operator==(const MyString &rhs) const;          // equals
    bool operator!=(const MyString &rhs) const;          // not equals
    bool operator<(const MyString &rhs) const;           // less than
    bool operator>(const MyString &rhs) const;           // greater than
    MyString &operator+=(const MyString &rhs);           // concat & assign
    MyString operator*(int n) const;                     // repeat string for 'n' times
    MyString &operator*=(int n);                         // a *= 3 ----> a = a * 3 (repeat & assign)
    MyString &operator++();                              // pre-increment ----> ++a
    MyString operator++(int);                            // post-increment ----> a++
    */
};


#endif //OPERATOROVERLOADING_MYSTRING_H