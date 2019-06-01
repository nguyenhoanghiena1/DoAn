#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Sach
{
private:
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNXB;
	double dTriGia;
	int nNam;
	int nSoTrang;
	string sNgayNhap;
	int MaPhieuMuon;


public:
	Sach();
	Sach(string sMaSach, string sTuaDe, string sTacGia, string sNXB, double dTriGia, int nNam, int nSoTrang, string sNgayNhap, int MaPhieuMuon);
	~Sach();

	string getMaSach();
	string getTuaDe();
	string getTacGia();
	string getNXB();
	double getTriGia();
	int getNam();
	int getSoTrang();
	string getNgayNhap();
	void setMaSach(string sMaSach);
	void setTuaDe(string sTuaDe);
	void setTacGia(string sTacGia);
	void setNXB(string sNXB);
	void setTriGia(double dTriGia);
	void setNam(int nNam);
	void setSoTrang(int nSoTrang);
	void setNgayNhap(string sNgayNhap);
	void setMaPhieuMuon(int MaPhieuMuon);
	int getMaPhieuMuon();
};
