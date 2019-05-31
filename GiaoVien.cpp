#include "GiaoVien.h"



GiaoVien::GiaoVien()
{
}

GiaoVien::GiaoVien(string sMaBanDoc, string sNgayThamGia, string sHoTen, string sKhoa, string sDiaChi, string sSDT)
{
	this->setMaBanDoc(sMaBanDoc);
	this->setNgayThamGia(sNgayThamGia);
	this->setHoTen(sHoTen);
	this->setKhoa(sKhoa);
	this->sDiaChi = sDiaChi;
	this->sSDT = sSDT;
}
void GiaoVien::setMaBanDoc(string sMaBanDoc)
{
	this->sMaBanDoc = sMaBanDoc;
}
string GiaoVien::getMaBanDoc()
{
	return this->sMaBanDoc;
}
GiaoVien::~GiaoVien()
{
}


string GiaoVien::getDiaChi()
{
	return this->sDiaChi;
}
string GiaoVien::getSDT()
{
	return this->sSDT;
}

void GiaoVien::setDiaChi(string sDiaChi)
{
	this->sDiaChi = sDiaChi;
}
void GiaoVien::setSDT(string sSDT)
{
	this->sSDT = sSDT;
}