#include "QuanLy.h"


QuanLy::QuanLy()
{

}
void QuanLy::QuanLyMK(int& nID, int nDem)
{
	HienThi HT;
	string sMaCaoCap;
		char ch;
		system("cls");
		HT.MauChu(1);
		cout << "*****************************************************************************\n";
		cout << "*****************            Supper Quan Ly            **********************\n";
		cout << "*****************************************************************************\n\n\n\n";
		HT.MauChu(2);
		cout << "Nhap Ma Truy Cap Cao Cap. Ban Co 3 Lan Nhap Hay Co Nhap Cho Chinh Xac\n";
		cout << "Khong the xoa trong qua trinh nhap vi vay hay that can than!!!\n\n";
		cout << "\t\t\t\So Lan Nhap Con Lai : " << nDem << endl << endl;
		HT.MauChu(3);
		cout << "\t\tNhap Ma Tai Day: ";
		HT.MauChu(7);
		int nSoMa = 0;
		ch = _getch();
		cout << nSoMa;
		nSoMa++;
		while (true) {
			if (ch == 13)
			{
				break;
			}
			else
			{
				sMaCaoCap.push_back(ch);
				if (ch == 8)
				{
					break;
				}
				else
				{
					ch = _getch();
					cout << nSoMa;
					nSoMa++;
				}
			}
		}
		if (sMaCaoCap == "con")
		{
			nID = 1;
		}
}

void QuanLy::TaoPhieuMuon(vector<SinhVien> SV, vector<GiaoVien> GV, vector<Sach>& Sa)
{
	HienThi HT;
	GhiXuatDuLieu G;
	string sNgayMuon;
	string sMaBanDoc;
	string sMasach;
	int nTinhTrang;
	int nKiem = 0;
	int nVT = 0;
	PhieuMuon PM;
	system("cls");
	HT.MauChu(1);
	cout << "*****************************************************************************\n";
	cout << "*****************            Tao Phieu Muon            **********************\n";
	cout << "*****************************************************************************\n\n\n\n";
	HT.MauChu(2);
	do
	{
		rewind(stdin);
		cout << "\t\tNhap Ma Sach: ";
		HT.MauChu(7);
		rewind(stdin);
		getline(cin, sMasach);
		rewind(stdin);
		for (int i = 0; i < Sa.size(); i++)
		{
			if (Sa.at(i).getMaSach() == sMasach && Sa.at(i).getMaPhieuMuon() == 0)
			{
				nKiem = 1;
				nVT = i;
				break;
			}
			else if(sMasach == "thoat")
			{
				nKiem = 5;
				break;
			}
		}
	} while (nKiem == 0);
	if (nKiem == 1)
	{
		do
		{
			HT.MauChu(2);
			cout << "\t\tNhap Ma Ban Doc: ";
			HT.MauChu(7);
			rewind(stdin);
			getline(cin, sMaBanDoc);
			rewind(stdin);
			for (int i = 0; i < SV.size(); i++)
			{
				if (SV.at(i).getMaBanDoc() == sMaBanDoc)
				{
					nKiem = 2;
				}
				else if (sMaBanDoc == "thoat")
				{
					nKiem = 5;
					break;
				}
			}
			if (nKiem != 2)
			{
				for (int i = 0; i < GV.size(); i++)
				{
					if (GV.at(i).getMaBanDoc() == sMaBanDoc)
					{
						nKiem = 2;
					}
					else if (sMaBanDoc == "thoat")
					{
						nKiem = 5;
						break;
					}
				}
			}
		} while (nKiem == 1);
	}
	nTinhTrang = 1;
	PM.setMaSach(sMasach);
	PM.setMaBanDoc(sMaBanDoc);
	PM.setNgay();
	PM.setTinhTrang(nTinhTrang);
	if (nKiem != 5)
	{
		char cKey;
		G.GhiPhieuMuon(PM);
		Sa.at(nVT).setMaPhieuMuon(PM.getSTT());
		G.capNhat(Sa);
		HT.MauChu(10);
		cout << "\n\n\t\tDang Tao Vui Long Cho!!!!\n\n\n";
		cout << "\t\tBam phim bat ky de thoat!!!\n\n";
		cKey = _getch();
		Sleep(100);
	}
}

void QuanLy::CapNhatPhieuMuon(vector<Sach>& Sa)
{
	HienThi HT;
	GhiXuatDuLieu G;
	string sSoPM;
	PhieuMuon PM;
	string link;
	ifstream input;
	int nTinhTrang;
	
	do
	{
		system("cls");
		HT.MauChu(1);
		cout << "*****************************************************************************\n";
		cout << "*****************            Tao Phieu Muon            **********************\n";
		cout << "*****************************************************************************\n\n\n\n";
		rewind(stdin);
		HT.MauChu(2);
		cout << "\t\tNhap So Phieu Muon: ";
		HT.MauChu(7);
		getline(cin, sSoPM);
		rewind(stdin);
		link.operator=("D:/Database/PhieuMuon/");
		link.operator+=(sSoPM);
		link.operator+=(".txt");
		input.open(link, ios::out);
		HT.MauChu(2);
		cout << "\t\tNhap Tinh Trang: ";
		HT.MauChu(7);
		cin >> nTinhTrang;
		if (input.is_open() == true && nTinhTrang == 1 || nTinhTrang == 0)
		{
			G.capNhatPhieuMuon(PM, link, nTinhTrang);
			char cKey;
			if (nTinhTrang == 0)
			{
				for (int i = 0; i < Sa.size(); i++)
				{
					if (Sa.at(i).getMaSach() == PM.getMaSach())
					{
						Sa.at(i).setMaPhieuMuon(0);
						G.capNhat(Sa);
					}
				}
			}
			HT.MauChu(10);
			cout << "\n\n\t\tDang Tao Vui Long Cho!!!!\n\n\n";
			Sleep(100);
			HT.MauChu(8);
			cout << "\t\tBam phim bat ky de thoat!!!\n\n";
			cKey = _getch();
			break;
		}
	} while (true);
}

void QuanLy::themSachMoi(vector<Sach>& Sa)
{
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNXB;
	double dTriGia;
	int nNam;
	int nSoTrang;
	string sNgayNhap;
	int MaPhieuMuon;

	system("cls");
	cout << "*****************************************************************************\n";
	cout << "*****************               Them Sach              **********************\n";
	cout << "*****************************************************************************\n\n\n\n";
	cout << "\tNhap Ma Sach: ";
	rewind(stdin);
	getline(cin, sMaSach);
	cout << "\tNhap Tua De: ";
	rewind(stdin);
	getline(cin, sTuaDe);
	cout << "\tNhap Tac Gia: ";
	rewind(stdin);
	getline(cin, sTacGia);
	cout << "\tNhap NXB: ";
	rewind(stdin);
	getline(cin, sNXB);
	cout << "\tNhap Ngay Nhap"<<endl<<"(dinh dang theo dd/mm/yyyy khong tuan thu loi rang chiu): ";
	rewind(stdin);
	getline(cin, sNgayNhap);
	cout << "\tNhap Tri Gia: ";
	cin >> dTriGia;
	cout << "\tNhap Nam: ";
	cin >> nNam;
	cout << "\tNhap So Trang: ";
	cin >> nSoTrang;
	MaPhieuMuon = 0;
	Sach SA(sMaSach, sTuaDe, sTacGia, sNXB, dTriGia, nNam, nSoTrang, sNgayNhap, MaPhieuMuon);
	Sa.push_back(SA);
	GhiXuatDuLieu G;
	G.capNhat(Sa);
	cout << "\n\n\Da Them Thanh Cong, Bam phim bat ky de thoat!!!\n\n";
	char cKey;
	cKey = _getch();

}
void QuanLy::xoaSach(vector<Sach>& Sa)
{
	string sMaSach;
	int nSach = -1;
	system("cls");
	cout << "*****************************************************************************\n";
	cout << "*****************               Xoa  Sach              **********************\n";
	cout << "*****************************************************************************\n\n\n\n";
	cout << "\tNhap Ma Sach Can Xoa: ";
	rewind(stdin);
	getline(cin, sMaSach);
	for (int i = 0; i < Sa.size(); i++)
	{
		if (Sa.at(i).getMaSach() == sMaSach && Sa.at(i).getMaPhieuMuon() == 0)
		{
			nSach = i;
		}
	}
	if (nSach == -1)
	{
		system("cls");
		cout << "*****************************************************************************\n";
		cout << "*****************               Xoa  Sach              **********************\n";
		cout << "*****************************************************************************\n\n\n\n";
		cout << "\t\tKhong Tim Thay Sach Can Xoa!!!\n";
		cout << "\t\tCo The la chua them, Hay them truoc khi xoa.\n";
		cout << "\t\tCo Khi La Sach Dang Co Nguoi Muon.\n";
		cout << "\n\n\Bam phim bat ky de thoat!!!\n\n";
		char cKey;
		cKey = _getch();
	}
	else
	{
		Sa.erase(Sa.begin() + nSach);
		GhiXuatDuLieu G;
		G.capNhat(Sa);
		system("cls");
		cout << "*****************************************************************************\n";
		cout << "*****************               Xoa  Sach              **********************\n";
		cout << "*****************************************************************************\n\n\n\n";
		cout << "\t\tDa Xoa Thanh Cong!!!\n";
		cout << "\n\n\Bam phim bat ky de thoat!!!\n\n";
		char cKey;
		cKey = _getch();
	}
}
void QuanLy::themBanDoc(vector<SinhVien>& SV, vector<GiaoVien>& GV)
{
	HienThi HT;
	int nChucVu = 0;
	string sNgayThamGia;
	string sHoTen;
	string sKhoa;
	string sDiaChi;
	string sSDT;
	string sKhoaHoc;
	string sMaBanDoc;
	int nMaBanDoc;

	system("cls");
	HT.MauChu(1);
	cout << "*****************************************************************************\n";
	cout << "*****************               Them Ban Doc              **********************\n";
	cout << "*****************************************************************************\n\n\n\n";
	HT.MauChu(2);
	cout << "\tChon Chuc Vu: 1. Giao Vien 2.Sinh Vien\n";
	cout << "Nhap Con So Theo Chuc Vu Vao Day: ";
	do
	{
		HT.MauChu(7);
		cin >> nChucVu;
	} while (nChucVu<0 || nChucVu > 2);
	if (nChucVu == 1)
	{
		if (GV.size() != 0)
		{
			sMaBanDoc = GV.at(GV.size() - 1).getMaBanDoc().substr(2, 6);
			stringstream chuSangSo(sMaBanDoc);
			chuSangSo >> nMaBanDoc;
			nMaBanDoc++;
			ostringstream soSangChu;
			soSangChu << nMaBanDoc;
			sMaBanDoc = "GV";
			sMaBanDoc += soSangChu.str();
		}
		else
		{
			sMaBanDoc = "GV1";
		}
		HT.MauChu(2);
		cout << "Nhap ngay tham Gia: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sNgayThamGia);
		HT.MauChu(2);
		cout << "Nhap Ho Ten: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sHoTen);
		HT.MauChu(2);
		cout << "Nhap Khoa: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sKhoa);
		HT.MauChu(2);
		cout << "Nhap Dia Chi: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sDiaChi);
		HT.MauChu(2);
		cout << "Nhap SDT: ";
		HT.MauChu(7);
		rewind(stdin);
		getline(cin, sSDT);
		rewind(stdin);
		GiaoVien Gv(sMaBanDoc, sNgayThamGia, sHoTen, sKhoa, sDiaChi, sSDT);
		GV.push_back(Gv);
	}
	else if (nChucVu == 2)
	{
		if (SV.size() != 0)
		{
			sMaBanDoc = SV.at(SV.size() - 1).getMaBanDoc().substr(2, 6);
			stringstream chuSangSo(sMaBanDoc);
			chuSangSo >> nMaBanDoc;
			nMaBanDoc++;
			ostringstream soSangChu;
			soSangChu << nMaBanDoc;
			sMaBanDoc = "SV";
			sMaBanDoc += soSangChu.str();
		}
		else
		{
			sMaBanDoc = "SV1";
		}
		HT.MauChu(2);
		cout << "Nhap ngay tham Gia: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sNgayThamGia);
		HT.MauChu(2);
		cout << "Nhap Ho Ten: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sHoTen);
		HT.MauChu(2);
		cout << "Nhap Khoa: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sKhoa);
		HT.MauChu(2);
		cout << "Nhap Khoa Hoc: ";
		rewind(stdin);
		HT.MauChu(7);
		getline(cin, sKhoaHoc);
		rewind(stdin);
		SinhVien Sv(sMaBanDoc, sNgayThamGia, sHoTen, sKhoa, sKhoaHoc);
		SV.push_back(Sv);
	}

	GhiXuatDuLieu G;
	G.themBanDoc(SV, GV);
	HT.MauChu(10);
	cout << "\n\n\Da Them Thanh Cong, Bam phim bat ky de thoat!!!\n\n";
	char cKey;
	cKey = _getch();
}
void QuanLy::thongKe(vector<SinhVien> SV, vector<GiaoVien> GV, vector<Sach> Sach)
{
	HienThi HT;
	string sMaBanDoc;
	vector<string> sach;
	GhiXuatDuLieu G;
	int soSachDaChoMuon = 0;
	for (int i = 0; i < Sach.size(); i++)
	{
		if (Sach.at(i).getMaPhieuMuon() != 0)
		{
			soSachDaChoMuon++;
		}
	}
	system("cls");
	HT.MauChu(1);
	cout << "*****************************************************************************\n";
	cout << "*****************            Quan Ly Sach              **********************\n";
	cout << "*****************************************************************************\n\n\n\n";
	HT.MauChu(2);
	cout << "\t>.<  So Sach Con Lai: " << Sach.size()- soSachDaChoMuon << endl;
	cout << "\t>.<  So Sach Da Cho Muon: "<< soSachDaChoMuon << endl;
	HT.MauChu(3);
	cout << "\nNhap thoat de thoat, nhap Ma ban doc de xem thong tin: ";
	rewind(stdin);
	HT.MauChu(7);
	getline(cin, sMaBanDoc);
	if (sMaBanDoc != "thoat")
	{
		G.docPhieuMuon(sach, sMaBanDoc);
		for (int j = 0; j < sach.size(); j++)
		{
			for (int i = 0; i < Sach.size(); i++)
			{
				if (Sach.at(i).getMaSach() == sach.at(j))
				{
					HienThi HT;

					HT.HienThiDon(Sach, i);
					break;
				}
			}
		}
		HT.MauChu(10);
		cout << "\n\n\Bam phim bat ky de thoat!!!\n\n";
		char cKey;
		cKey = _getch();
	}
}
QuanLy::~QuanLy()
{
}
