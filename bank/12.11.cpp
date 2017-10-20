#include"stdafx.h"
#include "12.10.h"
#include <cstdlib>

Queue::Queue(int qs	):qsize(qs)                     //���캯��������Ĭ��ֵΪ10����qs��ֵ���򸲸�
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()                                     //��������
{
	node *temp;
	while(front!=nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const                        //����Ϊ��
{
	return items==0;
}

bool Queue::isfull() const                         //��������
{
	return items==qsize;
}

int Queue::queuecount() const                     //����ڵ���Ŀ
{
	return items;
}

bool Queue::enqueue(const Item & item)            //����β���� �˿� ����
{
	if(isfull())                                  //����������false
	   return false;
	node*add = new node;                          //�����½ڵ㲢��ֵ
	add->item = item;
	add->next = nullptr;
	if (front == nullptr)                         //������Ϊ�գ���Ϊ�׽ڵ� 
		front = add;
	else
		rear->next = add;                         //������Ϊβ�ڵ��next
	items++;                                      //�ڵ���� +1
	rear = add;                                   //��Ϊβ�ڵ�
	return true;
}

bool Queue::dequeue(Item & item)                  //����ͷɾ�� �˿� ����
{
	if (isempty())                                //���գ�����false
		return false;
	item = front->item;                           //�׽ڵ��� �˿� ���󱸷�
	node *temp = front;                           //�� �׽ڵ� ���б���
	front = front->next;                          //�׽ڵ�ı�
	delete temp;                                  //ɾ�� ԭ �׽ڵ�
	items--;                                      //�ڵ����-1
	if (front == nullptr)                         //��  if (items==0)  
		rear = nullptr;
	return true;
}
