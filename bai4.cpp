#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSuperPrime(int n) {
    while (n > 0) {
        if (!isPrime(n)) return false;
        n /= 10;
    }
    return true;
}

vector<int> superPrimeNumber(int n) {
    vector<int> result;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i) && isSuperPrime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;

    vector<int> result = superPrimeNumber(n);

    cout << "Số siêu nguyên bé hơn hoặc bằng " << n << ": ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
