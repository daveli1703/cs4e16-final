#include <iostream>
#include <vector>

using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int T;
    cout << "nhập số test case: ";
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cout << "Nhập giá trị cho test case " << t + 1 << ": ";
        cin >> n;

        vector<int> divisors = getDivisors(n);
        cout << "Ước của test case " << t + 1 << ": ";
        for (int divisor : divisors) {
            cout << divisor << " ";
        }
        cout << endl;

       
        cout << "Tổng ước của test case " << t + 1 << ": " << sumOfDivisors(n) << endl;
    }

    return 0;
}