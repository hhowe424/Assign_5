
#ifndef ASSIGNMENT_5_ARRAY_H
#define ASSIGNMENT_5_ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int* ptr;
    static int nOfElem;
public:
    int getSize() const;
    static int getNumberOfElements();

    Array();
    Array(int num);
    Array(const Array& right);

    Array& operator=(const Array& right);
    friend ostream& operator<<(ostream& out, const Array& obj);
    //friend ostream& operator>>(istream &stream, Array& obj);

    int& operator[](int i);

    bool operator==(const Array& right) const;
    bool operator<(const Array& right) const;
    Array& operator+=(const Array& right);

    Array operator*();
    Array operator++(int);
    Array operator--();
    Array operator!();
    ~Array();
};
ostream& operator<<(ostream& out, const Array& obj);
//ostream& operator>>(istream &stream, Array& obj);

#endif //ASSIGNMENT_5_ARRAY_H
