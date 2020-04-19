#include <iostream>
#include <stdlib.h>
#include <conio.h>

/*
算法内容：	找到链表倒数的第k个节点
算法来源：	剑指Offer第一章的面试题
算法思想：	使用俩个链表节点，同时指向头节点，一个先走k-1步，俩个节点距离变成k-1
			当先行节点走到链表结尾时，后面的节点就是倒数第k个节点
算法注意：	1.链表判断
			2.在查找过程中注意链表节点是否为空，可能出现k>链表长度的情况

*/

typedef  int nodeData;

struct  ListNode
{
	nodeData data;
	struct ListNode *next;
	
} ;
void printList(ListNode * L);

ListNode * createList(int num)
{
	int a=1,b=1000,data=(rand() % (b - a + 1)) + a;
	ListNode *L,*head;
	L = head = (ListNode *)malloc(sizeof(ListNode));
	//使用随机数产生链表
	for (int i = 0; i < num-1; i++)
	{
		head->data = (rand() % (b - a + 1)) + a;
		head->next = (ListNode *)malloc(sizeof(ListNode));
		head = head->next;
	}
	head->data = (rand() % (b - a + 1)) + a;
	head->next = NULL;
	//std::cout << "创建链表" << std::endl;
	//printList(L);
	return L;
}


ListNode * findKthNodeToTail(ListNode * L,int k)
{
	ListNode *ahead = L, *behind = L, *head = L;
	int i;
	if (ahead == NULL)
		return NULL;
	//先让先行指针走k-1步，这样他与后面的指针相差的距离就是k-1
	//当先行指针到达链表结尾时，后行指针所处的位置就是距离结尾的倒数第k个节点
	for (i = 0; ahead&&i < k-1 ; i++)
		ahead = ahead->next;
	//std::cout << " 此时ahead所指位置 " << ahead->data << " i的位置" << i << std::endl;
	//说明k的长度大于链表长度，此时返回null
	if (ahead == NULL && i <= k - 1)
		return NULL;
	//当先行指针到达链表结尾时，后行指针所处的位置就是距离结尾的倒数第k个节点
	while (ahead->next)
	{
		ahead = ahead->next;
		behind = behind->next;
	}
	std::cout << " 此时behind所指位置 " << behind->data<<std::endl;
	return behind;
}
void printList(ListNode * L)
{
	ListNode *head = L;
	while (head)
	{
		std::cout << " data: " << head->data;
		head = head->next;
	}
	std::cout << std::endl;
}

void findKthNodeToTailTest()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "循环次数： " << i << std::endl;
		int a = 0, b = 10, num = (rand() % (b - a + 1)) + a, k = (rand() % (b - a + 1)) + a;
		ListNode *L = createList(num), *n;
		std::cout << " num: " << num << " k " << k << std::endl;
		std::cout << "主函数中显示链表" << std::endl;
		printList(L);
		n = findKthNodeToTail(L, k);
		if (n != NULL)
			std::cout << "倒数第k个节点是" << n->data << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
	getchar();
	
}
