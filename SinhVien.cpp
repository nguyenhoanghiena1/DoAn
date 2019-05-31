#include "SinhVien.h"



SinhVien::SinhVien()
{
}

SinhVien::SinhVien(string sMaBanDoc, string sNgayThamGia, string sHoTen, string sKhoa, string sKhoaHoc)
{
	this->setMaBanDoc(sMaBanDoc);
	this->setNgayThamGia(sNgayThamGia);
	this->setHoTen(sHoTen);
	this->setKhoa(sKhoa);
	this->sKhoaHoc = sKhoaHoc;
}

SinhVien::~SinhVien()
{
}
void SinhVien::setMaBanDoc(string sMaBanDoc)
{
	this->sMaBanDoc = sMaBanDoc;
}
string SinhVien::getMaBanDoc()
{
	return this->sMaBanDoc;
}
string SinhVien::getKhoaHoc()
{
	return this->sKhoaHoc;
}
void SinhVien::setKhoaHoc(string sKhoaHoc)
{
	this->sKhoaHoc = sKhoaHoc;
}