#include <iostream>
#include <bist/stdc++.h>
using namespace std;

class SV{
public:
	string id;
	string name;
	double score;
	SV (string id, string name, double score) {
		this->id = id;
		this->name = name;
		this->score = score;
	}
	SV () {}
};

class Node {
public: 
	SV data;
	Node *next;
	Node (SV value) {
		data = value;
		next = NULL;
	}
};

class LinkList {
private:
	Node *head;
public:
	LinkList () {
		head = NULL;
	}
	void prepend (SV value) {
		Node *newNode = new Node( value);
		newNode->next = head;
		head = newNode;
	}
	void inputSt () {
		int i = 0;
		while (true) {
			SV st;
			cout << "Nhap thong tin sinh vien thu " << ++i << ":" << endl;
	        cout << "ID: ";
	        getline(cin, st.id);
	        if (st.id.empty()) {
	            break;
			}
	        cout << "Ho va Ten: ";
	        getline(cin, st.name);
	        cout << "Diem: ";
	        cin >> st.score;
	        cin.ignore();
	        prepend(st);
		}	
	}
	void Display () {
		Node *tam = head;
		int i = 0;
		cout<< left 
	    	<< setw(5) << "STT"
	        << setw(20) << "Ho Va Ten"
	        << setw(15) << "ID"
	        << setw(15) << "Diem" << endl;
	    cout << string(55, '-') << endl;	
		while (tam != NULL) {
			cout<< setw(5) << i++
	            << setw(20) << tam->data.name
	            << setw(15) << tam->data.id
	            << setw(15) << tam->data.score << endl;
	        tam = tam->next;  
		}
	}
	Node* Search () {
		string input;
		cout << "nhap ma sv can tim: " ;
		cin >> input;
		Node *tam = head;
		int i = 0;
		bool bl = false;
		while (tam != NULL) {
			if (tam->data.id == input) {
				cout << left 
			    	 << setw(5) << "STT"
			         << setw(20) << "Ho Va Ten"
			         << setw(15) << "ID"
			         << setw(15) << "Diem" << endl;
			    cout << string(55, '-') << endl;
			    cout << setw(5) << i++
	                 << setw(20) << tam->data.name
	                 << setw(15) << tam->data.id
	                 << setw(15) << tam->data.score << endl;
	            bl = true;
	            return tam;
			}
			tam = tam->next;
		}
		if (!bl) {
			cout << "bo hoc!" << endl;
		}
		return NULL;
	}
	void ModifyScore (Node *result) {
		double newScore;
		cout << "nhap diem moi cua sv " << result->data.name << ": ";
		cin >> newScore;
		result->data.score = newScore;
		cout << "Cap nhat th�nh c�ng!" << endl;
	}
	void RemoveScoreSmaller5 () {
		if (head->next != NULL && head->data.score < 5) {
			Node *tam = head;
			head = head->next;
			delete(tam);
		}
		Node *tam = head;
		while (tam->next != NULL & tam != NULL) {
			if (tam->next->data.score < 5) {
				Node *tam2 = tam->next;
				tam->next = tam->next->next;
				delete(tam2);
			} else {
				tam = tam->next;
			}
		}
	}
	void insertBefore (SV st) {
		string input;
		cout << "nhap ma sv de chen vao truoc: ";
		cin >> input;
		Node *newNode = new Node(st);
		if (head != NULL && head->data.id == input) {	
			newNode->next = head;
			head = newNode;
			return;
		}
		Node *tam = head;
		while (tam != NULL && tam->next != NULL) {
			if (tam->next->data.id == input) {
				newNode->next = tam->next;
				tam->next = newNode;
				return;
			}
			tam = tam->next;
		}
		cout << "Kh�ng t�m thay m� SV de ch�n truoc!" << endl;
    	delete newNode;
	}
	~LinkList() { 
	    Node* tam;
	    while (head != NULL) {
	        tam = head;
	        head = head->next;
	        delete tam;  
	    }
	}
};
