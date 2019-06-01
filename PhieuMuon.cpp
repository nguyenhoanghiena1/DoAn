#include "PhieuMuon.h"



PhieuMuon::PhieuMuon()
{
}


PhieuMuon::~PhieuMuon()
{
}

int PhieuMuon::getSTT()
{
	return this->nSTT;
}
string PhieuMuon::getNgayMuon()
{
	return this->sNgayMuon;
}
string PhieuMuon::getMaBanDoc()
{
	return this->sMaBanDoc;
}
string PhieuMuon::getNgayTra()
{
	return this->sNgayTra;
}
int PhieuMuon::getTinhTrang()
{
	return this->nTinhTrang;
}
string PhieuMuon::getMaSach()
{
	return this->sMaSach;
}
void PhieuMuon::setMaSach(string sMaSach)
{
	this->sMaSach = sMaSach;
}
void PhieuMuon::setNgay()
{
	DoiNgay(this->sNgayMuon, this->sNgayTra);
}
void PhieuMuon::setMaBanDoc(string sMaBanDoc)
{
	this->sMaBanDoc = sMaBanDoc;
}

void PhieuMuon::setTinhTrang(int nTinhTrang)
{
	this->nTinhTrang = nTinhTrang;
}

void PhieuMuon::setSTT(int nSTT)
{
	this->nSTT = nSTT;
}

void PhieuMuon::DoiNgay(string &ngayMuon,string &ngayTra)
{
	int ngay, thang, nam;

	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);

	ngay = (ltm->tm_mday);
	thang = (1 + ltm->tm_mon);
	nam = (1900 + ltm->tm_year);
	ostringstream ongayMuon;
	ongayMuon << ngay << "/" << thang << "/" << nam;
	sNgayMuon = ongayMuon.str();
	ngayMuon = sNgayMuon;
	if (((ngay + 7) > 31) && (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12))
	{
		if (thang == 12)
		{
			ngay = ngay + 7 - 31;
			thang = 1;
			nam = nam + 1;
		}
		else
		{
			ngay = ngay + 7 - 31;
			thang = thang + 1;
		}
	}
	else if (((ngay + 7) > 30) && (thang == 4 || thang == 6 || thang == 9 || thang == 11))
	{
		ngay = ngay + 7 - 30;
		thang = thang + 1;
	}
	else if (((ngay + 7) > 29) && thang == 2)
	{
		ngay = ngay + 7 - 29;
		thang = thang + 1;
	}
	else
	{
		ngay = ngay + 7;
	}

	ostringstream ongayTra;
	ongayTra << ngay << "/" << thang << "/" << nam;
	sNgayTra = ongayTra.str();
	ngayTra = sNgayTra;
}
