#include <iostream>

struct ListNode {
	int data;
	ListNode *next;
};

static ListNode *createList(int n)
{
	ListNode *head, *p;
	head = p = new ListNode();
	int i = 0;
	while (i++ < n - 1)
	{
		p->data = i;
		p->next = new ListNode();
		p = p->next;
	}
	p->data = i;
	p->next = NULL;
	return head;
}

static ListNode *createListII(int n)
{
	ListNode *head, *p, *q;
	head = p = new ListNode();
	int i = 0;
	while (i++ < n - 1)
	{
		p->data = i*2;
		p->next = new ListNode();
		p = p->next;
	}
	p->data = i;
	p->next = NULL;
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

ListNode *merge(ListNode *p,ListNode *q) {
	ListNode *head=new ListNode(),*t=head;
	head->next = NULL;	
	if (p == nullptr&&q == nullptr)
		return nullptr;
	while (p && q) {
		if (p->data > q->data) {
			t->next = q;
			q = q->next;
			t = t->next;
		}
		else {
			t->next = p;
			p = p->next;
			t = t->next;
		}
	}
	if (q)
		t->next = q;
	if (p)
		t->next = p;
	t = head->next;
	delete head;
	return t;

}

void mergeTest() {
	ListNode *p = createList(3);
	printList(p);
	ListNode *q = createListII(1);
	printList(q);
	ListNode *head = merge(p, q);

	printList(head);
}