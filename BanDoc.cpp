#include "BanDoc.h"



BanDoc::BanDoc()
{
}

BanDoc::~BanDoc()
{
}

string BanDoc::getHoTen()
{
	return this->sHoTen;
}
string BanDoc::getKhoa()
{
	return this->sKhoa;
}

string BanDoc::getNgayThamGia()
{
	return this->sNgayThamGia;
}
void BanDoc::setHoTen(string sHoTen)
{
	this->sHoTen = sHoTen;
}
void BanDoc::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}

void BanDoc::setNgayThamGia(string sNgayThamGia)
{
	this->sNgayThamGia = sNgayThamGia;
}
int BanDoc::getSoSachMuon()
{
	return this->nSoSachMuon;
}
void BanDoc::setSoSachMuon(int nSoSachMuon)
{
	this->nSoSachMuon = nSoSachMuon;
}