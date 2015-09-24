#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int row;
    int col;
    double value;
};

bool compare(node a, node b) {
    if (a.value > b.value)
        return true;
    else if (a.value == b.value) {
        if (a.col - a.row > b.col - b.row)
             return true;
        else if (a.col - a.row == b.col - b.row) {
            if (a.col < b.col) return true;
        }
    }
        
    return false;
}
node result[90001];
int main() {
    
    int n, nq, np, mnq, quarters[301];
    cin >> n;
    
    for (int run = 1; run <= n; run++) {
       cin >> nq >> np >> mnq;
       for (int i = 0; i < nq; i++) {
           cin >> quarters[i];
       }
       int count = 0;
       for (int i = 0; i < nq; i++) {
           int mnq_sum = 0;
           for (int j = i; j < mnq + i - 1 && j < nq; j++) {
               mnq_sum += quarters[j];
           }

           for (int j = i + mnq - 1; j < nq; j++) {
               result[count].row = i;
               result[count].col = j;
               mnq_sum += quarters[j];
               result[count].value =(double)((double) (mnq_sum) / (double)(j - i + 1));
               count++;
           }
       }
       sort(result, result + count, compare);
  
       cout << "Result for run " << run << ":" << endl;
       for (int i = 0; i < np && i < count; i++) {
           cout << result[i].row + 1 << '-' << result[i].col + 1 << endl;
       }

      
    }
}
