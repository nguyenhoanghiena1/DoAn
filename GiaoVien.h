#pragma once
#include "BanDoc.h"

using namespace std;

class GiaoVien:
	public BanDoc
{
private:
	string sDiaChi;
	string sMaBanDoc;
	string sSDT;
public:
	GiaoVien();
	GiaoVien(string sMaBanDoc, string sNgayThamGia, string sHoTen, string sKhoa, string sDiaChi, string sSDT);
	~GiaoVien();

	string getDiaChi();
	string getSDT();
	void setMaBanDoc(string sMaBanDoc);
	string getMaBanDoc();

	void setDiaChi(string sDiaChi);
	void setSDT(string sSDT);
};

