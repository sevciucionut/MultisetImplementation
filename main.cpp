#include <iostream>
#include <set>
#include <iterator>
#include "Multiset.h"

using namespace std;

template<size_t N, class T>
bool throws_get(Multiset<T> &mset) {
    try {
        mset[N];
        return false;
    } catch (exception e) {
        return true;
    }
}


int main() {

    Multiset<int> a;
    a.add(3);
    a.add(5);
    assert(a[1] == 5);
    a.eliminare(3);
    assert(!a.aparitii(3));
    assert(a[0] == 5);

    Multiset<int> b;
    b = a;
    assert(b.aparitii(5));
    b.Sterge(5);
    assert(b.SizeT() == 0);

    Multiset<int> c(b);
    c.add(2);
    c.add(2);
    c.eliminare(2);
    assert(!c.apartenenta(2));
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(3);
    cout << "Elementele lui c sunt:\n";
    cout << c << endl;
    //cout<<"Nr elem dist: ";
    //int aa = c.nrElemDist();//cateodata imi dadea eroare, cateodata mergea bine
    //cout<<aa;

    Adaugare x(5);
    c.Transform(x);
    cout << endl << c;

    c.Clear();
    assert(c.SizeT() == 0);
    assert(!throws_get<0>(c));//il are pe NULL

}