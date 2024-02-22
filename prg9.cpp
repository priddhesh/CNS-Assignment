#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

void findOrder(const mpz_class& a, const mpz_class& m) {
    mpz_class order = 1;
    mpz_class temporary = a;
    while (temporary != 1) {
        temporary = (temporary * a) % m;
        order += 1;
    }
    cout << order;
}

int main(int argc, char* argv[]) {
    mpz_class c(argv[1]), v(argv[2]);
    findOrder(c, v);
    return 0;
}
