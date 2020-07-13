#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include <algorithm>
#include <array>
#include <list>
#include <vector>

const int MaxSize = 100;    //队列的最大容量
using namespace std;
/*数据元素结构体，两个属性*/
struct DataType
{
    int priority;     //优先级数值
    int data;         //数据域
};

/*队列结构体，顺序结构*/
struct Queue
{
    DataType list[MaxSize];
    int size;         //元素个数
};

/*初始化*/
void queueInitiate(Queue *queue)
{
    queue->size = 0;
}

/*入队*/
void queueAppend(Queue *queue,DataType node)
{
    Queue *p = queue;
    int n = p->size;        //获取队列的元素个数
    p->list[n] = node;      //将data数据添加到队列最后一个元素的后面
    p->size++;
}

/*考虑优先级出队*/
int deleteData(Queue *queue,DataType *node)
{
    Queue  *p = queue;
    if (queue->size <= 0)
    {
        return -1;
    }
    int number = p->size;
    int maxPriority = -1;
    int index = 0;

    for (int i = 0; i < number; i++)
        if (p->list[i].priority > maxPriority)
        {
            maxPriority = p->list[i].priority;
            index = i;
        }
		else if (p->list[i].priority == maxPriority)
		{
			if (p->list[i].priority >= p->list[index].priority)
				{
					for (int j = index; j < number - 1; j++) //在队列中删除数据结点
        				p->list[j] = p->list[j + 1];
					index = i - 1;
					p->size--;
				}
			else
			{
				for (int j = i; j < number - 1; j++) //在队列中删除数据结点
        				p->list[j] = p->list[j + 1];
					p->size--;
			}
		}
    *node = p->list[index]; //找到删除的数据结点，并由data带出
	cout << ("%d",p->list[index].data);
    for (int i = index; i < number - 1; i++) //在队列中删除数据结点
        p->list[i] = p->list[i + 1];
    p->size--;             //结点个数减一
	return 0;
}

/*遍历输出队列*/
void queuePrint(Queue *queue)
{
    Queue *p = queue;
    for (int i = 0; i < p->size; i++)
        printf("%d  ",p->list[i].data);
    printf("\n");
    return;
}

list<int> GetStringByNumArr(string str);

char numarr[] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
};

list<int> GetStringByNumArr(string str) {

	list<int> numlist;
	int startIndex = 0;

	while (startIndex != -1)
	{
		vector<char> tempnum;

		startIndex = -1;

		for (size_t i = 0; i < str.length(); i++)
		{
			for (size_t j = 0; j < (sizeof(numarr) / sizeof(numarr[0]) - 1); j++)
			{
				if (str[i] == numarr[j])
				{
					startIndex = i;
					break;
				}
			}

			if (startIndex != -1)
			{
				tempnum.push_back(str[startIndex]);
				int tempindex = 0;

				//向下查找数据
				char tempchar = str[startIndex + (tempindex += 1)];

				//表示为数字
				while (int(tempchar - 48) >= 0 && int(tempchar - 48) <= 9)
				{
					tempnum.push_back(tempchar);
					tempchar = str[startIndex + (tempindex += 1)];
				}

				//删除查询到的数据
				str.erase(startIndex, tempindex);
				break;
			}
		}

		if (!tempnum.empty()) {
			//cout << "tempnum : " << string(tempnum.begin(), tempnum.end()) << endl;
			numlist.push_back(stoi(string(tempnum.begin(), tempnum.end())));
		}
	}

	return numlist;
}


int main()
{
    Queue queue;
    Queue *p = &queue;
    array<DataType, 100> value;
    string receive;
    DataType *q = (DataType*)malloc(sizeof(DataType));
    queueInitiate(p);
    cin >> receive;
    list <int> nums = GetStringByNumArr(receive);
		int i = 0;
		for (list<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			q->data = *it;
			it++;
			q->priority = *(it);
			i++;
            queueAppend(p, *q);
		}
    /*建立一条具有n个数据的队列*/

    //queuePrint(p);
    //system("pause");
	
    for(int i = 0; i < p->size; i++)
	{
		deleteData(p,q);
	}
    //printf("%d %d\n", q->data, q->priority);
    //system("pause");
    return 0;
}
