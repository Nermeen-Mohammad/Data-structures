#include <iostream>
using namespace std;
template <class Temp>
class unsortedtype {
public: // data functions (ADT : Specifications)
unsortedtype(); //constructor to initialization members
void MakeEmpty();
int LengthIs() const;
bool IsFull() const;
void RetrievedItem(Temp&, bool&);
void InsertItem(Temp);
void DeleteItem(Temp);
bool IsLastItem();
void ResetList();
void GetNextItem(Temp&);
void PrintList() const;
private: // data members
int length;
int currentPos;
int info[100];
};
//Now we will implement the functions (implementation)
template < class Temp >
unsortedtype <Temp> ::unsortedtype() {
length = 0;
}
template < class Temp >
void unsortedtype <Temp> ::MakeEmpty() {
length = 0;
}
template < class Temp >
int unsortedtype <Temp> ::LengthIs() const {
return length;
}
template < class Temp >
bool unsortedtype <Temp> ::IsFull() const {
return (length == 100);
}
template < class Temp >
void unsortedtype <Temp> ::RetrievedItem(Temp& item, bool& found) {
int location = 0;
found = false;
while ((location < length) && !found)
if (item == info[location]) {
found = true;
item = info[location];
}
else
location++;
}
template < class Temp >
void unsortedtype <Temp> ::InsertItem(Temp item) {
info[length] = item;
length++;
}
template < class Temp >
void unsortedtype <Temp> ::DeleteItem(Temp item) {
int location = 0;
while (item != info[location])
location++;
info[location] = info[length - 1];
length--;
}
template < class Temp >
bool unsortedtype <Temp> ::IsLastItem() {
return (currentPos == length - 1);
}
template < class Temp >
void unsortedtype <Temp> ::ResetList() {
currentPos = -1;
}
template < class Temp >
void unsortedtype <Temp> ::GetNextItem(Temp& item) {
currentPos++;
item = info[currentPos];
//item = info[currentPos + 1]; طريقة ثانية
}
template <class Temp>
void unsortedtype <Temp> ::PrintList() const {
for (int i = 0; i < length; i++)
cout << info[i] << " ";
}
int main() {
cout << "Create an array of int :\n ";
unsortedtype <int> obj;
cout << "Insert 3 items (100,200,300) : \n";
obj.InsertItem(100);
obj.InsertItem(200);
obj.InsertItem(300);
cout << "Print the content of the created array : \n";
obj.PrintList();
cout << "\nDelete item 200 then print the array again :\n";
obj.DeleteItem(200);
obj.PrintList();
cout << "\nRetrieve item 100 : \n";
bool b;
int a = 100;
obj.RetrievedItem(a, b);
return 0;
}