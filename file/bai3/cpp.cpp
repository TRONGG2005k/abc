#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
struct sv
{
    char name[50];
    char id[10];
    double diem;
};

struct Index {
    char id[10];
    int index;
};

bool SortByID (Index a, Index b) {
    return strcmp(a.id, b.id) < 0;  
}

vector<Index> readAndSave (string file) {
    ifstream fdiem (file, ios::binary);
    vector<Index> a;
    sv st;
    int index = 0; 
    while (fdiem.read(reinterpret_cast<char*>(&st), sizeof(sv)))
    {
        Index i;
        strcpy(i.id, st.id);
        i.index = index;
        a.push_back(i);
        index++;
    }
    fdiem.close();
    sort(a.begin(), a.end(), SortByID);

    return a;
}
void wirteIdx (vector<Index> a, string file) {
    ofstream fChiMuc (file, ios::binary);
    for (auto &x : a) {
        fChiMuc.write(reinterpret_cast<char*>(&x), sizeof(Index));
    }
    fChiMuc.close();
    ifstream fchimuc ("file", ios::binary);
    Index entry;
    while (fchimuc.read(reinterpret_cast<char*>(&entry), sizeof(Index))) {
        cout << "ID: " << entry.id << ", vi tri: " << entry.index << endl;
    }
    fchimuc.close();
}
int main () {
    vector<Index> a = readAndSave("diem.dat");
    wirteIdx(a, "ChiMuc.idx");
    return 0;
}