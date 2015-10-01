#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Car{
    int id;
    int start;
    int end;
    int speed;
    float time;
};

bool compare1(Car a, Car b) {
    if (a.start < b.start) return true;
    return false;
}
bool compare2(Car a, Car b) {
    if (a.id < b.id) return true;
    return false;
}

int main() {
    int n;
    int s, e, sp, count = 0;
    Car car[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e >> sp;
        car[count].id = count;
        car[count].start = s;
        car[count].end = e;
        car[count].speed = sp;
        car[count].time = 0.0;
        count++;
    }

    sort(car, car + count, compare1);

   /* for (int i = 0; i < count; i++)
        cout << car[i].id << ' ' << car[i].start << ' '
             << car[i].end << ' ' << car[i].speed << endl;
    */
    car[count - 1].time = (float)(car[count - 1].end - car[count - 1].start) / (float)car[count - 1].speed;
    Car last = car[count - 1];
   // cout << last.id << ' ' << last.start << ' ' << last.end << ' ' << last.speed << endl;
    int i = count - 2;
    int flag = 2;
    while (i) {
        s = car[i].start;
        e = car[i].end;
        sp = car[i].speed;
        if (last.speed >= sp) {
            car[i].time = car[i].time + (float)(e - s) / (float)(sp);
            last = car[i];
            i--;
            flag = 2;
        }  else {
           float t = (float)(e - s) / (float)(sp);
           float position = (float)last.start + (float)(last.speed) * t;
           position = position > last.end ? last.end : position; 
           if (position >= (float)(e)) {
               car[i].time = car[i].time + t;
               last = car[i];
               i--;
               flag = 2;
           } else {   //v[i-1]到达终点前可以追上vi,但是不确定追上vi时v[i-1]是否已经到达终点
               float catch_time = (float)(last.start - s) / (float)(sp - last.speed);
               float catch_position = (float)s + catch_time * (float)sp;
               //追上时已经到达终点
               if (catch_position >= last.end) {
                   car[i].time = car[i].time + (float)(last.end - s) / (float)(sp);
                   car[i].start = last.end;
                   last = car[i + flag];
                   flag++;
               } else {
                   car[i].time = car[i].time + catch_time;
                   if (e <= last.end) {
                       car[i].time = car[i].time + (float)(e - catch_position) / (float)(last.speed);
                       flag = 2;
                       car = car[i];
                       i--;
                   } else {
                       car[i].time = car[i].time + (float)(last.end - catch_position) / (float)(last.speed);
                       car[i].start = last.end;
                       last = car[i + flag];
                       flag++;
                   }
               }
           }
        }
    }

    sort(car, car + count, compare2); 
    for (int i = 0; i < count; i++) {
        cout << fixed << setprecision(2) << car[i].time << endl;
    }
}
