#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct panel{
    string state;
    string path;
};
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
int main() {
    int max_step;
    string initial;
    string target;
    while (cin >> max_step && max_step != -1) {
        map<string, int> visited;
        queue<panel> queue1;
        panel initial;
        initial.state = "12348765";
        initial.path = "";
        target = "";
        visited.insert(pair<string, int>("12348765", 1));
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
            //进行Ａ操作
            temp.state = A(front.state);
            temp.path = front.path + 'A';
            if (visited.find(temp.state) == visited.end()) {
                queue1.push(temp);
                visited.insert(pair<string, int>(temp.state, 1));
                if (temp.state == target) 
                    break;
            }
            //进行B操作
            temp.state = B(front.state);
            temp.path = front.path + 'B';
            if (visited.find(temp.state) == visited.end()) {
                queue1.push(temp);
                visited.insert(pair<string, int>(temp.state, 1));
                if (temp.state == target)
                    break;
            }
            //进行C操作
            temp.state = C(front.state);
            temp.path = front.path + 'C';
            if (visited.find(temp.state) == visited.end()) {
                queue1.push(temp);
                visited.insert(pair<string, int>(temp.state, 1));
                if (temp.state == target)
                     break;
            }
            queue1.pop();
        }
        if (queue1.empty()) {
            cout << "-1" << endl;
        } else {
            cout << temp.path.length() << ' ' << temp.path << endl;
        }
    }
}
