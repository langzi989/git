#include <iostream>
#include <stack>

using namespace std;
int couple[200001];
int main() {
    int n, husband, wife;
    
    while (cin >> n && n != 0) {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            cin >> husband >> wife;
            couple[husband] = wife;
            couple[wife] = husband;
        }

        for (int i = 1; i <= 2 * n; i++) {
            if (!s.empty()) {
                if (couple[i] == s.top()) s.pop();
                else s.push(i);
            } else {
                s.push(i);
            }
        }
        if (s.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
} 
