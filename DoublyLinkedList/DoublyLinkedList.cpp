#include "DoublyLinkedList.h"

/*  ��� ���� */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*  ��� �Ҹ� */
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  ��� �߰� */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        printf("New Node Inserted <HeadNode> : NewNode's Data = %d \n", NewNode->Data);
    }
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; /*  ������ ������ ���ο� ������ PrevNode�� ����Ų��. */
        printf("New Node Inserted            : NewNode's Data = %d \n", NewNode->Data);
    }
    
}

/*  ��� ���� */
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

/*  ��� ���� */
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
            (*Head)->PrevNode = NULL;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        if (Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Temp->NextNode;

        if (Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/*  ��� Ž�� */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int DLL_GetNodeCount(Node* Head)
{
    unsigned int  Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

/* ��� ���� */
void PrintReverse(Node* Head)
{

}

void PrintNode(Node* _Node)
{
    if (_Node->PrevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);

    printf(" Current: %d ", _Node->Data);

    if (_Node->NextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);
}


void DLL_InsertBefore(Node** Head, Node* Current ,Node* NewHead)
{
    printf("New DLL_InsertBefore Start\n");
    printf("=========================�Ű�����===================\n");
    printf("Head: %d\n", *Head);
    printf("Current: %d\n", Current->Data);
    printf("NewHead: %d\n", NewHead->Data);
    printf("=========================�Ű�����===================\n");

    printf("New Node Inserted            : NewHead's Data = %d \n", NewHead->Data);

    Node* Temp_Cur = *Head;

    printf("���� �� Temp_Cur -> Data: %d\n", Temp_Cur->Data);

    if (Temp_Cur != NULL && Temp_Cur->NextNode != Current)
        Temp_Cur = Temp_Cur->NextNode;

    printf("���� �� Temp_Cur -> Data: %d\n", Temp_Cur->Data);

    Temp_Cur->NextNode = NewHead;
    NewHead->NextNode = Current;

    printf(" Temp_Cur->Data: %d\n", Temp_Cur->Data);
    printf(" NewHead->Data: %d\n", NewHead->Data);
}

/* ��� ���� */
void  DLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ((*Head) == NULL) // ��尡 �������� ������ ���ο� ��尡 Head
    {
        *Head = NewHead;
        printf("New Head Inserted <Head Node> : NewNode's Data = %d \n", NewHead->Data);
    }
    else
    {
        NewHead->NextNode = (*Head); // ���ο� ����� NextNode�� ������ Head�� �ǰ�

        // SLL->DLL�� �����ϸ鼭 ���� ���� �κ� 
        (*Head)->PrevNode = NewHead;
        (*Head) = NewHead;
        printf("New Head Inserted <Head Node> : NewNode's Data = %d \n", NewHead->Data);
    }
}