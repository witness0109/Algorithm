#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

/* �Լ� ���� ���� */
Node* DLL_CreateNode(ElementType NewData);
void  DLL_DestroyNode(Node* Node);
void  DLL_AppendNode(Node** Head, Node* NewNode); //��� �߰� �Լ� - LinkedList �� Tail�� �߰�
void  DLL_InsertAfter(Node* Current, Node* NewNode); //Current ��� �ڿ� NewNode�� �����ϴ� �Լ�
void  DLL_InsertNewHead(Node** Head, Node* NewHead); // ���ο� ��带 Head�� ����� �Լ�
void  DLL_RemoveNode(Node** Head, Node* Remove); //��� ���� - ������ ����� �޸� ���� ��ɱ��� ��ü �߰�
Node* DLL_GetNodeAt(Node* Head, int Location); // 
int   DLL_GetNodeCount(Node* Head);

/* Vitamin Quiz */
void PrintReverse(Node* Head);

/* Vitamin Quiz */
void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void DLL_DestroyAllNodes(Node** List);

#endif DOUBLY_LINKEDLIST_H