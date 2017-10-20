#include"stdafx.h"
#include "12.10.h"
#include <cstdlib>

Queue::Queue(int qs	):qsize(qs)                     //构造函数，设置默认值为10，若qs有值，则覆盖
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()                                     //析构函数
{
	node *temp;
	while(front!=nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const                        //链表为空
{
	return items==0;
}

bool Queue::isfull() const                         //链表已满
{
	return items==qsize;
}

int Queue::queuecount() const                     //链表节点数目
{
	return items;
}

bool Queue::enqueue(const Item & item)            //链表尾增加 顾客 对象
{
	if(isfull())                                  //若满，返回false
	   return false;
	node*add = new node;                          //创建新节点并赋值
	add->item = item;
	add->next = nullptr;
	if (front == nullptr)                         //若链表为空，设为首节点 
		front = add;
	else
		rear->next = add;                         //否则，设为尾节点的next
	items++;                                      //节点计数 +1
	rear = add;                                   //设为尾节点
	return true;
}

bool Queue::dequeue(Item & item)                  //链表头删除 顾客 对象
{
	if (isempty())                                //若空，返回false
		return false;
	item = front->item;                           //首节点内 顾客 对象备份
	node *temp = front;                           //对 首节点 进行备份
	front = front->next;                          //首节点改变
	delete temp;                                  //删除 原 首节点
	items--;                                      //节点计数-1
	if (front == nullptr)                         //或  if (items==0)  
		rear = nullptr;
	return true;
}
