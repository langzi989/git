#include <iostream>
#include <string>
using namespace std;

int main() {
    int test, n;
    string s[101];
    cin >> test;
    while (test--) {
        int count = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
           cin >> s[i]; 
        }
  
        for (int i = 0; i < n; i++) {
            if (s[i] == "") continue;
            for (int j = i + 1; j < n; j++) {
                if (s[i].length() != s[j].length() || s[j] == "")
                     continue;
                int k;
                for (k = 0; k < s[i].length(); k++) {
                    if (!((s[i][k] == 'A' && s[j][k] == 'T')||
                        (s[i][k] == 'C' && s[j][k] == 'G')||
                        (s[i][k] == 'T' && s[j][k] == 'A')||
                        (s[i][k] == 'G' && s[j][k] == 'C')))
                        break;
                }
                if (k == s[i].length() && k != 0) {
                    s[j] = "";
                    count++;
                    break;
                } 
            }
        }
        cout << count << endl;
    }
}
