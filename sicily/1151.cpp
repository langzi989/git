#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

struct panel{
    string state;
    string path;
};

int factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
/*
使用广度优先遍历方法找到目标状态
为方便记录一个状态是否遍历过，使用字符串记录当前魔板的状态
*/
//A操作
string A(string s) {
    string temp = "12345678";
    for (int i = 0; i < 8; i++) {
        temp[i] = s[(i + 4) % 8];
    }
    
    return temp;
}
//B操作
string B(string s) {
    string temp = "12345678";
    char t1 = s[3];
    for (int i = 3; i > 0; i--)
       temp[i] = s[i - 1];
    temp[0] = t1;
    t1 = s[7];
    for (int i = 7;i > 4; i--)
        temp[i] = s[i - 1];
    temp[4] = t1;
    return temp;
}
//C操作
string C(string s) {
    string temp = s;
    temp[6] = s[2];
    temp[2] = s[1];
    temp[1] = s[5];
    temp[5] = s[6];
    return temp;
}

int cantor(string s) {
    int rank = 0, min = 0;
    for (int i = 0; i < 7; i++) {
        min = 0;
        for (int j = i + 1; j < 8; j++) {
            if (s[i] > s[j]) min++;
        }
        rank += min * factorial[8 - i - 1];
    }
    return rank;
}
int main() {
    int max_step;
    string initial;
    string target;
    bool visited[40500];
    while (cin >> max_step && max_step != -1) {
        bool flag = true;
        memset(visited, false, sizeof(visited));
        queue<panel> queue1;
        panel initial;
        initial.state = "12348765";
        initial.path = "";
        target = "";
        visited[cantor(initial.state)] = true;
        int temp_num;
        for (int i = 0; i < 8; i++) {
            cin >> temp_num;
            target = target + char(temp_num + '0');
        }

        //将初始状态压入队列
        queue1.push(initial);
        panel temp;
        while(!queue1.empty()) {
            panel front = queue1.front();
            //特别注意此处搜索深度是否已经超出规定的最大步数max_step
            if (front.path.length() > max_step) {
                flag = false;
            }
            //进行Ａ操作
            temp.state = A(front.state);
            temp.path = front.path + 'A';
            int rank = cantor(temp.state);
            if (visited[rank] == false) {
                queue1.push(temp);
                visited[rank] = true;
                if (temp.state == target) 
                    break;
            }
            //进行B操作
            temp.state = B(front.state);
            temp.path = front.path + 'B';
            rank = cantor(temp.state);
            if (visited[rank] == false) {
                queue1.push(temp);
                visited[rank] = true;
                if (temp.state == target)
                    break;
            }
            //进行C操作
            temp.state = C(front.state);
            temp.path = front.path + 'C';
            rank = cantor(temp.state);
            if (visited[rank] == false) {
                queue1.push(temp);
                visited[rank] = true;
                if (temp.state == target)
                     break;
            }
            queue1.pop();
        }
        if (flag == false) {
            cout << "-1" << endl;
        } else {
            if (queue1.empty()) {
                cout << "-1" << endl;
            } else {
                cout << temp.path.length() << ' ' << temp.path << endl;
            }
        }
    }
}                                 
