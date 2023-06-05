//Student : Nermeen Mohammad Almomani

#include <iostream>
using namespace std;

template<class ItemType>
class QueueType {
public:
	QueueType(int);
	~QueueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType);
	void Dequeue(ItemType&);
	void print();
private:
	int front;
	int rear;
	ItemType* items;
	int maxQue;
};

template<class ItemType>
QueueType<ItemType>::QueueType(int max)
{
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
		items = new ItemType[maxQue];
}

template<class ItemType>
QueueType<ItemType>::~QueueType()
{
	delete[] items;
}

template<class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
	front = maxQue - 1;
	rear = maxQue - 1;
}

template<class ItemType>
bool QueueType<ItemType>::IsEmpty() const
{
	return (rear == front);
}
template<class ItemType>
bool QueueType<ItemType>::IsFull() const
{
	return ((rear + 1) % maxQue == front);
}
template<class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
	rear = (rear + 1) % maxQue;
	items[rear] = newItem;
}
template<class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item)
	{
	front = (front + 1) % maxQue;
	item = items[front];
	}

template <class ItemType>
void QueueType<ItemType>::print() {


	for (size_t i = 0 ; i != rear; i = (i + 1) % maxQue) {
		cout << items[i] << " ";
	}
	cout << items[rear];
}
int main() {

	QueueType <int> obj (5);
	
	obj.Enqueue(34);
	obj.Enqueue(239);
	obj.Enqueue(79);
	obj.Enqueue(98);
	
	obj.print();

	return 0;

}
