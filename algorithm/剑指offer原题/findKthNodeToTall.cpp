#include <iostream>
#include <stdlib.h>
#include <conio.h>

/*
�㷨���ݣ�	�ҵ��������ĵ�k���ڵ�
�㷨��Դ��	��ָOffer��һ�µ�������
�㷨˼�룺	ʹ����������ڵ㣬ͬʱָ��ͷ�ڵ㣬һ������k-1���������ڵ������k-1
			�����нڵ��ߵ������βʱ������Ľڵ���ǵ�����k���ڵ�
�㷨ע�⣺	1.�����ж�
			2.�ڲ��ҹ�����ע������ڵ��Ƿ�Ϊ�գ����ܳ���k>�����ȵ����

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
	//ʹ���������������
	for (int i = 0; i < num-1; i++)
	{
		head->data = (rand() % (b - a + 1)) + a;
		head->next = (ListNode *)malloc(sizeof(ListNode));
		head = head->next;
	}
	head->data = (rand() % (b - a + 1)) + a;
	head->next = NULL;
	//std::cout << "��������" << std::endl;
	//printList(L);
	return L;
}


ListNode * findKthNodeToTail(ListNode * L,int k)
{
	ListNode *ahead = L, *behind = L, *head = L;
	int i;
	if (ahead == NULL)
		return NULL;
	//��������ָ����k-1����������������ָ�����ľ������k-1
	//������ָ�뵽�������βʱ������ָ��������λ�þ��Ǿ����β�ĵ�����k���ڵ�
	for (i = 0; ahead&&i < k-1 ; i++)
		ahead = ahead->next;
	//std::cout << " ��ʱahead��ָλ�� " << ahead->data << " i��λ��" << i << std::endl;
	//˵��k�ĳ��ȴ��������ȣ���ʱ����null
	if (ahead == NULL && i <= k - 1)
		return NULL;
	//������ָ�뵽�������βʱ������ָ��������λ�þ��Ǿ����β�ĵ�����k���ڵ�
	while (ahead->next)
	{
		ahead = ahead->next;
		behind = behind->next;
	}
	std::cout << " ��ʱbehind��ָλ�� " << behind->data<<std::endl;
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
		std::cout << "ѭ�������� " << i << std::endl;
		int a = 0, b = 10, num = (rand() % (b - a + 1)) + a, k = (rand() % (b - a + 1)) + a;
		ListNode *L = createList(num), *n;
		std::cout << " num: " << num << " k " << k << std::endl;
		std::cout << "����������ʾ����" << std::endl;
		printList(L);
		n = findKthNodeToTail(L, k);
		if (n != NULL)
			std::cout << "������k���ڵ���" << n->data << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
	getchar();
	
}
