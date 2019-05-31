#pragma once
#include "BanDoc.h"

class SinhVien :
	public BanDoc
{
private:
	string sKhoaHoc;
	string sMaBanDoc;
public:
	SinhVien();
	SinhVien(string sMaBanDoc, string sNgayThamGia, string sHoTen, string sKhoa, string sKhoaHoc);
	~SinhVien();
	string getKhoaHoc();
	void setKhoaHoc(string sKhoaHoc);
	void setMaBanDoc(string sMaBanDoc);
	string getMaBanDoc();

};

