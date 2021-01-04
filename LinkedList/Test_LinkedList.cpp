#include "LinkedList.h"

void Print_State_Of_SLL(Node* List) 
{ 
    int i = 0; 
    int Count = SLL_GetNodeCount(List); 
    Node* Current = List; 
    printf("-----------------------------\n"); 
    printf("- Current Linked List State -\n"); 
    printf("-----------------------------\n"); 
    if (Count) 
    { 
        for (i = 0; i < Count; i++) 
        { 
            printf("%d -> ", Current->Data); 
            Current = Current->NextNode; 
        } 
        printf("\n"); 
    }
    else 
    { 
        printf("Doesn't Exist Current Linked List\n");
    }
}


int main(void)
{
    int   i = 0;
    int   Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    /*  ��� 5�� �߰� */
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    //NewNode = SLL_CreateNode(-2);
    //SLL_InsertNewHead(&List, NewNode);

    /*  ����Ʈ ��� */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /*  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� */
    printf("\nInserting 3000 Before [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    
    SLL_InsertBefore(&List, Current, NewNode);

    /*  ����Ʈ ��� */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    SLL_PrintReverse(List);

    /*  ��� ��带 �޸𸮿��� ����     */
    printf("\nDestroying List...\n");

    SLL_DestroyAllNodes(&List);
    Print_State_Of_SLL(List);

 /*   for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
             
        }
    }*/

    return 0;
}
