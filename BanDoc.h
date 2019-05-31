#pragma once
#include <iostream>
#include <string>

using namespace std;

class BanDoc
{
private:
	int nSoSachMuon;
	string sNgayThamGia;
	string sHoTen;
	string sKhoa;
public:
	BanDoc();
	~BanDoc();
	string getHoTen();
	string getKhoa();
	int getSoSachMuon();
	void setSoSachMuon(int nSoSachMuon);
	string getNgayThamGia();
	void setHoTen(string sHoTen);
	void setKhoa(string sKhoa);
	void setNgayThamGia(string sNgayThamGia);
};

