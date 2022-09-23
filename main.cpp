#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
class NhanVien
{
    friend void TimKiemTheoTen(int SoNV, NhanVien *nv[]);
    friend class NVSanXuat;
    friend class NVVanPhong;
    friend class NVQuanLy;
private:
    char HoTen[50];
    char NgaySinh[12];
public:
    NhanVien(){};
    virtual ~NhanVien();
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual int TienLuong() = 0;
};

NhanVien::~NhanVien()
{
    delete []HoTen;
    delete []NgaySinh;
}

class NVQuanLy:public NhanVien
{
private:
	int LuongCoBan, HeSoChucVu, Thuong;
public:
    void Nhap();
    void Xuat();
    int TienLuong();
    NVQuanLy(){};
    ~NVQuanLy();
};

void NVQuanLy::Nhap()
{
    cout << "Nhap ten nhan vien: ";
    fflush(stdin);
    gets(HoTen);
    cout << "Nhap ngay thang nam sinh: ";
    fflush(stdin);
    gets(NgaySinh);
    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
    cout << "Nhap he so chuc vu: ";
    cin >> HeSoChucVu;
    cout << "Nhap muc thuong: ";
    cin >> Thuong;
}

void NVQuanLy::Xuat()
{
    cout << "Nhan vien quan ly:\n";
    cout << "Ho Ten: "; puts(HoTen);
    cout << "Ngay sinh: "; puts(NgaySinh);
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "He so chuc vu: " << HeSoChucVu << endl;
    cout << "Muc thuong: " << Thuong << endl;
}

int NVQuanLy::TienLuong()
{
    return LuongCoBan*HeSoChucVu + Thuong;
}

NVQuanLy::~NVQuanLy()
{
    delete[]HoTen;
    delete[]NgaySinh;
}

class NVSanXuat:public NhanVien
{
protected:
    int SoSanPham, LuongCoBan;
public:
    void Nhap();
    void Xuat();
    int TienLuong();
    NVSanXuat(){};
    ~NVSanXuat();
};


void NVSanXuat::Nhap()
{
        cout << "Nhap ten nhan vien: ";
        fflush(stdin);
        gets(HoTen);
        cout << "Nhap ngay thang nam sinh: ";
        fflush(stdin);
        gets(NgaySinh);
        cout << "Nhap luong co ban: ";
        cin >> LuongCoBan;
        cout << "Nhap so san pham: ";
        cin >> SoSanPham;
}

void NVSanXuat::Xuat()
{
    cout << "Nhan vien san xuat:\n";
    cout << "Ho Ten: "; puts(HoTen);
    cout << "Ngay sinh: "; puts(NgaySinh);
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "So san pham: " << SoSanPham << endl;
}

int NVSanXuat::TienLuong()
{
    return LuongCoBan + SoSanPham*2000;
}

NVSanXuat::~NVSanXuat()
{
    delete[]HoTen;
    delete[]NgaySinh;
}

class NVVanPhong:public NhanVien
{
private:
	int LuongCoBan, SoNgayLamViec, TroCap;
public:
    void Nhap();
    void Xuat();
    int TienLuong();
    NVVanPhong(){};
    ~NVVanPhong(void);
};


void NVVanPhong::Nhap()
{
	cout << "Nhap ten nhan vien: ";
    fflush(stdin);
    gets(HoTen);
    cout << "Nhap ngay thang nam sinh: ";
    fflush(stdin);
    gets(NgaySinh);
	cout << "Nhap luong co ban: ";
	cin >> LuongCoBan;
	cout << "Nhap ngay lam viec: ";
	cin >> SoNgayLamViec;
	cout << "Nhap muc tro cap: ";
	cin >> TroCap;
}

void NVVanPhong::Xuat()
{
    cout << "Nhan vien van phong:\n";
	cout << "Ho Ten: "; puts(HoTen);
    cout << "Ngay sinh: "; puts(NgaySinh);
	cout << "Luong co ban: " << LuongCoBan << endl;
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
	cout << "Muc tro cap: " << TroCap << endl;
}

int NVVanPhong::TienLuong()
{
	return LuongCoBan + SoNgayLamViec*100000 + TroCap;
}

NVVanPhong::~NVVanPhong()
{
	delete[]HoTen;
	delete[]NgaySinh;
}

void NhapNVCTY(int &SoNV, NhanVien *nv[])
{
    cout << "nhap so nhan vien : ";
    cin >> SoNV;
    cout << " 1. nhan vien van phong." << endl;
    cout << " 2. nhan vien san xuat." << endl;
    cout << " 3. nhan vien quan ly." << endl;
    for (int i = 0; i < SoNV; i++)
    {
        int t;
        cout << "\nChon : ";
        cin >> t;
        if (t == 1)
        {
            cout << "nhan vien van phong" << endl;
            nv[i] = new NVVanPhong;
        }
        if (t == 2)
        {
            cout << "nhan vien san xuat" << endl;
            nv[i] = new NVSanXuat;
        }
        if (t == 3)
        {
            cout << "nhan vien san xuat" << endl;
            nv[i] = new NVQuanLy;
        }
        nv[i]->Nhap();

    }
}

void XuatNVCTY(int SoNV, NhanVien *nv[])
{
    cout << endl << "Danh Sach Nhan Vien Cong Ty: " << endl;
    for (int i = 0; i < SoNV; i++)
    {
        cout << "\n";
        nv[i]->Xuat();
        cout << "Tien luong: " << nv[i]->TienLuong()<<endl;
    }
}

int TongLuong (int SoNV, NhanVien *nv[])
{
    int s = 0;
    for (int i = 0; i < SoNV; i++)
    {
        s = s + (nv[i]->TienLuong());
    }
    return s;
}

void TimKiemTheoTen (int SoNV, NhanVien *nv[])
{
    char mHoTen[50];
    int dem = 0;
    cout <<"\n\nNhap ten nhan vien can tim kiem: ";
    fflush(stdin);
    gets(mHoTen);
    cout << "Ket qua tim kiem: \n";
    for (int i = 0; i < SoNV; i++)
    {
        if (strcmp(mHoTen,nv[i]->HoTen) == 0 )
        {
            nv[i]->Xuat();
            break;
        }
        else
        {
            ++dem;
        }
    }
    if (dem == (SoNV))
        cout << "Khong tim thay.";
}

int main()
{
    int SoNV;
    NhanVien *nv[100];
    NhapNVCTY(SoNV, nv);
    XuatNVCTY(SoNV, nv);
    cout << "\nTong luong cong ty phai tra la: " << TongLuong(SoNV,nv);
    TimKiemTheoTen(SoNV, nv);
    return 0;
}
