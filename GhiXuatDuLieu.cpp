#include "GhiXuatDuLieu.h"


GhiXuatDuLieu::GhiXuatDuLieu()
{

}

void GhiXuatDuLieu::capNhat(vector<Sach> allSach)
{
	ofstream Output;
	Output.open("D:/Database/Book_Data.txt", ios::out);
	Output << allSach.size() << endl;
	for (int i = 0; i < allSach.size(); i++)
	{
		Output << allSach.at(i).getMaPhieuMuon() << " ";
		Output << allSach.at(i).getTriGia() << " ";
		Output << allSach.at(i).getNam() << " ";
		Output << allSach.at(i).getSoTrang() << " ";
		Output << allSach.at(i).getMaSach() << '#';
		Output << allSach.at(i).getTuaDe() << '#';
		Output << allSach.at(i).getTacGia() << '#';
		Output << allSach.at(i).getNXB() << '#';
		Output << allSach.at(i).getNgayNhap() << '\n';
	}
	Output.close();
}

void GhiXuatDuLieu::XuatDuLieuSach(vector<Sach>& allSach)
{
	ifstream input;
	input.open("D:/Database/Book_Data.txt", ios::in);
	int nSo = 0;
	input >> nSo;
	input.ignore(1, '\n');
	for (int i = 0; i < nSo; i++)
	{
		input >> nMaPhieuMuon;
		input >> dTriGia;
		input >> nNam;
		input >> nSoTrang;
		input.ignore(1);
		getline(input, sMaSach, '#');
		rewind(stdin);
		getline(input, sTuaDe, '#');
		rewind(stdin);
		getline(input, sTacGia, '#');
		rewind(stdin);
		getline(input, sNXB, '#');
		rewind(stdin);
		getline(input, sNgayNhap, '\n');
		Sach S(sMaSach, sTuaDe, sTacGia, sNXB, dTriGia, nNam, nSoTrang, sNgayNhap, nMaPhieuMuon);
		allSach.push_back(S);
	}
	input.close();
}

 void GhiXuatDuLieu::XuatDuLieuBanDoc(vector<SinhVien>& allSinhVien, vector<GiaoVien>& allGiaoVien)
{
	ifstream input;
	input.open("D:/Database/User_Data.txt", ios::in);
	int nSo = 0;
	input >> nSo;
	input.ignore(1, '\n');
	for (int i = 0; i < nSo; i++)
	{
		getline(input, sMaBanDoc, '#');
		rewind(stdin);
		getline(input, sNgayThamGia, '#');
		rewind(stdin);
		getline(input, sHoTen, '#');
		rewind(stdin);
		getline(input, sKhoa, '#');
		rewind(stdin);
		if (sMaBanDoc.substr(0, 2) == "GV")
		{
			getline(input, sDiaChi, '#');
			rewind(stdin);
			getline(input, sSDT, '\n');
			rewind(stdin);
			GiaoVien GV(sMaBanDoc, sNgayThamGia, sHoTen, sKhoa, sDiaChi, sSDT);
			allGiaoVien.push_back(GV);
		}
		else if(sMaBanDoc.substr(0, 2) == "SV")
		{
			getline(input, sKhoaHoc, '\n');
			rewind(stdin);
			SinhVien SV(sMaBanDoc, sNgayThamGia, sHoTen, sKhoa, sKhoaHoc);
			allSinhVien.push_back(SV);
		}
	}
	input.close();
}

void GhiXuatDuLieu::GhiPhieuMuon(PhieuMuon &PM)
{
	ofstream Output;
	string sTenFile;
	int nSTT = 1;
	while (true)
	{
		sTenFile.operator=("D:/Database/PhieuMuon/");
		sTenFile.operator+=(this->DoiSoSangChu(nSTT));
		sTenFile.operator+=(".txt");
		ifstream Test;
		Test.open(sTenFile, ios::in);
		if (Test.is_open() == false)
		{
			break;
		}
		nSTT++;
	}
	Output.open(sTenFile, ios::out);
	
	PM.setSTT(nSTT);

	Output << PM.getSTT() << endl << PM.getMaSach() << endl << PM.getMaBanDoc() << endl << PM.getNgayMuon() << endl << PM.getNgayTra() << endl << PM.getTinhTrang();

	Output.close();
}

string GhiXuatDuLieu::DoiSoSangChu(int nSo)
{
	string sSo;
	ostringstream convert;
	convert << nSo;
	sSo.operator=(convert.str());
	return sSo;
}

void GhiXuatDuLieu::capNhatPhieuMuon(PhieuMuon& PM, string link,int nTinhTrang)
{
	int nSTT;
	string sMaSach;
	string sNgayMuon;
	string sMaBanDoc;
	string sNgayTra;
	ofstream Output;
	ifstream input;

	input.open(link, ios::in);
	input >> nSTT;
	input.ignore(1, '\n');
	rewind(stdin);
	getline(input, sMaSach, '\n');
	rewind(stdin);
	getline(input, sMaBanDoc, '\n');
	rewind(stdin);
	getline(input, sNgayMuon, '\n');
	rewind(stdin);
	getline(input, sNgayTra, '\n');
	input.close();
	PM.setMaSach(sMaSach);
	PM.setMaBanDoc(sMaBanDoc);
	PM.setNgay();
	PM.setTinhTrang(nTinhTrang);
	PM.setSTT(nSTT);
	Output.open(link, ios::out);
	Output << PM.getSTT() << endl << PM.getMaSach() << endl << PM.getMaBanDoc() << endl << PM.getNgayMuon() << endl << PM.getNgayTra() << endl << PM.getTinhTrang();
	Output.close();
}

void GhiXuatDuLieu::themBanDoc(vector<SinhVien>& allSinhVien, vector<GiaoVien>& allGiaoVien)
{
	int nSo = 0;
	nSo = allGiaoVien.size() + allSinhVien.size();
	ofstream output;
	output.open("D:/Database/User_Data.txt", ios::out);
	output << nSo << endl;
	for (int i = 0; i < allGiaoVien.size(); i++)
	{
		output << allGiaoVien.at(i).getMaBanDoc() << "#";
		output << allGiaoVien.at(i).getNgayThamGia() << "#";
		output << allGiaoVien.at(i).getHoTen() << "#";
		output << allGiaoVien.at(i).getKhoa() << "#";
		output << allGiaoVien.at(i).getDiaChi() << "#";
		output << allGiaoVien.at(i).getSDT() << '\n';
	}
	for (int i = 0; i < allSinhVien.size(); i++)
	{
		output << allSinhVien.at(i).getMaBanDoc() << "#";
		output << allSinhVien.at(i).getNgayThamGia() << "#";
		output << allSinhVien.at(i).getHoTen() << "#";
		output << allSinhVien.at(i).getKhoa() << "#";
		output << allSinhVien.at(i).getKhoaHoc() << '\n';
	}
}

void GhiXuatDuLieu::docPhieuMuon(vector<string> &sach,string sMaBanDoc)
{
	string sTenFile;
	string sMaBanDoc1;
	string sach1;
	string sTam;
	int nTrangThai;
	int nSTT = 1;
	int nS = 0;
	while (true)
	{
		sTenFile.operator=("D:/Database/PhieuMuon.txt");
		sTenFile.operator+=(this->DoiSoSangChu(nSTT));
		sTenFile.operator+=(".txt");
		ifstream input;
		input.open(sTenFile, ios::in);
		if (input.is_open() == false)
		{
			break;
		}
		else
		{
			input >> nS;
			input.ignore(1,'\n');
			rewind(stdin);
			getline(input, sach1, '\n');
			rewind(stdin);
			getline(input, sMaBanDoc1, '\n');
			rewind(stdin);
			getline(input, sTam, '\n');
			rewind(stdin);
			getline(input, sTam, '\n');
			input >> nTrangThai;
			if (sMaBanDoc1 == sMaBanDoc && nTrangThai != 0)
			{
				sach.push_back(sach1);
			}
		}
		nSTT++;
	}
}

GhiXuatDuLieu::~GhiXuatDuLieu()
{

}
