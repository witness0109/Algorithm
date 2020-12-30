#include "DoublyLinkedList.h"

/*  노드 생성 */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/*  노드 소멸 */
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  헤드 노드가 NULL이라면 새로운 노드가 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        printf("New Node Inserted <HeadNode> : NewNode's Data = %d \n", NewNode->Data);
    }
    else
    {
        /*  테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; /*  기존의 테일을 새로운 테일의 PrevNode가 가리킨다. */
        printf("New Node Inserted            : NewNode's Data = %d \n", NewNode->Data);
    }
    
}

/*  노드 삽입 */
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

/*  노드 제거 */
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

/*  노드 탐색 */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  노드 수 세기 */
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

/* 노드 역순 */
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
    printf("=========================매개변수===================\n");
    printf("Head: %d\n", *Head);
    printf("Current: %d\n", Current->Data);
    printf("NewHead: %d\n", NewHead->Data);
    printf("=========================매개변수===================\n");

    printf("New Node Inserted            : NewHead's Data = %d \n", NewHead->Data);

    Node* Temp_Cur = *Head;

    printf("변경 전 Temp_Cur -> Data: %d\n", Temp_Cur->Data);

    if (Temp_Cur != NULL && Temp_Cur->NextNode != Current)
        Temp_Cur = Temp_Cur->NextNode;

    printf("변경 후 Temp_Cur -> Data: %d\n", Temp_Cur->Data);

    Temp_Cur->NextNode = NewHead;
    NewHead->NextNode = Current;

    printf(" Temp_Cur->Data: %d\n", Temp_Cur->Data);
    printf(" NewHead->Data: %d\n", NewHead->Data);
}

/* 헤드 삽입 */
void  DLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ((*Head) == NULL) // 헤드가 존재하지 않을시 새로운 노드가 Head
    {
        *Head = NewHead;
        printf("New Head Inserted <Head Node> : NewNode's Data = %d \n", NewHead->Data);
    }
    else
    {
        NewHead->NextNode = (*Head); // 새로운 노드의 NextNode가 기존의 Head가 되고

        // SLL->DLL로 변경하면서 새로 생긴 부분 
        (*Head)->PrevNode = NewHead;
        (*Head) = NewHead;
        printf("New Head Inserted <Head Node> : NewNode's Data = %d \n", NewHead->Data);
    }
}