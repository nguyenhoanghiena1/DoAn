#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Sach.h"
#include "SinhVien.h"
#include "GiaoVien.h"
#include "PhieuMuon.h"
class GhiXuatDuLieu
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
	int nMaPhieuMuon;
	int swap;
	int nlanChay;
	string sMaBanDoc;
	int sSoSachMuon;
	string sNgayThamGia;
	string sHoTen;
	string sKhoa;
	string sDiaChi;
	string sSDT;
	string sKhoaHoc;
	string DoiSoSangChu(int nSo);
public:
	void XuatDuLieuSach(vector<Sach>& allSach);
	void XuatDuLieuBanDoc(vector<SinhVien>& allSinhVien, vector<GiaoVien>& allGiaoVien);
	GhiXuatDuLieu();
	void GhiPhieuMuon(PhieuMuon &PM);
	void capNhat(vector<Sach> allSach);
	void capNhatPhieuMuon(PhieuMuon& PM, string link, int nTinhTrang);
	void themBanDoc(vector<SinhVien>& allSinhVien, vector<GiaoVien>& allGiaoVien);
	void docPhieuMuon(vector<string> &sach, string sMaBanDoc);
	~GhiXuatDuLieu();
};

