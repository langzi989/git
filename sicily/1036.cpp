#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string keyword;
    string cophertext;
    int col, row, index;
    char result[100][10];
    while (cin >> keyword && keyword != "THEEND") {
        cin >> cophertext;
        index = 0;
        col = keyword.length();
        row = cophertext.length() / col;
        string temp = keyword;
        sort(temp.begin(), temp.end());
        //将字符串映射到二维数组
        for (int i = 0; i < temp.length(); i++) {
            for (int j = 0; j < temp.length(); j++) {
                if (temp[i] == keyword[j]) {
                    for (int k = 0; k < row; k++)
                        result[k][j] = cophertext[index++];
                    keyword[j] = '0';
                }
            }
        }
        //输出
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                 cout << result[i][j];
        cout << endl;
    }
}
