#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include "PhieuMuon.h"
#include "Sach.h"
#include "SinhVien.h"
#include "GiaoVien.h"
#include "GhiXuatDuLieu.h"
#include <Windows.h>
#include "HienThi.h"
#include <sstream>

using namespace std;
class QuanLy
{
public:
	QuanLy();
	void QuanLyMK(int &nID, int nDem);
	void TaoPhieuMuon(vector<SinhVien> SV, vector<GiaoVien> GV, vector<Sach>& Sach);
	void CapNhatPhieuMuon(vector<Sach>& Sa);
	void themSachMoi(vector<Sach>& Sa);
	void xoaSach(vector<Sach>& Sa);
	void themBanDoc(vector<SinhVien> &SV, vector<GiaoVien> &GV);
	void thongKe(vector<SinhVien> SV, vector<GiaoVien> GV, vector<Sach> Sach);
	~QuanLy();
};

