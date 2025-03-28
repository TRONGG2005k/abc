#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class SV {
public:
	string id;
	string name;
	double score;
	
	SV (string id,
		string name,
		double score) {
		this->id = id;
		this->name = name;
		this->score = score;
	}
	SV() {}
	
	void nhap() {
	    cout << "ID: ";
	    getline(cin, this->id);
	    if (this->id.empty()) {
	        return;
		}
	    cout << "Ho va Ten: ";
	    getline(cin, this->name);
	    cout << "Diem: ";
	    cin >> this->score;
	    cin.ignore();
	}
};

class Node {
public:
	SV data;
	Node *next;
	Node(SV value) {
		this->data = value;
		this->next = NULL;
	}
};

class LinkList {
private:
	Node* head;
public:
	LinkList () {
		head = NULL;
	}
	
	void prepend(SV value) {
		Node* node = new Node(value);
		node->next = head;
		head = node;
	}
	
	void inputSt () {
		int i = 0;
		while (true) {
			cout << "Nhap thong tin sinh vien thu " << ++i << ":" << endl;
			SV st;
			st.nhap();
			if(st.id.empty()) {
				break;
			}
	        prepend(st);
		}	
	}
	
	void display() {
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
	
	Node* search() {
		string input;
		cout << "nhap ma sv can tim: " ;
		cin >> input;
		Node *tam = head;
		int i = 0;
		bool bl = false;
		while (tam != NULL ) {
			if(tam->data.id == input) {
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
			i++;
		}
		if (!bl) {
			cout << "bo hoc!" << endl;
		}
		return NULL;
	}
	
	void ModifyScore(Node* result) {
		double newScore;
		cout << "nhap diem moi cua sv " << result->data.name << ": ";
		cin >> newScore;
		cin.ignore();
		result->data.score = newScore;
		cout << "cap nhat thanh cong!" <<endl;
	}
	
	void RemoveScoreSmaller5() {
		if(head->next != NULL && head->data.score < 5) {
			Node*tam = head;
			head = head->next;
			delete(tam);
		} 
		Node *tam = head;
		while(tam->next != NULL && tam != NULL) {
			if(tam->next->data.score < 5) {
				Node *tam2 = tam->next;
				tam->next = tam->next->next;
				delete(tam2);
			} else {
				tam = tam->next;
			}
		}
	}
	
	void insertBefore(SV st) {
		string input;
		cout << "nhap ma sv de chen vao truoc: ";
		cin >> input;
		Node *node = new Node(st);
		if(head != NULL && head->data.id == input) {
			node->next = head;
			head = node;
			return;
		}
		Node *tam = head;
		while(tam->next != NULL && tam != NULL) {
			if(tam->next->data.id == input) {
				node->next = tam->next;
				tam->next = node;
				return;
			}
			tam = tam->next;
		}
		cout << "Khong tim thay ma SV de chen truoc!" << endl;
    	delete node;
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

