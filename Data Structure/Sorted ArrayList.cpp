#include<iostream>
using namespace std;
template<class ItemType>
class SortedType
{
public:
SortedType(); //constructor
void MakeEmpty();
bool IsFull() const;
int Lengthls() const;
void RetrievedItem(ItemType&, bool&); //linear search
void InsertItem(ItemType);
void DeleteItem(ItemType);
void ResetList();
bool IsLastItem();
void GetNextItem(ItemType&);
void printList() const;
void SplitLists(SortedType<ItemType>& list, ItemType item, SortedType<ItemType>& list1, SortedType<ItemType>& list2);
private:
int length;
ItemType info[100];
int currentPos;
};
template<class ItemType>
SortedType<ItemType>::SortedType()
{
cout << "Object is created" << endl;
length = 0;
}
template<class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
length = 0;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
{
return(length == 100);
}
template<class ItemType>
int SortedType<ItemType>::Lengthls() const
{
return length;
}
//linear search algorithm
template<class ItemType>
void SortedType<ItemType>::RetrievedItem(ItemType& item, bool& found)
{
found = false;
int location = 0;
while ((location < length) && !found)
{
if (item > info[location])
location++;
else if (item < info[location])
location = length;
else
{
cout << "item found" << endl;
found = true;
item = info[location];
}
}
}
template<class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
int location = 0;
bool found;
found = false;
while ((location < length) && !found)
{
if (item < info[location])
found = true;
else
location++;
}
for (int index = length; index > location; index--)
info[index] = info[index - 1];
info[location] = item;
length++;
}
template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
int location = 0;
while (item != info[location])
location++;
for (int index = location + 1;index < length;index++)
info[index - 1] = info[index];
length--;
}
template<class ItemType>
void SortedType<ItemType>::ResetList()
{
currentPos = -1;
}
template<class ItemType>
bool SortedType<ItemType>::IsLastItem()
{
return(currentPos == length - 1);
}
template<class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
item = info[currentPos + 1];
}
template<class ItemType>
void SortedType<ItemType>::printList() const
{
for (int i = 0; i < length; i++)
cout << info[i] << ' ';
cout << endl;
}
//split list into two lists
template<class ItemType>
void SortedType<ItemType>::SplitLists(SortedType<ItemType>& list, ItemType item, SortedType<ItemType>& list1, SortedType<ItemType>& list2)
{
cout << "start splitting" << endl;
ItemType listItem;
list1.MakeEmpty();
list2.MakeEmpty();
list.ResetList();
while (!list.IsLastItem())
{
cout << "***********" << endl;
list.GetNextItem(listItem);
if (listItem > item)
list2.InsertItem(listItem);
else
list1.InsertItem(listItem);
} //end while
list1.printList();
list2.printList();
cout << "end splitting" << endl;
}
int main()
{
cout << "Create an array of integer:" << endl;
SortedType<int> s1; //create objects
cout << "Insert three items (20, 10, 30)" << endl;
s1.InsertItem(20);
s1.InsertItem(10);
s1.InsertItem(30);
cout << "Print the content of the created array:" << endl;
s1.printList();
cout << "\Delete item (20) then print the array again:"<<endl;
s1.DeleteItem(20);
s1.printList();
cout << "Retrieve item (10):" << endl;
bool b;
int x = 10;
s1.RetrievedItem(x, b);
//SortedType<string> s2;
return 0;
}