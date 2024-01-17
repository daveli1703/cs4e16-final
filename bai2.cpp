#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    double giave;

public:
    
    Vemaybay() : tenchuyen(""), ngaybay(""), giave(0.0) {}

    Vemaybay(string t, string nb, double gv) : tenchuyen(t), ngaybay(nb), giave(gv) {}

    double getgiave() const {
        return giave;
    }

    void Nhap() {
        cout << "Nhập thông tin vé máy bay:\n";
        cout << "Chuyến bay: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Ngày bay: ";
        getline(cin, ngaybay);
        cout << "Giá vé: ";
        cin >> giave;
    }

    void Xuat() const {
        cout << "Chuyến bay: " << tenchuyen << "\nNgày bay: " << ngaybay << "\nGiá vé: " << giave << endl;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() : hoten(""), gioitinh(""), tuoi(0) {}

    Nguoi(string ht, string gt, int t) : hoten(ht), gioitinh(gt), tuoi(t) {}

    void Nhap() {
        cout << "Nhập thông tin người:\n";
        cout << "Họ tên: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Giới tính: ";
        getline(cin, gioitinh);
        cout << "Tuổi: ";
        cin >> tuoi;
    }

    void Xuat() const {
        cout << "Họ tên: " << hoten << "\nGiới tính: " << gioitinh << "\nTuổi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    Vemaybay *ve;
    int soluong;

public:
    Hanhkhach() : ve(nullptr), soluong(0) {}

    Hanhkhach(string ht, string gt, int t, Vemaybay *v, int sl) : Nguoi(ht, gt, t), ve(v), soluong(sl) {}

    ~Hanhkhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhập số lượng vé máy bay: ";
        cin >> soluong;

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            ve[i].Nhap();
        }
    }

    void Xuat() const {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; ++i) {
            cout << "\nVé thu " << i + 1 << ":\n";
            ve[i].Xuat();
        }
        cout << "Tổng tiền phải trả: " << fixed << setprecision(2) << tongtien() << endl;
    }

    double tongtien() const {
        double total = 0;
        for (int i = 0; i < soluong; ++i) {
            total += ve[i].getgiave();
        }
        return total;
    }
};

int main() {
    int n;
    cout << "Nhập số lượng hành khách: ";
    cin >> n;

    Hanhkhach *danhSachHanhKhach = new Hanhkhach[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhập thông tin hành khách thứ " << i + 1 << ":\n";
        danhSachHanhKhach[i].Nhap();
    }

    sort(danhSachHanhKhach, danhSachHanhKhach + n,
         [](const Hanhkhach &a, const Hanhkhach &b) {
             return a.tongtien() > b.tongtien();
         });

 
    for (int i = 0; i < n; ++i) {
        cout << "\nHành khách thứ " << i + 1 << ":\n";
        danhSachHanhKhach[i].Xuat();
    }

    delete[] danhSachHanhKhach;

    return 0;
}

