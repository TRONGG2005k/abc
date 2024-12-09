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

bool CompareID(const Index &a, const char *searchid) {
    return strcmp(a.id, searchid) < 0;
}

int seachByBinary_Seach (vector<Index> traCuu) {
    char searchID[10];
    cout << "nhap ma sv can tim: ";
    cin >> searchID;
    vector<Index>::iterator it = lower_bound(traCuu.begin(), traCuu.end(), searchID, CompareID);
    if (it != traCuu.end() && strcmp(it->id, searchID) == 0) {
        return it->index;
    }
	return -1;
}

void timQuaIndex (int index) {
    if (index == -1) { 
        cout << "Khong the tim thay." << endl;
        return;
    }
    ifstream fdiem("diem.dat", ios::binary);
    sv st;
    fdiem.seekg(index * sizeof(sv));
    if (fdiem.read(reinterpret_cast<char*>(&st), sizeof(sv))) {
        cout << "Sinh vien " << st.id << ", co diem: " << st.diem << endl;
    } else {
        cout << "khong thay sv vs chi muc: " << index << endl;
    }
}

int main () {
    ifstream fchimuc ("ChiMuc.idx", ios::binary);
    Index entry;
    vector<Index> traCuu;
    while (fchimuc.read(reinterpret_cast<char*>(&entry), sizeof(Index))) {
        traCuu.push_back(entry);
    }
    fchimuc.close();
    for (int i = 0; i < traCuu.size(); i++) {
        cout << "Ma sv: " << traCuu[i].id << " index:" << traCuu[i].index << endl;
    }
    int seach = seachByBinary_Seach(traCuu);
    timQuaIndex(seach);
    return 0;
}
