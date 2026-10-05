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

void TaiKhoan::napTien(long long tien) {
    if (tien > 0)
        soDu += tien;
}

void TaiKhoan::rutTien(long long tien) {
    if (tien > 0 && tien <= soDu)
        soDu -= tien;
}

double TaiKhoan::tinhLai() {
    return soDu * laiSuat / 100;
}

void TaiKhoan::napTien(long long tien) {
    if (tien > 0)
        soDu += tien;
}

void TaiKhoan::rutTien(long long tien) {
    if (tien > 0 && tien <= soDu)
        soDu -= tien;
}

double TaiKhoan::tinhLai() {
    return soDu * laiSuat / 100;
}
class DanhSachTaiKhoan {
private:
    TaiKhoan a[200];
    int n;

public:
    DanhSachTaiKhoan();
    DanhSachTaiKhoan(const DanhSachTaiKhoan& ds);
    void nhapDanhSach();
    void xuatDanhSach();
    void xuatMotTaiKhoan(int viTri);
    void sapXep();
    int timKiem(string soTK);
    void themTaiKhoan(int viTri);
    void xoaTaiKhoan(int viTri);
};

DanhSachTaiKhoan::DanhSachTaiKhoan() {
    n = 0;
}

DanhSachTaiKhoan::DanhSachTaiKhoan(const DanhSachTaiKhoan& ds) {
    n = ds.n;
    for (int i = 0; i < n; i++)
        a[i] = ds.a[i];
}

void DanhSachTaiKhoan::nhapDanhSach() {
    do {
        cout << "Nhap so luong tai khoan (0 < n < 200): ";
        cin >> n;
    } while (n <= 0 || n >= 200);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Tai khoan thu " << i + 1 << " ---\n";
        a[i].nhap();
    }
}

void DanhSachTaiKhoan::xuatDanhSach() {
    if (n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Tai khoan thu " << i + 1 << " ---\n";
        a[i].xuat();
    }
}