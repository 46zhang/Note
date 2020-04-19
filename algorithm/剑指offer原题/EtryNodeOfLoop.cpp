#include <iostream>

struct ListNode {
	int data;
	ListNode *next;
};

static ListNode *createList(int n)
{
	ListNode *head, *p, *q=nullptr;
	head = p = new ListNode();
	int i = 0;
	while (i++ < n-1)
	{
		
		p->data = i;
		if (i == 5)
			q = p;
		p->next = new ListNode();
		p = p->next;
	}
	p->data = i ;
	p->next = q;
	return head;
}
static void  printList(ListNode * head)
{
	ListNode *p = head;
	int i = 0;
	while (i++<10) {
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << std::endl;
}
ListNode *meetNodeOfLoop(ListNode *head) {
	ListNode *first, *second;
	if (head == nullptr)
		return nullptr;
	first = second = head;
	//first一次走俩步，second一次走一步
	while (first!=nullptr&&second!=nullptr) {
		if(first->next)
			first = first->next->next;
		second=second->next;
		if (first == second)
			return first;
	}
	return nullptr;
}
ListNode * entryNodeOfLoop(ListNode *head) {
	ListNode *p = head,*q=head;
	if (head == NULL)
		return nullptr;
	ListNode *meetNode = meetNodeOfLoop(head), *temp;
	if (meetNode == nullptr)
		return nullptr;
	
	temp= meetNode->next;
	std::cout << "相遇的节点是： "<<meetNode->data<<'\n';
	int count = 1;
	while (temp != meetNode) {
		temp=temp->next;
		++count;
	}
	std::cout << " 环中节点个数 : "<<count << std::endl;
	//p先移动n步
	for (int i = 0; i < count; i++)
		p=p->next;
	while (p != q) {
		q=q->next;
		p=p->next;
	}
	return p;
}
void entryNodeOfLoopTest()
{
	ListNode *head;
	head=createList(10);
	printList(head);
	ListNode * p = entryNodeOfLoop(head);
	if (p == nullptr)
		std::cout << "不存在重复节点" << std::endl;
	else
		std::cout << p->data << std::endl;
}