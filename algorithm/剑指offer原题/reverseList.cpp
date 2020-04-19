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
	while (i++ < n - 1)
	{

		p->data = i;
		
		p->next = new ListNode();
		p = p->next;
	}
	p->data = i;
	p->next = q;
	return head;
}
static void  printList(ListNode * head)
{
	ListNode *p = head;
	int i = 0;
	while (p) {
		std::cout << p->data << "  ";
		p = p->next;
	}
	std::cout << std::endl;
}

ListNode * reverstList(ListNode *head) {
	if (nullptr == head)
		return nullptr;
	ListNode *p = head,*q = p->next;
	p->next = NULL;
	while (q) {
		ListNode *temp = q->next;
		q->next = p;
		p = q;
		q = temp;
	}
	return  p;
	
}
void reverseListTest() {
	ListNode *p = createList(1);
	printList(p);
	ListNode *q = reverstList(p);
	printList(q);
}