#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
   int test, num_basis;
   int basis[1000], mod[1000];
   string big_integer;
   
   cin >> test;
   while (test--) {
       memset(mod, 0, sizeof(mod));
       cin >> num_basis;
       for (int i = 0; i < num_basis; i++)
           cin >> basis[i];
       cin >> big_integer;
 
       for (int i = 0; i < big_integer.length(); i++) {
          for (int j = 0; j < num_basis; j++) {
              mod[j] = (mod[j] * 10 + big_integer[i] - '0') % basis[j];
          } 
       }
       cout << '(' << mod[0];
       for (int i = 1; i < num_basis; i++) {
           cout << ',' << mod[i];
       }
       cout << ')' << endl;
   }
    
}
