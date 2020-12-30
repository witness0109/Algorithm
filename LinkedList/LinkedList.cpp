#include "LinkedList.h"

/*  ��� ���� */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
    NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� (�޸� ����) */
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  ��� �߰� (�� tail)�� �߰� */
void SLL_AppendNode(Node** Head, Node* NewNode)
    // Head�� �̱� �����ͷ� ����� Head�� ����Ű�� �ּҰ��� �ٲ� �� ����.
    //        ���� �����ͷ� ����� Node* Ÿ���� ����� �ּҸ� �ѱ�Ƿμ� Head�� ����Ű�� Node�� ������ ����
         
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        printf("New Node Inserted < Head Node > : NewNode's Data = %d \n", NewNode->Data);
    }
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head); // Head�� ����Ű�� Node�� �ּҷ� Tail�� �ʱ�ȭ
        while (Tail->NextNode != NULL) // 
        {
            Tail = Tail->NextNode;
        }
        // Loop�� ����� Tail�� ��ũ�� ����Ʈ�� ������ ��带 ����Ű�Ե� 
        Tail->NextNode = NewNode;
        printf("New Node Inserted               : NewNode's Data = %d \n", NewNode->Data);
            
    }
}

/*  ��� ���� */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    /* Current�� ���� ��ġ�� ������ ���� 
       NewNode�� ������ data 
     */
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;

    printf("New Node Inserted               : NewNode's Data = %d \n", NewNode->Data);

}

/* ��� ���� */
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
    Node* Temp_Cur = *Head;
    if ((*Head) == Current) // Current�� Head�� ���ٸ� - �� ��� ��� �տ� �����Ϸ��� �ҽ� 
        SLL_InsertNewHead(Head, NewHead);
    else
    {
        while (Temp_Cur != NULL && Temp_Cur->NextNode != Current)
            Temp_Cur = Temp_Cur->NextNode;
        //Remove�Լ��� loop�� �״�� Ȱ���Ͽ� Temp_Cur�� Current����� ���� ��带 ����Ű�� �Ѵ���
        Temp_Cur->NextNode = NewHead; // Temp_Cur�� NextNode�� NewHead�� �ǰ�
        NewHead->NextNode = Current; // NewHead�� NextNode�� Current�� �ǵ���
        printf("New Node Inserted               : NewNode's Data = %d \n", NewHead->Data);
    }   
 
}


void  SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if (Head == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

/*  ��� ���� */
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}

/* ��� ��� �ѹ��� ����*/
void SLL_DestroyAllNodes(Node** List)
{
    int i;
    int Count = SLL_GetNodeCount(*List);//��ü ����� ������ ���� ��
    Node* Current;

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(*List,0);
        // 0��° ��带 �����ϰ� �Ǹ� �� ���� ��尡 0�� ��尡 ��
        // ���� ����� ������ŭ �����ϸ� ��� ��� ����
        SLL_RemoveNode(List, Current);
    }
}


/*  ��� Ž�� */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}
