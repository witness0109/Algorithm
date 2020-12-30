#include "LinkedList.h"

/*  노드 생성 */
Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  데이터를 저장한다. */
    NewNode->NextNode = NULL; /*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */

    return NewNode;/*  노드의 주소를 반환한다. */
}

/*  노드 소멸 (메모리 해제) */
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

/*  노드 추가 (끝 tail)에 추가 */
void SLL_AppendNode(Node** Head, Node* NewNode)
    // Head를 싱글 포인터로 선언시 Head가 가리키는 주소값을 바꿀 수 없다.
    //        이중 포인터로 선언시 Node* 타입의 헤드의 주소를 넘기므로서 Head가 가리키는 Node의 변경이 가능
         
{
    /*  헤드 노드가 NULL이라면 새로운 노드가 Head */
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        printf("New Node Inserted < Head Node > : NewNode's Data = %d \n", NewNode->Data);
    }
    else
    {
        /*  테일을 찾아 NewNode를 연결한다. */
        Node* Tail = (*Head); // Head가 가리키는 Node의 주소로 Tail을 초기화
        while (Tail->NextNode != NULL) // 
        {
            Tail = Tail->NextNode;
        }
        // Loop문 수행시 Tail은 링크드 리스트의 마지막 노드를 가리키게됨 
        Tail->NextNode = NewNode;
        printf("New Node Inserted               : NewNode's Data = %d \n", NewNode->Data);
            
    }
}

/*  노드 삽입 */
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    /* Current는 현재 위치를 가지고 있음 
       NewNode는 삽입할 data 
     */
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;

    printf("New Node Inserted               : NewNode's Data = %d \n", NewNode->Data);

}

/* 노드 삽입 */
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
    Node* Temp_Cur = *Head;
    if ((*Head) == Current) // Current와 Head가 같다면 - 즉 헤드 노드 앞에 삽입하려고 할시 
        SLL_InsertNewHead(Head, NewHead);
    else
    {
        while (Temp_Cur != NULL && Temp_Cur->NextNode != Current)
            Temp_Cur = Temp_Cur->NextNode;
        //Remove함수의 loop를 그대로 활용하여 Temp_Cur가 Current노드의 앞의 노드를 가리키게 한다음
        Temp_Cur->NextNode = NewHead; // Temp_Cur의 NextNode는 NewHead가 되고
        NewHead->NextNode = Current; // NewHead의 NextNode는 Current가 되도록
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

/*  노드 제거 */
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

/* 모든 노드 한번에 제거*/
void SLL_DestroyAllNodes(Node** List)
{
    int i;
    int Count = SLL_GetNodeCount(*List);//전체 노드의 갯수를 얻은 후
    Node* Current;

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(*List,0);
        // 0번째 노드를 삭제하게 되면 그 다음 노드가 0번 노드가 됨
        // 현재 노드의 개수만큼 수행하면 모든 노드 삭제
        SLL_RemoveNode(List, Current);
    }
}


/*  노드 탐색 */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  노드 수 세기 */
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
