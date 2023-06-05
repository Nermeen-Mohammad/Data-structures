//Student : Nermeen Mohammad Almomani

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
	ItemType info;
	struct NodeType* next;
};

template <class ItemType>
class StackType {
public : 
	StackType();
	~StackType();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	void Push(ItemType item);
	void Pop(ItemType &item);
	void display();
	private:
	NodeType <ItemType>* topPtr;
};

template <class ItemType>
StackType <ItemType> ::StackType() {
	topPtr = NULL;
 }

template <class ItemType>
StackType <ItemType> ::~StackType() {
	MakeEmpty();
}

template <class ItemType>
void StackType <ItemType> ::Push(ItemType item) {
	NodeType <ItemType>* location = new NodeType <ItemType>;

	location->info = item;
	location->next = topPtr;
	topPtr = location;
}

template <class ItemType>
void StackType <ItemType> ::Pop(ItemType& item) {

	item = topPtr->info; // لتخزين القيمة قبل الحذف
	NodeType <ItemType>* tempPtr;
	tempPtr = topPtr;
	topPtr = topPtr->next;
	tempPtr = tempPtr->next = NULL;
	delete tempPtr;
}

template <class ItemType>
bool StackType <ItemType> ::IsEmpty() {
	return (topPtr == NULL);
}

template <class ItemType>
void StackType <ItemType> ::display() {
	NodeType <ItemType>* CurPos = topPtr;
	cout <<'[';

	while (CurPos != NULL){
		cout << CurPos->info <<" ";
	CurPos = CurPos->next;

}
	cout <<']';
}

template <class ItemType>
bool StackType <ItemType> ::IsFull() {
	NodeType<ItemType>* location = new NodeType<ItemType>;
	if (location == NULL)
		return true;
	else
		delete location;
		return false;
}

template <class ItemType>
void StackType <ItemType> ::MakeEmpty() {
	NodeType <ItemType>* tempPtr;
	while (topPtr != NULL) {
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

int main() {
	StackType<int> obj;// CREATE OBJECT
	obj.Push(3);
	obj.Push(17);
	obj.Push(28);
	obj.Push(1);
	obj.display();
}


 

