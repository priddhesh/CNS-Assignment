#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

bool checkPrimitiveRoot(const mpz_class& a, const mpz_class& m) {
    mpz_class power = 1;
    mpz_class eulerPHI = m - 1;
    vector<bool> vis(eulerPHI.get_ui() + 1, false);

    for (mpz_class i = 0; i < eulerPHI;i++) {
        power = (power * a) % m;
        if (vis[power.get_ui()]){
            return false;
        }
        vis[power.get_ui()] = true;
    }
    return true;
}

void findPrimitiveRoots(const mpz_class& m) {
    vector<mpz_class> primitiveRoots;
    mpz_class eulerPHI = m - 1;

    for (mpz_class a = 2; a < m; ++a) {
        if (checkPrimitiveRoot(a, m)) {
            primitiveRoots.push_back(a);
        }
    }
    cout<< primitiveRoots.size() <<" ";
    for (int i = 0;i<primitiveRoots.size();i++) {
        if(i==primitiveRoots.size()-1){
          cout << primitiveRoots[i];
        }else{
            cout<<primitiveRoots[i]<<" ";
        }
    }
}

int main(int argc, char* argv[]) {
    mpz_class m(argv[1]);
    findPrimitiveRoots(m);
    return 0;
}
