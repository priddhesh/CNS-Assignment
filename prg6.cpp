#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

void findModInverse(mpz_class x, mpz_class y) {
    mpz_class res;
    mpz_gcd(res.get_mpz_t(), x.get_mpz_t(), y.get_mpz_t());
    if (res != 1)
        cout << "N";
    else {
        mpz_invert(res.get_mpz_t(), x.get_mpz_t(), y.get_mpz_t());
        cout << "Y " << res;
    }
}
int main(int argc, char* argv[]) {
    mpz_class x(argv[1]), y(argv[2]);
    findModInverse(x, y);
    return 0;
}
