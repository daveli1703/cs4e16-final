#include <iostream>
#include <string>

using namespace std;

string encodeString(const string& s) {
    string result = "";
    int count = 1;

    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        } else {
            result += s[i] + to_string(count);
            count = 1;
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Nhập sâu: ";
    cin >> s;
    cout << "Sâu đã được mã hóa: " << encodeString(s) << endl;

    return 0;
}