#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(string s1, string s2) {
    if (s1 + s2 <= s2 + s1) return true;
    return false;
}
int main() {
    int test, n;
    string temp;
    cin >> test;
    while (test--) {
        vector<string> vs;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            vs.push_back(temp);
        }
        sort(vs.begin(), vs.end(), compare);
        for (int i = 0; i < vs.size(); i++)
            cout << vs[i];
        cout << endl;
    }
}
