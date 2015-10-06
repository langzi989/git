/*
求梅森合数
此题目的关键点在于快速分解大数的质因数
本体使用递归方法分解质因数
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int prime[] = {11, 23, 29, 37, 41, 43, 47, 53, 59};
vector<long long> result;
void QFContract(long long target) {
    int temp = (int)pow(target, 0.5) + 1;
    //用来标示此数是不是素数
    bool flag = true;
    //判断此数是不是素数,若不是,则将其两个因子继续分解质因数
    for (int i = 2; i < temp; i++) {
        if (target % i == 0) {
            flag = false;
            QFContract(i);
            QFContract(target / i);
            break;
        }
    }
    if (flag)
        result.push_back(target);
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; prime[i] <= n && i < 10; i++) {
        result.clear();
        long long temp = (long long int)pow(2, prime[i]) - 1;
        QFContract(temp);
        if (result.size() != 1) {
        sort(result.begin(), result.end());
        cout << result[0];
        for (int j = 1; j < result.size(); j++)
            cout << " * " << result[j];
        cout << " = " << temp << " = ( 2 ^ " << prime[i] << " ) - 1" << endl;
        }
    }
}
