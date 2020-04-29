//
// Created by Sevciuc on 20.05.2019.
//

#ifndef POO_TEMA_3_MULTISET_H
#define POO_TEMA_3_MULTISET_H

#include <cstddef>
#include <stdexcept>
#include<iostream>
#include <cassert>

using namespace std;

template<class T>
class Multiset {

    T *multime_;
    int nr_;

    void Copy(const Multiset &other);

public:
    Multiset();

    Multiset(const Multiset &other);

    ~Multiset();

    Multiset &operator=(const Multiset &other);

    void Clear();

    void add(T elem);

    int SizeT() { return nr_; };

    T &operator[](int nr) { return multime_[nr]; };

    void Sterge(T val);

    int aparitii(T elem);

    bool apartenenta(T elem);

    void eliminare(T elem);

    T get_val(int i) { return multime_[i]; }

    int nrElemDist();

    template<class Operation>
    void Transform(Operation op) {
        for (int i = 0; i < nr_; ++i) {
            multime_[i] = op(multime_[i]);
        }
    }
};

class Adaugare {
    int num_;
public:
    Adaugare(int num) : num_(num) {}

    int operator()(int num) { return num + num_; }
};

template<class T>
void Multiset<T>::Copy(const Multiset<T> &other) {
    assert(multime_ == NULL);

    if (other.nr_ == 0) {
        return;
    }

    nr_ = other.nr_;
    multime_ = new T[nr_];

    for (int i = 0; i < nr_; ++i) {
        multime_[i] = other.multime_[i];
    }
}

template<class T>
Multiset<T>::Multiset() : multime_(NULL), nr_(0) {

}

template<class T>
Multiset<T>::Multiset(const Multiset<T> &other) : multime_(NULL), nr_(0) {
    Copy(other);
}

template<class T>
Multiset<T>::~Multiset() {
    delete multime_;
    multime_ = NULL;
    nr_ = 0;
    assert(multime_ == NULL);
}

template<class T>
Multiset<T> &Multiset<T>::operator=(const Multiset<T> &other) {
    if (&other != this) {
        Clear();
        Copy(other);
    }
    return *this;
}

template<class T>
void Multiset<T>::Clear() {
    delete multime_;
    multime_ = NULL;
    nr_ = 0;
    assert(multime_ == NULL);
}

template<class T>
void Multiset<T>::add(T elem) {
    T *aux;
    aux = multime_;
    assert(aux == multime_);

    nr_++;
    multime_ = new T[nr_];

    for (int i = 0; i < nr_ - 1; ++i) {
        multime_[i] = aux[i];
    }

    //multime_[nr_ - 1] = elem;
    multime_[nr_] = NULL;


    int i = 0;
    while (elem > multime_[i] && i != nr_ - 1) {
        i++;
    }

    for (int j = nr_ - 1; j > i; j--) {
        multime_[j] = multime_[j - 1];
    }

    multime_[i] = elem;
}

template<class T>
void Multiset<T>::Sterge(T val) {

    for (int i = 0; i < nr_; i++) {
        if (multime_[i] == val) {
            for (int j = i; j < nr_; j++) {
                multime_[j] = multime_[j + 1];
            }
            nr_--;
        }
    }
    if (nr_ == 0)
        multime_ = NULL;
}

template<class T>
int Multiset<T>::aparitii(T elem) {
    int nr = 0;
    for (int i = 0; i < nr_; ++i) {
        if (multime_[i] == elem)
            nr++;
    }
    return nr;
}

template<class T>
bool Multiset<T>::apartenenta(T elem) {
    for (int i = 0; i < nr_; ++i) {
        if (elem == multime_[i])
            return true;
    }
    return false;
}

template<class T>
void Multiset<T>::eliminare(T elem) {
    int nr = aparitii(elem);
    assert(nr == aparitii(elem));
    for (int i = 0; i < nr; ++i) {
        Sterge(elem);
    }
    if (nr_ == 0) multime_ = NULL;
}

template<class T>
int Multiset<T>::nrElemDist() {
    Multiset<T> aux = *this;
    if(aux.SizeT() == 0) return 0;
    int nr = 1;
    for (int i = 0; i < aux.SizeT() - 1; i++) {
        if (aux.get_val(i) != aux.get_val(i + 1))
        nr++;
    }

    return nr;
}

template<class T>
ostream &operator<<(ostream &os, const Multiset<T> &mset) {
    Multiset<T> aux = mset;
    for (int i = 0; i < aux.SizeT(); i++) {
        os << aux.get_val(i) << " ";
    }
    return os;
}

#endif //POO_TEMA_3_MULTISET_H
