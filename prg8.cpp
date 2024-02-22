#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class findGCD(mpz_class a, mpz_class b)
{
	if (a == 0){
		return b;
	}
	return findGCD(b % a, a);
}

mpz_class inverse(mpz_class a, mpz_class m)
{
	mpz_class m0 = m, t, q;
	mpz_class x0 = 0, x1 = 1;

	if (m == 1){
		return 0;
	}
	while (a > 1)
	{
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}
	if (x1 < 0)
		x1 += m0;

	return x1;
}
int main(int argc, char *argv[])
{
	int n = stoi(argv[1]);
	vector<mpz_class> vec1(n);
	vector<mpz_class> vec2(n);
	vector<mpz_class> vec3(n);
	mpz_class product = 1;
	mpz_class result = 0;
	for (int i = 0; i < n; ++i)
	{
		vec1[i] = argv[3 * i + 2];
		vec2[i] = argv[3 * i + 3];
		vec3[i] = argv[3 * i + 4];
	}

	for (int i = 0; i < n; ++i)
	{
		mpz_class gcd = findGCD(vec1[i], vec3[i]);
		vec1[i] = vec1[i] / gcd;
		vec2[i] = vec2[i] / gcd;
		vec3[i] = vec3[i] / gcd;

		mpz_class inv = inverse(vec1[i], vec3[i]);
		vec2[i] = vec2[i] * inv;
	}
	for (int i = 0; i < n; i++){
		product = product * vec3[i];
	}
	for (int i = 0; i < n; i++)
	{
		mpz_class val = product / vec3[i];
		result += vec2[i] * inverse(val, vec3[i]) * val;
	}
	if(result != 0){
		cout << "Y " << result % product;
	} else {
		cout<<"N";
	}
	return 0;
}