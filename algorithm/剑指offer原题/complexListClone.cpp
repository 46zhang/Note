#include<iostream>

/*
�㷨���ƣ����Ƹ�������
�㷨��Դ����ָOffer ������35
�㷨˼�룺		�㷨�ֳ�3��
					1. ��������ÿ���ڵ���涼�Ǹ��ƽڵ�
					2. ����m_pSiblingָ��
					3. �������

�㷨ע�⣺		1.�߽���
				2.��βNULLָ�������
�㷨Ч�ʷ���:	ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	���˰��Сʱʵ���㷨�����˰��Сʱdebug

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
			std::cout <<"�ýڵ��ֵΪ: "<< p->m_nvalue << "  "<<"m_pSibling��ֵΪ: "<<p->m_pSibling->m_nvalue<<std::endl;
		else
			std::cout << "�ýڵ��ֵΪ: " << p->m_nvalue << "  " << "m_pSibling��ֵΪ: �� " << std::endl;
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
		//��ʼƴ��
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
		//��һ���ǹؼ���ÿ���ڵ��pnext���Ǹ��ƽڵ㣬���Խڵ����һ���ڵ���Ǹ��ƽڵ�
			p->m_pNext->m_pSibling = p->m_pSibling->m_pNext;
		//�������ƽڵ�
		p = p->m_pNext->m_pNext;
	}
	return true;
}

//��ʼ��ָ�������
ComplexListNode * createNewListFormConnectList(ComplexListNode *head) {
	ComplexListNode *newList,*p;
	p = newList = head->m_pNext;
	head = head->m_pNext->m_pNext;
	std::cout << p->m_nvalue << "  ";
	//ע���βnullptr�ĸ���
	while (head&&head->m_pNext) {
		p->m_pNext = head->m_pNext;
		p = p->m_pNext;
		std::cout << p->m_nvalue << "  ";
		//�ı�Head��nextָ���ָ��
		head = head->m_pNext->m_pNext;
	}
	
	return newList;
}
ComplexListNode * clone(ComplexListNode *p)
{
	//�Ƚ�������������������ÿ���ڵ���涼�Ǹ��ƽڵ�
	connectNewComplexList(&p);
	//��ʼ����m_pSibling
	copySiblingPtr(p);
	//�����µ�����
	ComplexListNode *q= createNewListFormConnectList(p);
	return q;
}

void complexListCloneTest() {
	ComplexListNode *p = createList(5);
	printList(p);
	ComplexListNode *q = clone(p);
	std::cout << "������" << std::endl;
	printList(q);
}