#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct sv
{
    char name[50];
    char id[10];
    double diem;
};

void ghiTieuDe(ofstream &f) {
    f << "Danh sach hoc lai" << "\n";
    f << left << setw(15) << "Ma" << setw(20) << "Ten" << "Diem " << endl;
}

void nhapDangSachDiem (string File_Name) {
    ofstream fdiem (File_Name, ios::binary);
    sv st;
    while (true) {
        cout << "Nhap ma sv: ";
        cin.getline(st.id, 10);
        if (st.id[0] == '\0') {
            break; 
        }
        cout << "Nhap ten: ";
        cin.getline(st.name, 50);
        cout << "Nhap diem: ";
        cin >> st.diem;
        cin.ignore(); 
        fdiem.write(reinterpret_cast<char*>(&st), sizeof(sv));
    }
    fdiem.close();
}

string TimDiemQuaID (string FileName, string text) {
    ifstream fdiem (FileName, ios::binary);
    sv st;
    if (!fdiem.is_open()) {
        cout << "Khong mo duoc file " << FileName << endl;
        return "false";
    }
    cout << text;
    string input;
    cin >> input;
    bool bl = false;
    string tam;
    while (fdiem.read(reinterpret_cast<char*>(&st), sizeof(sv)))
    {
        if (input == st.id) {
            cout << "Sv " << st.id << " co diem: " << st.diem << endl;
            bl = true;
            tam = st.id;
            break;
        }
    }
    if (!bl) {
        cout << "bo hoc";
        return "0";
    }
    fdiem.close();
    return tam;;
}

void suaDiem (string FileName) {
    ifstream fdiem (FileName, ios::binary);
    sv st;
    if (!fdiem.is_open()) {
        return ;
    }
    vector<sv> st1;
    while (fdiem.read(reinterpret_cast<char*>(&st), sizeof(sv)))
    {
        st1.push_back(st);
    }
    fdiem.close();
    double new_diem;
    bool bl = false;
    string tim = TimDiemQuaID(FileName, "Nhap sv can tim de sua diem: ");
    for (auto &x : st1) {
        if (tim == x.id) {
            cout << "Nhap diem can sua: ";
            cin >> new_diem;
            x.diem = new_diem;
            bl = true;
            break;
        }
    }
    if (!bl) {
        cout << "Sinh vien khong ton tai" << endl;
    }
    ofstream fdiem1 (FileName, ios::binary);
    for (auto x : st1) {
        fdiem1.write(reinterpret_cast<char*>(&x), sizeof(sv));
    }
    fdiem1.close();
    cout << "Diem da duoc sua thanh cong!" << endl;

}

void DsHocLai (string FileDat, string FileHocLai) {
    ifstream fdiem(FileDat, ios::binary);
    sv st;
    if (!fdiem.is_open()) {
        return;
    }
    ofstream fhoclai(FileHocLai, ios::binary);
    if (!fhoclai.is_open()) {
        return;
    }
    bool bl = false;
    while (fdiem.read(reinterpret_cast<char*>(&st), sizeof(sv)))
    {
        if (st.diem < 5) {
            fhoclai.write(reinterpret_cast<char*>(&st), sizeof(sv));
            bl = true; 
        } 
    }
    if (!bl) {
        fhoclai << "khong co sv hoc lai!";
    }
    fhoclai.close();
    fdiem.close();
    cout << "Da ghi danh sach hoc lai vao " << FileHocLai << endl;
}

void DsDiemBeHon5 (string FileName) {
    ifstream fListBeHon5 (FileName, ios::binary);
    sv st;
    cout << left << setw(15) << "Ma" << setw(20) << "Ten" << "Diem" << endl;
    cout << string(50, '-') << endl; // Dòng phân cách
    while (fListBeHon5.read(reinterpret_cast<char*>(&st), sizeof(sv)))
    {
        cout << left << setw(15) << st.id << setw(20) << st.name << st.diem << endl;
    }
    fListBeHon5.close();
}

int main () {
    nhapDangSachDiem("diem.dat");
    TimDiemQuaID("diem.dat", "Nhap sv can tim: ");
    suaDiem("diem.dat");
    DsHocLai("diem.dat", "hoclai.dat");
    DsDiemBeHon5("hoclai.dat");
}