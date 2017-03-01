/*
给定Ｍ＊Ｎ的矩阵，其中的每个元素都是-10到10之间的整数．你的任务是从左上角(1,1)
走到右下角（Ｍ，Ｎ）,每一步只能向右或者向下，并不能走出矩阵的范围．你所经过的方
格里面的数字都必须被选取，请找出一条最适合的道路，使得在路上最选取的数字之和尽可能小的整数，输出最小整数
*/
//this is a test
#include <iostream>
#include <cstring>
using namespace std;

int 5matrix[10][10];
/*
记录中间状态，减少递归次数，在动态规划中常用
用于存储从(0,0)到(row,col)总和为sum能不能走到，初始化为-1，若可到记为１，否则0
*/
char f[10][10][2010];
bool dp(int r, int c, int sum) {
    char &res = f[r][c][sum + 1000];
    //先查询有没有到此状态，若到过则直接输出结果
    if (res != -1) return res;
    //检查是否到(0,0)，此为一个递归条件的结束
    if (!r&&!c) {
        return  res = (sum == matrix[0][0]);
    }
    //若未到达递归结束，查看其左边和上边两个位置是否可到达，递归下去
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
        //由于次题目中的要求的数较小，可从０到最大值遍历得到最小整数
        for (int i = 1; i <= row * col * 10; i++) {
            if (dp(row - 1, col - 1, i)) {
                min = i;
                break;
            }
        }

        cout << min << endl;
    }
}
