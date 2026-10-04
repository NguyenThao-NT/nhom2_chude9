#include <iostream>
#include <string>
using namespace std;

class TaiKhoan {
private:
    string soTK, hoTen, loaiTK;
    long long soDu;
    double laiSuat;

public:
    TaiKhoan();
    void nhap();
    void xuat();
    string getSoTK();
    long long getSoDu();
    void napTien(long long tien);
    void rutTien(long long tien);
    double tinhLai();
};

TaiKhoan::TaiKhoan() {
    soTK = "";
    hoTen = "";
    loaiTK = "";
    soDu = 0;
    laiSuat = 0;
}

void TaiKhoan::nhap() {
    cin.ignore();

    cout << "So tai khoan: ";
    getline(cin, soTK);

    cout << "Ho ten chu tai khoan: ";
    getline(cin, hoTen);

    cout << "Loai tai khoan: ";
    getline(cin, loaiTK);

    cout << "So du hien tai: ";
    cin >> soDu;

    cout << "Lai suat (%): ";
    cin >> laiSuat;
}

void TaiKhoan::xuat() {
    cout << "So tai khoan: " << soTK << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Loai tai khoan: " << loaiTK << endl;
    cout << "So du: " << soDu << endl;
    cout << "Lai suat: " << laiSuat << "%" << endl;
}

string TaiKhoan::getSoTK() {
    return soTK;
}

long long TaiKhoan::getSoDu() {
    return soDu;
}

void DanhSachTaiKhoan::sapXep() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].getSoDu() < a[j].getSoDu()) {
                TaiKhoan tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
}

int DanhSachTaiKhoan::timKiem(string soTK) {
    for (int i = 0; i < n; i++)
        if (a[i].getSoTK() == soTK)
            return i;

    return -1;
}