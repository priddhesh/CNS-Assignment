#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class ExtendedEuclid(mpz_class a, mpz_class b, mpz_class& x, mpz_class& y) {
    if (b == 0) {
        y = 0;
        x = 1;
        return a;
    } else {
        mpz_class x1, y1;
        mpz_class gcd = ExtendedEuclid(b, a % b, x1, y1);
        y = x1 - (a / b) * y1;
        x = y1;
        return gcd;
    }
}

void findCongruence(mpz_class a, mpz_class b, mpz_class m) {
    mpz_class x, y;
    mpz_class gcd = ExtendedEuclid(a, m, x, y);

    if (b % gcd != 0) {
        cout << "N"; 
        return;
    }
    cout << "Y ";
    cout << gcd << " ";
    mpz_class x0 = (x * (b / gcd)) % m;
    if (x0 < 0) x0 += m;
    for (mpz_class i = 0; i < gcd; i++) {
        mpz_class solution = (x0 + i * (m / gcd)) % m;
        if(i==gcd-1){
          cout << solution;
        }else{
          cout << solution << " ";
        }
    }
}

int main(int argc, char* argv[]) {
    mpz_class a(argv[1]), b(argv[2]), m(argv[3]);
    findCongruence(a, b, m);
    return 0;
}