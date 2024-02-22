#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

void solve(const mpz_class& a, const mpz_class& x, const mpz_class& n, mpz_class& res) {
    res = mpz_class(1);

    mpz_class exponent;
    exponent = x % n;

    mpz_powm_ui(res.get_mpz_t(), a.get_mpz_t(), exponent.get_ui(), n.get_mpz_t());
    cout<<res;
}

int main(int argc, char* argv[]) {
    mpz_class a(argv[1]), b(argv[2]), c(argv[3]);
    mpz_class res;

    solve(a, b, c, res);

    return 0;
}
