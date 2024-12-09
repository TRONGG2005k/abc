#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "QLXT.h"
#include <conio.h>
using namespace std;

void clear_screen() {
    system("cls");
}

void timkiem () {
	int key;
	do {
		clear_screen();
		cout << " Tao tep chi muc " << endl;
		cout << "-----------------" << endl;
		cout << "1 tim kiem theo ma " << endl; 
		cout << "2 tim kiem theo ma" << endl;
		cout << "0 thoat" << endl;
		cout << "lua chon: " ;
		cin >> key;
		switch (key) {
			case 1:
				{
					vector<Index> vTheoMaDK = readAndSave("HoSoSetTuyen.dat", "maDk");
					truyCapTrucTiep("HoSoSetTuyen.dat", vTheoMaDK);
				    cout << "Bam phim bat ky de tiep tuc!" << endl;
					getch();
//					cin.getline();
				    break;
				}
			case 2:
				{
					vector<Index> vTheoCC = readAndSave("HoSoSetTuyen.dat", "cc");
			    	truyCapTrucTiep("HoSoSetTuyen.dat", vTheoCC);
			    	cout << "Bam phim bat ky de tiep tuc!" << endl;
					getch();
				    break;
				}
			default:
				cout << "Nhap khong hop le vui long chon lai!" <<endl;
		}
	} while (key != 0);
}

void taoTepChiMuc () {
	int key;	
	do {
		clear_screen();
		cout << "          Tao tep chi muc       " << endl;
		cout << "----------------------------------" << endl;
		cout << "1 Tao tep chi muc theo ma dang ky " << endl; 
		cout << "2 Tao tep chi muc theo ma can cuoc" << endl;
		cout << "             0 thoat              " << endl;
		cout << "lua chon: " ;
		cin >> key;
		switch (key) {
			case 1:
				{
					vector<Index> vTheoMaDK = readAndSave("HoSoSetTuyen.dat", "maDk");
				    writeIdx(vTheoMaDK, "TheoMaDK.idx");
				    cout << "da tao tep chi muc" << endl;
				    cout << "Bam phim bat ky de tiep tuc!" << endl;
					getch();
				    break;
				}
			case 2:
				{
					vector<Index> vTheoCC = readAndSave("HoSoSetTuyen.dat", "cc");
			    	writeIdx(vTheoCC, "TheoCC.idx");
			    	cout << "da tao tep chi muc" << endl;
			    	cout << "Bam phim bat ky de tiep tuc!" << endl;
					getch();
				    break;
				}
			default:
				cout << "Nhap khong hop le vui long chon lai!" <<endl;
		}
	} while (key != 0);
}

int main () {
	while(true){
		clear_screen();
		cout << "      Quan Ly Xet Tuyen      " << endl;
		cout << "-----------------------------" << endl;
		cout << "  1 Nhap thong tin sinh vien " << endl;
		cout << "      2 Tao tep chi muc      " << endl;
		cout << "         3 Tim kiem          " << endl;
		cout << "    4 Hien bang thong tin     " << endl;
		cout << "          0 thoat            " << endl;
		cout << "lua chon: " ;
		int key;
		cin >> key;
		switch(key){
			case 1:
				// NhapTT("HoSoSetTuyen.dat");
				cout << "Bam phim bat ky de tiep tuc!" << endl;
				getch();
				break;
			case 2:
				taoTepChiMuc();
				break;
			case 3:
				{
					timkiem();   
					cout << "Bam phim bat ky de tiep tuc!" << endl;
					getch();
					break;
				}
			case 4:
				DocTT("HoSoSetTuyen.dat");
				cout << "Bam phim bat ky de tiep tuc!" << endl;
				getch();
				break;
			case 0:
				cout << "Ban da thoat truong trinh" << endl;
				exit(0);break;
			default:
				cout << "Nhap khong hop le vui long chon lai!" << endl;
				break;	
		}
	}
}


