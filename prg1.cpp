#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class findGCD(mpz_class x, mpz_class y) {
    while (y != 0) {
        mpz_class temporary = y;
        y = x % y;
        x = temporary;
    }
    return x;
}

mpz_class findCommonDivisor(const vector<mpz_class>& arr) {
    if (arr.empty()) return 0;
    mpz_class res = arr[0];
    int n = arr.size();

    for (size_t i = 1; i < n; i++) {
        res = findGCD(res, arr[i]);
    }

    return res;
}

void printDivisors(mpz_class n) {
    for (mpz_class i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if(i!=n){
            cout << i << " ";
            }else{
                cout<<i;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int numCount = atoi(argv[1]); 
    vector<mpz_class> vec;
    vector<mpz_class>val;
    for (int i = 2; i < argc; ++i) { 
        mpz_class num(argv[i]);
        val.push_back(num);
        vec.push_back(num);
    }

    mpz_class cd = findCommonDivisor(val);
    printDivisors(cd);
    return 0;
}
