#include <iostream>
using namespace std;
int main() {
    int col;
    string s;
    char result[100][20];
    while (cin >> col && col != 0) {
        cin >> s;
        int row = 0;
        int index  =0;
        //将字符串映射到一个二维数组
        while (index < s.length()) {
           if (row % 2 == 0) {
               for (int i = 0; i < col; i++)
                   result[row][i] = s[index++];
           } else {
               for (int i = col - 1; i >= 0; i--)
                    result[row][i] = s[index++];
           }
           row++;
        }

        //输出解密之后的字符串
        for (int i = 0; i < col; i++)
            for (int j = 0; j < row; j++)
                cout << result[j][i];
        cout << endl;
    }
}
