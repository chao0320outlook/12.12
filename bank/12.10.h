#pragma once
#ifndef  QUEUE_H
#define  UEUE_H

class Customer                                           //�˿���
{
private:
	long arrive;                                         //�˿͵���ATMʱ��ʱ��
	int processtiome;                                    //�˿�ȡ������ʱ��
public:
	Customer() { arrive = processtiome = 0; }            //���캯������ֵ����Ϊ0

	void set(long when);                                 //���ù˿�ȡ������ʱ��
	long when()const { return arrive; };
	int ptime()const { return processtiome; };
};

typedef  Customer Item;

class Queue
{
private:
	struct node { Item item; struct node *next; };       //�ڵ�ṹ��һ���˿Ͷ���һ�����ָ��
	enum { Q_size = 10};                                 
	node *front;                                         //����ͷ
	node *rear;                                          //����β
	int items;                                           //�����ڳ�Ա����
	const int qsize;                                     //����ڵ����ֵ

	Queue (const Queue & q ):qsize(0){}
	Queue &operator=(const Queue &q) { return *this; }
public:
	Queue(int qs = Q_size);                              //���캯��������Ĭ��ֵΪ10
	~Queue();                                            //��������
	bool isempty()const;                                 //����Ϊ��
	bool isfull()const;                                  //��������
	int queuecount()const;                               //����ڵ���Ŀ
	bool enqueue(const Item &item);                      //����β���ӹ˿Ͷ���
	bool dequeue(Item&item);                             //����ͷɾ���˿Ͷ���

};


#endif
