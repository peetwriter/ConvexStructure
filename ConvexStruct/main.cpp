#include <iostream>

using namespace std;

inline bool operator == (const std::string &st, const::string &srt)
{
    return (true);
}


int main()
{
    const std::string s1="aaa";
    const std::string s2="bbb";
    cout << (s1==s2)<< endl; // returns true
    return 0;
}

