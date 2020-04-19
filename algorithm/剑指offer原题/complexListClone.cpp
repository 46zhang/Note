#include<iostream>

/*
算法名称：复制复杂链表
算法来源：剑指Offer 面试题35
算法思想：		算法分成3步
					1. 复制链表，每个节点后面都是复制节点
					2. 设置m_pSibling指针
					3. 拆分链表

算法注意：		1.边界检查
				2.结尾NULL指针的设置
算法效率分析:	时间复杂度O(n)，空间复杂度O(1)
算法实现时间:	花了半个小时实现算法，花了半个小时debug

*/

struct ComplexListNode {
	int m_nvalue;
	ComplexListNode * m_pNext;
	ComplexListNode * m_pSibling;
};
static ComplexListNode *createList(int n)
{
	ComplexListNode *head, *p, *q=nullptr;
	head = p = new ComplexListNode();
	int i = 0;
	while (i++ < n-1)
	{
		
		p->m_nvalue = i;
		q = p;
		p->m_pNext = new ComplexListNode();
		p = p->m_pNext;
		p->m_pSibling = nullptr;
		
	}
	p->m_nvalue = i ;
	p->m_pNext = NULL;
	p->m_pSibling = nullptr;
	head->m_pSibling = head->m_pNext->m_pNext;
	head->m_pNext->m_pSibling = p;
	q->m_pSibling = head->m_pNext;
	return head;
}
static void printList(ComplexListNode * head)
{
	ComplexListNode *p = head;
	while (p) {
		if(p->m_pSibling)
			std::cout <<"该节点的值为: "<< p->m_nvalue << "  "<<"m_pSibling的值为: "<<p->m_pSibling->m_nvalue<<std::endl;
		else
			std::cout << "该节点的值为: " << p->m_nvalue << "  " << "m_pSibling的值为: 空 " << std::endl;
		p = p->m_pNext;
	}
	std::cout << std::endl;
}
bool connectNewComplexList(ComplexListNode ** head) {
	ComplexListNode *p = *head, *q = p;
	if (head == NULL || *head == NULL)
		return false;
	while (p) {
		q = new ComplexListNode();
		q->m_nvalue = p->m_nvalue;
		q->m_pSibling = nullptr;
		//开始拼接
		q->m_pNext = p->m_pNext;
		//std::cout << q->m_nvalue << "  ";
		p->m_pNext = q;
		if (q->m_pNext == NULL)
			break;
		p = q->m_pNext;
	}
	return true;
}
bool copySiblingPtr(ComplexListNode * head) {
	ComplexListNode * p = head;
	while (p && p->m_pNext) {
		if(p->m_pSibling)
		//这一步是关键，每个节点的pnext都是复制节点，所以节点的下一个节点就是复制节点
			p->m_pNext->m_pSibling = p->m_pSibling->m_pNext;
		//跳过复制节点
		p = p->m_pNext->m_pNext;
	}
	return true;
}

//开始拆分复制链表
ComplexListNode * createNewListFormConnectList(ComplexListNode *head) {
	ComplexListNode *newList,*p;
	p = newList = head->m_pNext;
	head = head->m_pNext->m_pNext;
	std::cout << p->m_nvalue << "  ";
	//注意结尾nullptr的复制
	while (head&&head->m_pNext) {
		p->m_pNext = head->m_pNext;
		p = p->m_pNext;
		std::cout << p->m_nvalue << "  ";
		//改变Head的next指针的指向
		head = head->m_pNext->m_pNext;
	}
	
	return newList;
}
ComplexListNode * clone(ComplexListNode *p)
{
	//先将俩个链表链接起来，每个节点后面都是复制节点
	connectNewComplexList(&p);
	//开始设置m_pSibling
	copySiblingPtr(p);
	//产生新的链表
	ComplexListNode *q= createNewListFormConnectList(p);
	return q;
}

void complexListCloneTest() {
	ComplexListNode *p = createList(5);
	printList(p);
	ComplexListNode *q = clone(p);
	std::cout << "新链表" << std::endl;
	printList(q);
}