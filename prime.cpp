/**
 *    author:  doublevgp
 *	  Which can not destroy me will make me strong
**/
#include<bits/stdc++.h>
using namespace std;
const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
class RandomNumber {
private:
	unsigned long randSeed;
public:
	RandomNumber(unsigned long s = 0);
	unsigned long Random(unsigned long n);
	double fRandom(void);
};
RandomNumber::RandomNumber(unsigned long s) {
	if (s == 0)
		randSeed = time(0);
	else
		randSeed = s;
}

unsigned long RandomNumber::Random(unsigned long n) {
	randSeed = multiplier * randSeed + adder;
	return (unsigned long)((randSeed >> 16) % n);
}

double RandomNumber::fRandom(void) {
	return Random(maxshort) / double(maxshort);
}
void power(unsigned long a, unsigned long p, unsigned long n, unsigned long &result, bool &composite) {
	unsigned long x;
	if (p == 0)
		result = 1;
	else {
		power(a, p / 2, n, x, composite);
		result = x * x % n;
		if ((result == 1) && (x != 1) && (x != n - 1))
			composite = true;
		if ((p % 2) == 1)
			result = result * a % n;
	}
}
bool PrimeMC(unsigned long n, unsigned int k) {
	RandomNumber rnd;
	unsigned long a, result;
	bool composite = false;
	for (unsigned int i = 1; i <= k; i++) {
		a = rnd.Random(n - 3) + 2;
		// cout << "a = " << a << endl;
		power(a, n - 1, n, result, composite);
		if (composite || (result != 1))
			return false;
	}
	return true;
}
void sol() {
	unsigned long n;
	cin >> n;
	if (PrimeMC(n, 10)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main()
{
	// ios;
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		sol();
	}
	return 0;
}
