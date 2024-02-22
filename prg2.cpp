#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

tuple<mpz_class, mpz_class, mpz_class> extendedEuclideanAlgo(const mpz_class& x, const mpz_class& y) {
    if (y == 0)  return make_tuple(x, 1, 0);

    mpz_class gcd, x1, y1;
    tie(gcd, x1, y1) = extendedEuclideanAlgo(y, x % y);

    mpz_class y2 = x1 - (x / y) * y1;
    mpz_class x2 = y1;

    return make_tuple(gcd, x2, y2);
}

int main(int argc, char* argv[]) {
    mpz_class x(argv[1]);
    mpz_class y(argv[2]);

    mpz_class gcd, x1, y1;
    tie(gcd, x1, y1) = extendedEuclideanAlgo(x, y);
    cout <<x1<<" "<< y1;
    return 0;
}
