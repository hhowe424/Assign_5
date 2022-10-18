
#include "Array.h"
using namespace std;

int Array::getSize() const {
    return size ;
}
int Array::getNumberOfElements(){
    return nOfElem;
}
int Array::nOfElem = 0;

Array::Array(){
    cout << "default Cons" << endl;
    size = 0;
    ptr = nullptr;
    nOfElem = 0;
}

Array::Array (int num){
    cout << "cons" << endl;
    size = num;
    ptr = new int[size];
    nOfElem = nOfElem + size;
}

Array::Array(const Array& right){
    size = right.size;
    ptr = new int[size];

    for(int i = 0; i < size; i++) {
        ptr[i] = right.ptr[i];
    }
    cout << "copy" << endl;

    nOfElem = nOfElem + size;
}

int& Array::operator[](int i) {
    return ptr[i];
}

ostream& operator<<(ostream& out, const Array& obj) {
    for(int i = 0; i < obj.getSize(); i++) {
        out << obj.ptr[i] << " ";
    }
    out << endl;

    return out;
}

Array& Array::operator=(const Array& right){
    cout << "ass op" << endl;
    if (this != &right) {
        int oldSize = size;
        size = right.size;

        nOfElem = nOfElem - oldSize;
        nOfElem = nOfElem + right.size;

        delete[] ptr;
        ptr = new int[size];

        for (int i = 0; i < size; i++) {
            ptr[i] = right.ptr[i];
        }
    }

    return *this;
}

bool Array::operator==(const Array& right) const {
    if (size >= right.size) {
        for(int i = 0; i < right.size; i++){
            if(ptr[i] != right.ptr[i]){
                return false;
            }
        }
        return true;
    }
    else if (size < right.size) {
        for(int i = 0; i < size; i++){
            if(ptr[i] != right.ptr[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Array::operator<(const Array& right) const{
    int allSame = 0;

    if (size <= right.size) {
        for(int i = 0; i < size; i++){
            if(ptr[i] > right.ptr[i]){
                return false;
            }
            else if(ptr[i] == right.ptr[i]){
                allSame += 1;
            }
        }
        if(allSame == size) {
            return false;
        }
        else
            return true;
    }
    else if (size > right.size) {
        for(int i = 0; i < right.size; i++){
            if(ptr[i] > right.ptr[i]){
                return false;
            }
            else if(ptr[i] == right.ptr[i]){
                allSame += 1;
            }
        }
        if(allSame == right.size) {
            return false;
        }
        else
            return true;
    }
    return false;
}

Array& Array::operator+=(const Array& right){
    int newSize = right.size + size;
    int oldSize = size;
    size = newSize;

    for(int i = 0; i < newSize; i++){
        static int j = oldSize;
        ptr[j] = right.ptr[i];
        j++;
    }

    nOfElem = nOfElem + right.size;

    return *this;
}

Array Array::operator!() {
    srand(time(nullptr));
    int temp;
    int x1, y1;

    for (int i = 0; i < size; i++) {
        y1 = rand() % size;
        x1 = rand() % size;

        temp = ptr[x1];
        ptr[x1] = ptr[y1];
        ptr[y1] = temp;
    }

    return *this;
}

Array Array::operator*(){
    int* minPtr = ptr;

    for(int i = 0; i < size; i++){
        if(*minPtr > ptr[i])
            *minPtr = ptr[i];
        minPtr++;
    }
    cout << *minPtr;

    return *minPtr;
}

Array Array::operator++(int){
    Array temp = *this;

    for(int i = 0; i < size; i++)
        ++ptr[i];

    return temp;
}

Array Array::operator--(){
    for(int i = 0; i < size; i++)
        --ptr[i];

    return *this;
}

Array::~Array() {
    delete[] ptr;
    ptr = nullptr;
    cout << "destructor" << endl;

    nOfElem = nOfElem - size;
}

