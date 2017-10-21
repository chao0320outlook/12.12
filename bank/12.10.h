#pragma once
#ifndef  QUEUE_H
#define  UEUE_H

class Customer                                           //顾客类
{
private:
	long arrive;                                         //顾客到达ATM时的时间
	int processtiome;                                    //顾客取款所需时间
public:
	Customer() { arrive = processtiome = 0; }            //构造函数，初值均设为0

	void set(long when);                                 //设置顾客取款所需时间
	long when()const { return arrive; };
	int ptime()const { return processtiome; };
};

typedef  Customer Item;

class Queue
{
private:
	struct node { Item item; struct node *next; };       //节点结构，一个顾客对象，一个向后指针
	enum { Q_size = 10};                                 
	node *front;                                         //链表头
	node *rear;                                          //链表尾
	int items;                                           //链表内成员个数
	const int qsize;                                     //链表节点最大值

	Queue (const Queue & q ):qsize(0){}
	Queue &operator=(const Queue &q) { return *this; }
public:
	Queue(int qs = Q_size);                              //构造函数，设置默认值为10
	~Queue();                                            //析构函数
	bool isempty()const;                                 //链表为空
	bool isfull()const;                                  //链表已满
	int queuecount()const;                               //链表节点数目
	bool enqueue(const Item &item);                      //链表尾增加顾客对象
	bool dequeue(Item&item);                             //链表头删除顾客对象

};


#endif
