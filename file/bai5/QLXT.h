
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct HoSoSv {
    char maDk[11];
    char hoten[50];
    char cc[13];
    double dDiemXetTuyen;
    char cQueQuan[10000];
    char sex[5];
};

struct Index {
    char data[14];
    int index;
};

bool sortByIndex (Index a, Index b) {
    return a.index < b.index;
}

int binarySeach (vector<Index> &a, char* search) {
    int l = 0; int r = a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        int cmp = strcmp(a[m].data, search);
        if (cmp == 0) {
            return a[m].index;
        } else if (cmp < 0) {
            l = m + 1; 
        } else {
            r = m - 1;
        }
    }
    return -1;
}

void truyCapTrucTiep (const char* file, vector<Index> a) {
    ifstream fHoSo (file, ios::binary);
    char search[14];
    cout << "nhap ma sv can tim:";
    cin >> search;
    int index = binarySeach(a, search);
    HoSoSv st;
    if (index == -1) {
        cout << "Khong tim thay sinh vien voi ma dang ky: " << search << endl;
        return;
    }
    fHoSo.seekg(index * sizeof(HoSoSv)) ;
    if (fHoSo.read(reinterpret_cast<char*>(&st), sizeof(HoSoSv))) {
        cout << left << setw(15) << "Ma Dang Ky"
         << setw(30) << "Ho Ten" 
         << setw(20) << "CCCD" 
         << setw(15) << "Diem Xet Tuyen" 
         << setw(30) << "Que Quan" 
         << setw(10) << "Gioi Tinh" << endl;
        cout << string(120, '-') << endl; 
        cout << left << setw(15) << st.maDk 
             << setw(30) << st.hoten 
             << setw(20) << st.cc 
             << setw(15) << st.dDiemXetTuyen 
             << setw(30) << st.cQueQuan 
             << setw(10) << st.sex << endl;
    } else {
        cout << "khong thay sv vs chi muc: " << index << endl;
    }
}

void NhapTT (const char* file) {
    HoSoSv st;
    ofstream fHoSo (file, ios::binary);
    if (!fHoSo.is_open()) {
        cout << "khong mo dc file";
        return;
    }
    while (true) {
        cout << "(nhan enter de ket thuc nhap)nhap ma dang ky:";
        cin.getline(st.maDk, 11);
        if (st.maDk[0] == '\0') {
            break;
        }
        cout << "nhap ho ten:";
        cin.getline(st.hoten, 50);

        cout << "nhap can cuoc cong dan:";
        cin.getline(st.cc, 13);
        
        cout << "nhap diem xet tuyen:";
        cin >> st.dDiemXetTuyen;
        cin.ignore(); 
        
        cout << "nhap que quan:";
        cin.getline(st.cQueQuan, 100);
        
        cout << "nhap gioi tinh:";
        cin.getline(st.sex, 5);
        
        fHoSo.write(reinterpret_cast<char*>(&st), sizeof(HoSoSv));
    }
    fHoSo.close();
}

void DocTT(const char* file) {
    HoSoSv st;
    ifstream fHoSo(file, ios::binary);
    if (!fHoSo.is_open()) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    cout << left << setw(15) << "Ma Dang Ky" 
         << setw(20) << "Ho Ten" 
         << setw(20) << "CCCD" 
         << setw(20) << "Diem Xet Tuyen" 
         << setw(30) << "Que Quan" 
         << setw(10) << "Gioi Tinh" << endl;
    cout << string(120, '-') << endl; 
    while (fHoSo.read(reinterpret_cast<char*>(&st), sizeof(HoSoSv))) {
            cout << left << setw(15) << st.maDk 
                << setw(20) << st.hoten 
                << setw(20) << st.cc 
                << setw(20) << st.dDiemXetTuyen 
                << setw(30) << st.cQueQuan 
                << setw(10) << st.sex << endl;
    }
    fHoSo.close();
}

vector<Index> readAndSave (const char* file, const char* thuoctinh) {
    ifstream fdiem (file, ios::binary);
    if (!fdiem.is_open()) {
        cout << "khong doc duoc file";
        return {};
    }
    vector<Index> a;
    HoSoSv st;
    int index = 0; 
    
    while (fdiem.read(reinterpret_cast<char*>(&st), sizeof(HoSoSv))) {
        Index i;
        if (strcmp(thuoctinh,  "cc") == 0) {
            strcpy(i.data, st.cc); 
        } else if (strcmp(thuoctinh, "maDk") == 0) {
            strcpy(i.data, st.maDk); 
        }
        i.index = index;
        a.push_back(i);
        index++;
    }

    fdiem.close();    
    sort(a.begin(), a.end(), sortByIndex);
    return a;
}

void writeIdx (vector<Index> a, const char* file) {
    
    ofstream fChiMuc (file, ios::binary);
    if (!fChiMuc.is_open()) {
        cout << "Khong mo duoc file" << endl;
        return;
    }
    for (int i = 0; i < a.size(); ++i) {
        fChiMuc.write(reinterpret_cast<char*>(&a[i]), sizeof(Index));
    }
    fChiMuc.close();
    // ifstream fchimuc (file, ios::binary);
    // Index entry;
    // while (fchimuc.read(reinterpret_cast<char*>(&entry), sizeof(Index))) {
    //     cout << "ID: " << entry.data << ", vi tri: " << entry.index << endl;
    // }
    // fchimuc.close();
}
