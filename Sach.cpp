#include "Sach.h"



Sach::Sach()
{

}

Sach::Sach(string sMaSach, string sTuaDe, string sTacGia, string sNXB, double dTriGia, int nNam, int nSoTrang, string sNgayNhap,int MaPhieuMuon)
{
	this->sMaSach = sMaSach;
	this->sTuaDe = sTuaDe;
	this->sTacGia = sTacGia;
	this->sNXB = sNXB;
	this->dTriGia = dTriGia;
	this->nNam = nNam;
	this->nSoTrang = nSoTrang;
	this->sNgayNhap = sNgayNhap;
	this->MaPhieuMuon = MaPhieuMuon;
}

Sach::~Sach()
{

}

string Sach::getMaSach()
{
	return this->sMaSach;
}

string Sach::getTuaDe()
{
	return this->sTuaDe;
}

string Sach::getTacGia()
{
	return this->sTacGia;
}

string Sach::getNXB()
{
	return this->sNXB;
}

double Sach::getTriGia()
{
	return this->dTriGia;
}

int Sach::getNam()
{
	return this->nNam;
}

int Sach::getSoTrang()
{
	return this->nSoTrang;
}

string Sach::getNgayNhap()
{
	return this->sNgayNhap;
}

int Sach::getMaPhieuMuon()
{
	return this->MaPhieuMuon;
}

void Sach::setMaSach(string sMaSach)
{
	this->sMaSach = sMaSach;
}

void Sach::setTuaDe(string sTuaDe)
{
	this->sTuaDe = sTuaDe;
}

void Sach::setTacGia(string sTacGia)
{
	this->sTacGia = sTacGia;
}

void Sach::setNXB(string sNXB)
{
	this->sNXB = sNXB;
}

void Sach::setTriGia(double dTriGia)
{
	this->dTriGia = dTriGia;
}

void Sach::setNam(int nNam)
{
	this->nNam = nNam;
}

void Sach::setSoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}

void Sach::setNgayNhap(string sNgayNhap)
{
	this->sNgayNhap = sNgayNhap;
}

void Sach::setMaPhieuMuon(int MaPhieuMuon)
{
		this->MaPhieuMuon = MaPhieuMuon;
}
