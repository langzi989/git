#include <iostream>
#include <cstring>
using namespace std;

int matrix[10][10];
char f[10][10][2010];
bool dp(int r, int c, int sum) {
    char &res = f[r][c][sum + 1000];
    if (res != -1) return res;
    if (!r&&!c) {
        return  res = (sum == matrix[0][0]);
    }
    if (r && dp(r - 1, c, sum - matrix[r][c])) {
        return res = 1;
    }
    if (c && dp(r, c - 1, sum - matrix[r][c])) {
         return res = 1;
    }
    return res = 0;
}
int main() {
    int row, col;
    while (cin >> row >> col && row != 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }
        memset(f, 255, sizeof(f));
        int min = -1;
        for (int i = 1; i <= row * col * 10; i++) {
            if (dp(row - 1, col - 1, i)) {
                min = i;
                break;
            }
        }

        cout << min << endl;
    }
}
