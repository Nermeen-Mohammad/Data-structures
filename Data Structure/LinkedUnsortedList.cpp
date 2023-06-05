// UnsortedLinkedList.cpp: This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;
// Creating a node as struct
template<class ItemType>
struct NodeType {
ItemType info;
NodeType* next;
};
template<class ItemType>
class UnsortedType
{
public:
UnsortedType(); //constructor
~UnsortedType(); //destructor
void MakeEmpty();
bool IsFull() const;
int Lengthls() const;
void RetrieveItem(ItemType&, bool&);
void InsertItem(ItemType);
void DeleteItem(ItemType);
void ResetList();
bool IsLastItem() const;
void GetNextItem(ItemType&);
void printList();
private:
int length;
NodeType<ItemType>* listData;
NodeType<ItemType>* currentPos;
};
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
cout << "Object is created" << endl;
length = 0;
listData = NULL;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
MakeEmpty();
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
NodeType<ItemType>* tempPtr;
while (listData != NULL) {
tempPtr = listData;
listData = listData->next;
delete tempPtr;
}
length = 0;
}
template <class ItemType>
int UnsortedType<ItemType>::Lengthls() const
{
return length; //O(1)
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
currentPos = listData;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
NodeType<ItemType>* location;
location = listData;
found = false;
while (location != NULL && !found)
{
if (location->info == item)
{
found = true;
item = location->info;
}
else
location = location->next;
}
}
template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
{
NodeType<ItemType>* location = new NodeType<ItemType>;
location->info = item;
location->next = listData;
listData = location;
length++;
}
template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
{
NodeType<ItemType>* location = listData;
NodeType<ItemType>* tempLocation;
tempLocation = location;
if (item == listData->info)
listData = listData->next;
else
{
while ((!(location->next)->info == item))
location = location->next;
tempLocation = location->next;
}
//delete the node
location->next = (location->next)->next;
delete tempLocation;
length--;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsLastItem() const
{
return (currentPos == NULL);
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
{
currentPos = currentPos->next;
item = currentPos->info; //or simply item = currentPos->next->info
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
{
NodeType<ItemType>* ptr;
ptr = new NodeType<ItemType>;
if (ptr == NULL)
return true;
else {
delete ptr;
return false;
}
}
template <class ItemType>
void UnsortedType<ItemType>::printList()
{
if (listData == NULL)
cout << "List is empty" << endl;
NodeType<ItemType>* location = listData;
while (location != NULL)
{
cout << location->info << " ";
location = location->next;
}
cout << endl;
}
int main() {
UnsortedType<int> l1; //call constructor
l1.InsertItem(13);
l1.InsertItem(8);
l1.InsertItem(10);
l1.printList();
//NodeType<int>* head;
//NodeType<int>* one = NULL;
//NodeType<int>* two = NULL;
//NodeType<int>* three = NULL;
//// allocate 3 nodes in the heap
//one = new NodeType<int>();
//two = new NodeType<int>();
//three = new NodeType<int>();
//// Assign value values
//one->info = 1;
//two->info = 2;
//three->info = 3;
// Connect nodes
//one->next = two;
//two->next = three;
//three->next = NULL;
//// print the linked list value
//head = one;
//while (head != NULL) {
// cout << head->info<<"->";
// head = head->next;
//}
}