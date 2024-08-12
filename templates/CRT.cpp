#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    int m0 = m, y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

int chineseRemainderTheorem(const vector<int>& num, const vector<int>& rem) {
    int prod = 1;
    int result = 0;
    for (int n : num)
        prod *= n;
    for (size_t i = 0; i < num.size(); i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    // Example: x ≡ 2 (mod 3), x ≡ 3 (mod 5), x ≡ 2 (mod 7)
    vector<int> num = {3, 6, 7}; // Moduli
    vector<int> rem = {2, 1, 2}; // Remainders
    int result = chineseRemainderTheorem(num, rem);

    cout << "x is " << result << endl;

    return 0;
}