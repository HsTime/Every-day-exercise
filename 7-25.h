#pragma once

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//struct binaryTree
//{
//	int _val;
//	binaryTree* _left;
//	binaryTree* _right;
//	binaryTree(int val)
//		:_val(val)
//		, _left(NULL)
//		, _right(NULL)
//	{}
//	~binaryTree()
//	{
//		_val = 0;
//		_left = NULL;
//		_right = NULL;
//	}
//};
////1��ʵ�ֶ�������ǰ��/����/����ǵݹ����
//void preOrder(binaryTree* Node) //ǰ�����  ��->��ڵ�->�ҽ��
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	s.push(Node);
//	cout <<"ǰ�����Ϊ��";
//	while (!s.empty())
//	{
//		binaryTree* p = s.top();
//		s.pop();
//		cout << p->_val << " ";  //��ӡ�ڵ�����
//		if (p->_right != NULL)
//		{
//			s.push(p->_right);
//		}
//		if (p->_left != NULL)
//		{
//			s.push(p->_left);
//		}
//	}
//	cout << endl;
//}
//
//void inOrder(binaryTree* Node)//�������  ��ڵ�->���ڵ�->�ҽ��
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	binaryTree* p = Node;
//	cout << "�������Ϊ��";
//	while (!s.empty() || p != NULL)
//	{
//		while (p != NULL)
//		{
//			s.push(p);
//			p = p->_left;
//		}
//		binaryTree* node = s.top();
//		s.pop();
//		cout << node->_val << " ";  //��ӡ�ڵ�����
//		p = node->_right;
//	}
//	cout << endl;
//}
//
//void postOrder(binaryTree* Node)//������� ��ڵ�->�ҽ�� ->���ڵ�
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	binaryTree* p = Node;
//	cout << "�������Ϊ��";
//	binaryTree* prev = NULL;
//	while (p != NULL || !s.empty())
//	{
//		while (p != NULL)
//		{
//			s.push(p);
//			p = p->_left;
//		}
//		binaryTree* node = s.top();
//		if (prev == node->_right || node->_right == NULL)
//		{
//			cout << node->_val << " ";
//			prev = node;
//			s.pop();
//		}
//		else
//		{
//			p = node->_right;
//		}
//	}
//	cout << endl;
//}
//
//void Text()
//{
//	binaryTree* node = new binaryTree(1);
//	binaryTree* node1 = new binaryTree(2);
//	binaryTree* node2 = new binaryTree(3);
//	binaryTree* node3 = new binaryTree(4);
//	binaryTree* node4 = new binaryTree(5);
//	binaryTree* node5 = new binaryTree(6);
//	binaryTree* node6 = new binaryTree(7);
//
//	node->_left = node1;
//	node->_right = node2;
//	node1->_left = node3;
//	node3->_left = node4;
//	preOrder(node);
//	inOrder(node);
//	postOrder(node);
//}
//2����֪����A��B��Ԫ�طֱ��ò���ͷ���ĵ�����洢������difference()������⼯��A��B�Ĳ��������������ڼ���A�ĵ������С����磬������A={5,10,20,15,25,30}������B={5,15,35,25}����ɼ����A={10,20,30}�� 
//������Ľṹ���Ͷ������£�����ɺ���void difference(node** LA, node* LB)��
struct node
{
	int elem;
	node* next;
	node(int val)
		:elem(val)
		, next(NULL)
	{}
};

void difference(node** LA, node* LB)
{
	assert(*LA);
	assert(LB);
	node* head = NULL;
	node* begin = NULL;
	node* node1 = *LA;
	node* p2 = LB;
	while (node1 != NULL)
	{
		int flag = 0;

		node* prev2 = NULL;
		node* node2 = p2;
		while (node2 != NULL)
		{
			if (node1->elem == node2->elem)
			{
				flag = 1;
				(prev2 == NULL) ? (p2 = node2->next) : (prev2->next = node2->next);
				break;
			}
			else
			{
 				prev2 = node2;
				node2 = node2->next;
				continue;
			}
		}
		if (flag  == 0)
		{
			if (begin == NULL)
				head = begin = node1;
			else
			{
				begin->next = node1;
				begin = begin->next;
			}
		}
		node1 = node1->next;
	}
	*LA = head;
}
void Text()
{
	node* A = new node(5);
	node* A1 = new node(10);
	node* A2 = new node(20);
	node* A3 = new node(15);
	node* A4 = new node(25);
	node* A5 = new node(30);
	A->next = A1;
	A1->next = A2;
	A2->next = A3;
	A3->next = A4;
	A4->next = A5;

	node* B = new node(5);
	node* B1 = new node(35);
	node* B2 = new node(25);
	node* B3 = new node(15);
	B->next = B1;
	B1->next = B2;
	B2->next = B3;
	difference(&A, B);
}
