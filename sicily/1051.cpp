#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415927
#define INCH 63360
int main() {
    float diameter, time;
    int revolution, count = 1;
    while (cin >> diameter >> revolution >> time&&revolution != 0) {
        float distance = PI * ((float)diameter/ INCH) * (float)revolution;
        float mph = distance / time * 3600;
        cout << "Trip #" << count << ": " << fixed << setprecision(2) << distance << ' ' << mph << endl;
        count++;
    } 
}
