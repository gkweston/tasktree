#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abbc";
    string ss = "abb";
    ss += (char)((int)(s[s.size() - 1]) + 1);
    cout << "s: " << s << endl;
    cout << "ss: " << ss << endl;

    char a = 'A';
    for (int i = 0; i < 100; ++i) {
        cout << a++ << endl;
    }
}