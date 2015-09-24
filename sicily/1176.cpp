#include <iostream>

using namespace std;
int sum;
int card[2001];
int dp(int a, int b);
//recorder用来记录之前已经计算过的最大值,避免重复递归计算,以空间换时间
int recorder[1001][1001];
int main() {
    int n, count = 1;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                recorder[i][j] = -1;
        sum = 0;
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> card[i];
            total_sum += card[i];
        }
        sum = dp(0, n - 1);
        cout << "In game " << count << ", the greedy strategy might lose by as many as " << sum - (total_sum -  sum) << " points." << endl;
        count++;
    }
}

int dp(int begin, int end) {
    if (recorder[begin][end] != -1) {
        return recorder[begin][end];
    }
    if (begin >= end) return 0;
    if (end - begin == 1) 
        return card[begin] >= card[end] ? card[begin] : card[end];
    int L = card[begin];
    if (card[begin + 1] >= card[end]) {
        L = L + dp(begin + 2, end);
    } else {
        L = L + dp(begin + 1, end - 1);
    }
    int R = card[end];
    if (card[begin] >= card[end - 1]) {
        R = R + dp(begin + 1, end - 1);
    } else {
        R = R + dp(begin, end - 2);
    }
    //求出最大值之后将其存入recorder中
    recorder[begin][end] = L >= R ? L : R;
    return recorder[begin][end];
}
