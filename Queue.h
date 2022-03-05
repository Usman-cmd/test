#pragma once
#include<iostream>
using namespace std;
class Queue
{
private:
	int*arr;
	int front;
	int rear;
	int maxSize;
protected:
	void deepcopy(const int *tobecopied, int*& incopy);
public:
	Queue(int maxSize = 20);
	Queue(const Queue&obj);
	bool empty();
	bool full();
	int size();
	void enqueue(int val);
	int dequeue();
	void rearrange(int position);
	void ShowQueue(const Queue &obj);
	~Queue();
};
void Queue::deepcopy(const int *tobecopied, int*& incopy)
{
	if (incopy != nullptr)
	{
		delete[]incopy;
		incopy = nullptr;
	}
	incopy = new int[this->maxSize]();
	for (int i = 0; i < this->rear; i++)
		incopy[i] = tobecopied[i];
}
Queue::Queue(int maxSize)
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
	this->arr = new int[maxSize]();
	this->maxSize = maxSize;
	this->front = 0;
	this->rear = 0;
}
Queue::Queue(const Queue&obj)
{
	this->maxSize = obj.maxSize;
	this->front = obj.front;
	this->rear = obj.rear;
	deepcopy(obj.arr,this->arr);
}
bool Queue::empty()
{
	if (this->front == this->rear)
		return true;
	else
		return false;
}
bool Queue::full()
{
	if (this->rear == this->maxSize)
		return true;
	else
		return false;
}
int Queue::size()
{
	return this->maxSize;
}
void Queue::enqueue(int val)
{
	if (!full())
	{
		this->arr[this->rear] = val;
		this->rear++;
	}
	else
		cout << " Queue is already Full : " << endl;
}
int Queue::dequeue()
{
	if (!empty())
	{
		return this->arr[this->front];
		rearrange(this->rear);
	}
	else
	{
		cout << " Queue is already empty : " << endl;
		return -1;
	}
}
void Queue::ShowQueue(const Queue &obj)
{
	cout << " Required data is : "<< endl;
	for (int i = 0; i < obj.rear; i++)
		cout << " " << obj.arr[i];
	cout << endl;
}
void Queue::rearrange(int position)
{
	for (int i = 0; i < position-1; i++)
		this->arr[i] = this->arr[i + 1];
	this->rear--;
}
Queue::~Queue()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
}
