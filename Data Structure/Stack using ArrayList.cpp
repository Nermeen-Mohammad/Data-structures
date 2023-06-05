//Student : Nermeen Mohammad Almomani

#include <iostream>
using namespace std;

const int MAX_ITEM = 100;
template <class ItemType>
class StackType {

public:
	StackType();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	void Push(ItemType newItem);
	void Pop(ItemType& item);
	void Print();
	void GetTop(ItemType& Get);
private:
	int top;
	ItemType items[MAX_ITEM];

};

template <class ItemType>
StackType <ItemType> ::StackType() {

	top = -1;
}

template <class ItemType>
void StackType <ItemType> ::MakeEmpty() {
	top = -1;
}

template <class ItemType>
void StackType <ItemType> ::Push(ItemType newItem) {
	if (IsFull())
		cout << "Stack is full";

	else

		top++;
	items[top] = newItem;
}

template <class ItemType>
void StackType <ItemType> ::Pop(ItemType& item) {
	if (IsEmpty())
		cout << "Stack is empty";
	else

		item = items[top];
	top--;

}

template <class ItemType>
bool StackType <ItemType> ::IsEmpty() {

	return (top == -1);
}

template <class ItemType>
bool StackType <ItemType> ::IsFull() {
	return (top == MAX_ITEM - 1);

}

template <class ItemType>
void StackType <ItemType> ::GetTop(ItemType& Get) {

	Get = items[top];
	cout << Get;
}



template <class ItemType>
void StackType <ItemType> ::Print() {
	cout << '[';
	for (int i = top; i >= 0; i--)
		cout << items[i] << " ";
	cout << ']';
}

int main() {

	StackType <int> obj;
	int Get;
	int val;
	obj.Push(2);
	obj.Push(8);
	obj.Push(1);
	obj.Push(13);
	obj.Push(20);

	obj.Pop(val);
	obj.Print();

	//obj.GetTop(Get);
	//obj.IsEmpty();
	//obj.IsFull();

}
