#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getRanking(string s1, string s2) {
    int rank = 0;
    for (int i = 0; i < s1.length(); i++) {
       for (int j = 0; j < s2.find(s1[i]); j++) {
           if (s1.find(s2[j]) > i) {
               rank++;
           }
       } 
    }
    return rank;
}

int getMedianRanking(string s1, string* s, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += getRanking(s1, s[i]);
        //cout << s1 << endl << s[i] << endl;
        //cout << getRanking(s1, s[i]) << endl;
    }
    return total;
}
int main() {
    int n;
    string s[100];
    string result = "ABCDE", target;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int min = 10000000;
        target = result;
        int temp = getMedianRanking(result, s, n);
        min = temp < min ? temp : min;
        while (next_permutation(result.begin(), result.end())) {
             temp = getMedianRanking(result, s, n);
             if (temp < min) {
                 min = temp;
                 target = result;
             }
        }
        cout << target << " is the median ranking with value " << min << '.' << endl;
    }
}
