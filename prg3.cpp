#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

mpz_class findGCD(mpz_class x, mpz_class y) {
    mpz_class temporary;
    while (y != 0) {
        temporary = y;
        y = x % y;
        x = temporary;
    }
    return x;
}

mpz_class modPowExp(mpz_class base, mpz_class exponent, const mpz_class& modulus) {
    mpz_class res;
    mpz_powm(res.get_mpz_t(), base.get_mpz_t(), exponent.get_mpz_t(), modulus.get_mpz_t());
    return res;
}

mpz_class findRho(mpz_class n) {
    if (n % 2 == 0) return 2;
    mpz_class b = rand() % n + 1;
    mpz_class x = rand() % n + 1, y = x;
    mpz_class a = 1;  

    while (a == 1) {
        x = (modPowExp(x, 2, n) + b + n) % n;
        y = (modPowExp(y, 2, n) + b + n) % n;
        y = (modPowExp(y, 2, n) + b + n) % n;
        a = findGCD(abs(x-y), n);
        if (a == n) return findRho(n);
    }
    return a;
}

void factorize(mpz_class n, vector<mpz_class>& factors) {
    if (n == 1) return;
    if (mpz_probab_prime_p(n.get_mpz_t(), 25) > 0) {
        factors.push_back(n);
        return;
    }
    mpz_class divisors = findRho(n);
    factorize(divisors, factors);
    factorize(n / divisors, factors);
}

int main(int argc, char* argv[]) {
    string input_str(argv[1]);
    mpz_class input(input_str);

    srand(time(0)); 

    vector<mpz_class> factors;
    factorize(input, factors);

    int n = factors.size();

    for (int i = 0;i<n;i++) {
        if(i==n-1){
            cout<<factors[i];
        }else{
            cout << factors[i] << " ";
        }
    }
    return 0;
}
