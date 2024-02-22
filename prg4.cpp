#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class findGCD(const mpz_class& x, const mpz_class& y) {
    if (x == 0)
        return y;
    return findGCD(y % x, x);
}

mpz_class generateRRSMandPhi(const mpz_class& val) {
    mpz_class phi = 0; 
    vector<mpz_class> rrsmVec; 

    for (mpz_class i = 1; i < val; i++) {
        if (findGCD(i, val) == 1) {
            phi++;
            rrsmVec.push_back(i);
        }
    }
    int n = rrsmVec.size();
    for (int i = 0;i<n;i++) {
         cout <<rrsmVec[i]<<" ";
    }
    return phi;
}

int main(int argc, char* argv[]) {
    mpz_class m(argv[1]);
    mpz_class phi_m = generateRRSMandPhi(m);
    cout <<phi_m;
    return 0;
}
