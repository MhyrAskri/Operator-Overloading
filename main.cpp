#include <iostream>
#include "MyString.h"

using namespace std;

int main() {

    cout << boolalpha << endl;
    MyString a {"frank"};
    MyString b {"frank"};

    cout << (a == b) << endl;               // true
    cout << (a != b) << endl;               // false

    b = "george";

    cout << (a == b) << endl;               // false
    cout << (a != b) << endl;               // true
    cout << (a < b) << endl;                // true
    cout << (a > b) << endl;                // false

    MyString s1 {"FRANK"};
    s1 = -s1;
    cout << s1 << endl;                     // frank

    s1 = s1 + "*****";
    cout << s1 << endl;                     // frank*****

    s1 += "-----";
    cout << s1 << endl;                     // frank*****-----

    MyString s2 {"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;                     // 123451234512345

    MyString s3 {"abcdef"};
    s3 *= 5;
    cout << s3 << endl;                     // abcdefabcdefabcdefabcdefabcdef

    MyString repeatString;
    int repeatTimes;
    cout << "Enter a string to repeat:" << endl;
    cin >> repeatString;
    cout << "How many time would you like to repeated?" << endl;
    cin >> repeatTimes;
    cout << "The result string is: " << (repeatString *= repeatTimes) << endl;

    cout << "\nYour string * your repeated times * 12:\n" << (repeatString * 12) << endl << endl;

    repeatString = "RepeatMe";
    cout << (repeatString + repeatString + repeatString) << endl;       // RepeatMeRepeatMeRepeatMe

    repeatString += (repeatString * 3);
    cout << repeatString << endl;           // RepeatMeRepeatMeRepeatMeRepeatMe

    MyString s = "Frank";
    ++s;
    cout << s << endl;                      // FRANK

    s = -s;
    cout << s << endl;                      // frank

    MyString result;
    result = ++s;
    cout << s << endl;                      // FRANK
    cout << result << endl;                 // FRANK

    s = "Frank";
    s++;
    cout << s << endl;                      // FRANK

    s = -s;
    cout << s << endl;                      // frank
    result = s++;
    cout << s << endl;                      // FRANK
    cout << result << endl;                 // frank

    return 0;
}