#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PhieuMuon
{
	/*
	2.	Phiếu mượn gồm các thông tin sau: Số thứ tự phiếu mượn, Mã giáo viên hoặc Mã Sinh viên, ngày mượn(lấy ngày hiện tại của hệ thống), ngày 
	phải trả(= ngày mượn +7), tình trạng (đang mượn-1 , đã trả - 0). Số thứ tự phiếu mượn bắt đầu là 1 và tăng dần khi phiếu mượn được tạo.
	*/
private:
	int nSTT;
	string sMaSach;
	string sNgayMuon;
	string sMaBanDoc;
	string sNgayTra;
	int nTinhTrang;
	void DoiNgay(string& ngayMuon, string& ngayTra);
public:
	PhieuMuon();
	~PhieuMuon();
	int getSTT();
	string getNgayMuon();
	string getMaBanDoc();
	string getNgayTra();
	int getTinhTrang();
	string getMaSach();
	void setMaSach(string sMaSach);
	void setNgay();
	void setSTT(int nSTT);
	void setMaBanDoc(string sMaBanDoc);
	void setTinhTrang(int nTinhTrang);
};

