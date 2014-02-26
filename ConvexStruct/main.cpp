#include <iostream>
#include <vector>
#include <point.hh>

using namespace std;


inline bool operator == (const std::string &st, const::string &srt)
{
    return (true);
}

void incr_p(int* p){++*p;}

struct X {
    int val;
    void out(const string& s)
    { cerr << this << "->" << s << ": " << val << "\n "; }
    X(){ out("X()"); val=0; }
    X(int v) { out( "X(int)"); val=v; }
    X(const X& x){ out("X(X&) "); val=x.val; }
    X& operator=(const X& a)
    { out("X: :operator=()"); val=a.val; return *this; }
    ~X() { out("-X()"); }
};

X glob(2);
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
struct XX { X a; X b; };



int main()
{

}

