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

/* 함수 원형 선언 */
Node* DLL_CreateNode(ElementType NewData);
void  DLL_DestroyNode(Node* Node);
void  DLL_AppendNode(Node** Head, Node* NewNode); //노드 추가 함수 - LinkedList 끝 Tail에 추가
void  DLL_InsertAfter(Node* Current, Node* NewNode); //Current 노드 뒤에 NewNode를 삽입하는 함수
void  DLL_InsertNewHead(Node** Head, Node* NewHead); // 새로운 노드를 Head로 만드는 함수
void  DLL_RemoveNode(Node** Head, Node* Remove); //노드 제거 - 제거할 노드의 메모리 해제 기능까지 자체 추가
Node* DLL_GetNodeAt(Node* Head, int Location); // 
int   DLL_GetNodeCount(Node* Head);

/* Vitamin Quiz */
void PrintReverse(Node* Head);

/* Vitamin Quiz */
void DLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void DLL_DestroyAllNodes(Node** List);

#endif DOUBLY_LINKEDLIST_H