// bank.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "12.10.h"

using namespace std;

const int MIN_FER_HR = 60;
bool newcustomer(double x);

int main()
{
	srand(time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;                                                              //队列最大值
	cin >> qs;
	Queue line(qs);                                                      //构造一个队列对象

	cout << "Enter the number of simulation hours: ";
	int hours;                                                           //模拟小时数
	cin >> hours;
	long cyclelimit = MIN_FER_HR*hours;                                  //总模拟时长

	cout << "Enter the average number of customer per hour: ";
	double perhour;                                                      //每小时顾客数
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_FER_HR / perhour;                                 //顾客出现的平局时长即：平均每过min_per_cust出现一位顾客

	Item temp;                                                           //顾客对象
	long turnaways = 0;                                                  //拒绝插入队列人次
	long customers = 0;                                                  //已排队人数
	long served = 0;                                                     //已服务人数
	long sum_line = 0;
	int wait_time = 0;                                                   //第二个人需要等待的时间
	long line_wait = 0;                                                  //总排队消耗时间

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;                             //拒绝插入队列人次+1
			else
			{
				customers++;                             //
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if(wait_time<=0 && !line.isempty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;                                    //已服务人数+1
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	if (customers > 0)
	{
		cout << "Customers acceptd: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "        turnaways: " << turnaways << endl;
		cout << "average queue size: ";

		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);

		cout << (double)sum_line / cyclelimit << endl;             //平均队列长度
		cout << "average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!" << endl;

	int secs = 60;                                   //延时60s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}