Student : Nermeen Mohammad Almomani


#include <iostream>
using namespace std;

template <class ItemType> // reseved 
struct nodeType {
	ItemType info; // لأعرف محتويات النود
	nodeType* next; // struct name + pointer name
};
// عملنا الستركت للنود

template <class ItemType>
class sortedType {

public: // functions
	sortedType(); //constructor بيعطي قيم ابتدائية لما بنشئ اوبجكت
	~sortedType(); // destructor بشيل الأماكن يلي حجزناها للمتغيرات و عكس الكونستركتر
	void MakeEmpty();
	bool IsFull() const;
	int Lengthls() const;
	void RetrieveItem(ItemType&, bool& found);
	void InsertItem(ItemType newItem);
	void DeleteItem(ItemType item);
	void ResetList();
	bool IsLastItem() const;
	void GetNextItem(ItemType& item);
	void printList();

private: // Data members
	int length;
	nodeType<ItemType>* listData; // head pointer
	nodeType<ItemType>* currentPos;

};

template <class ItemType>
sortedType <ItemType>::sortedType() {
	length = 0;
	listData = NULL;// pointer الليست فاضية
}

template <class ItemType>
sortedType <ItemType>::~sortedType() {
	MakeEmpty();
}


template <class ItemType>
void sortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	nodeType < ItemType >* location;
	location = listData;
	found = false;
	while (location != NULL && !found) {

		if (location->info < item)
			location = location->next;
		else if (location->info == item) {
			found = true;
			item == location->info;
		}
		else
			location = NULL; // كسر اللوب, no reason to keep searching
	}
}

template <class ItemType>
void sortedType<ItemType>::InsertItem(ItemType newItem)
{
	nodeType<ItemType>* newNode;
	nodeType<ItemType>* predLoc;
	nodeType<ItemType>* location;
	bool found;
	found = false;
	location = listData;
	predLoc = NULL;
	while (location != NULL && !found) {
		if (location->info < newItem) {
			predLoc = location;
			location = location->next;
		}
		else
			found = true;
	}
	newNode = new nodeType<ItemType>;
	newNode->info = newItem;
	if (predLoc == NULL) {
		newNode->next = listData; //cases(1) and (4)
			listData = newNode;
	}
	else {
		newNode->next = location;
		predLoc->next = newNode; //cases(2) and (3)
	}
	length++;
}
template <class ItemType>
void sortedType<ItemType> ::DeleteItem(ItemType item) {
	nodeType <ItemType>* location = listData;
	nodeType<ItemType>* tempLocation;

	if (item == listData->info) {
		tempLocation = location;
		listData = listData->next; //delete first node
	}
	else {

		while ((!(location->next)->info == item))
			location = location->next; // delete location at location-> next
		tempLocation = location->next;
	}
	//delete the node
	location->next = (location->next)->next;
	delete tempLocation;
	length--;
}


template <class ItemType>
void sortedType<ItemType>::MakeEmpty()
{
	nodeType<ItemType>* tempPtr;
	while (listData != NULL) {
		tempPtr = listData; // بأشروا على نفس المكان
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

template <class ItemType>
int sortedType<ItemType>::Lengthls() const
{
	return length; //O(1)
}

template <class ItemType>
void sortedType<ItemType>::ResetList()
{
	currentPos = listData; // بأشروا على نفس المكان
}

template <class ItemType>
bool sortedType<ItemType>::IsLastItem() const
{
	return (currentPos == NULL); // i am in last node
}

template <class ItemType>
void sortedType<ItemType>::GetNextItem(ItemType& item)
{
	currentPos = currentPos->next;
	item = currentPos->info; //or simply item = currentPos->next->info
}


template<class ItemType>
bool sortedType<ItemType>::IsFull() const
{
	nodeType<ItemType>* ptr;
	ptr = new nodeType<ItemType>;
	if (ptr == NULL)
		return true;
	else {
		delete ptr;
		return false;
	}
}
template <class ItemType>
void sortedType<ItemType>::printList()
{
	if (listData == NULL)
		cout << "List is empty" << endl;
	nodeType<ItemType>* location = listData;
	while (location != NULL)
	{
		cout << location->info << endl;
		location = location->next;
	}
	cout << endl;
}


int main() {

	sortedType<int> obj; //create object--> call constructor
	obj.InsertItem(1);
	obj.InsertItem(2);
	obj.InsertItem(3);
	obj.printList();

	return 0;
}
