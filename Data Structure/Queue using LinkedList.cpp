// Student : Nermeen Mohammad Almomani

#include <iostream>
using namespace std;

template<class ItemType>
	struct NodeType { ItemType info; 
	struct NodeType next;
	};

	template<class ItemType>
		class QueueType{
public:
	QueueType();
	~QueueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void print();

private:
	NodeType <ItemType >* qFront;
	NodeType <ItemType >* qRear;
};

		template <class ItemType>
		void QueueType<ItemType>::Enqueue(ItemType newItem)
		{
			NodeType<ItemType>* newNode;
			newNode = new NodeType<ItemType>;
			newNode->info = newItem;
			newNod->next = NULL;
			if (qRear == NULL)
				qFront = newNode;
			else
				qRear->next = newNode;
					qRear = newNode;
		}


		template <class ItemType>
		void QueueType<ItemType>::Dequeue(ItemType& item)
		{
			NodeType<ItemType>* tempPtr;
			tempPtr = qFront;
			item = qFront->info;
			qFront = qFront->next;
			if (qFront == NULL)
				qRear = NULL;
			delete tempPtr;
		}

		template<class ItemType>
		QueueType<ItemType>::QueueType()
		{
			qFront = NULL;
			qRear = NULL;
		}
		template<class ItemType>
		void QueueType<ItemType>::MakeEmpty()
		{
			NodeType<ItemType>* tempPtr;
			while (qFront != NULL) {
				tempPtr = qFront;
				qFront = qFront->next;
					
					delete tempPtr;
			}
			qRear = NULL;
		}

		template<class ItemType>
		bool QueueType<ItemType>::IsEmpty() const
		{
			return(qFront == NULL);
		}

		template<class ItemType>
		bool QueueType<ItemType>::IsFull() const
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
		template<class ItemType>
		QueueType<ItemType>::~QueueType()
		{
			MakeEmpty();
		}

		
		int main() {

			QueueType <int> obj;

			obj.Enqueue(3);
			obj.Enqueue(4);
			obj.Enqueue(6);

			return 0;

		}
