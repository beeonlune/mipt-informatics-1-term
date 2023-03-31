#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp -> value = data;
    tmp -> next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node* prev = NULL;
    int val;
    if (head == NULL)
    {
        return(-1);
    }
    prev = (*head);
    val = prev -> value;
    (*head) = (*head) -> next;
    free(prev);
    return val;
}

void buildList(Node **head, int size)
{
    Node *last_node = NULL;

    int i = size - 1;

    if (size == 0)
        return;
    for (i = size; i >= 1; i--)
    {
        push(head, i);
        if (last_node == NULL) last_node = (*head);
    }
    last_node -> next = (*head);
}

void printLinkedList(const Node *head, int size)
{
    Node *cur_node;
    cur_node = head;
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%d ", cur_node -> value);
        cur_node = cur_node -> next;
    }
    printf("\n");
}

Node* getNth(Node* head, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (head == NULL) break;
        head = head -> next;
    }
    return head;
}

int deleteNth(Node **head, int n, int quant)
{
    Node *prev, *curr;
    if (n == 0)
    {
        return pop(head);
    }
    else
    {
        if (n > 1)
            prev = getNth(*head, n - 1);
        else
            prev = getNth(*head, quant);
        curr = prev -> next;
        int val = curr -> value;

        prev -> next = curr -> next;
        *head = curr -> next;
        free(curr);
        return val;
    }
}

void deleteList(Node **head)
{
    while ((*head) -> next)
    {
        pop(head);
        *head = (*head) -> next;
    }
    free(*head);
}

int main()
{
    Node* Start_node = NULL;
    int VAL, M, N;
    printf("Enter the number of people (>1): ");
    scanf("%d", &N);
    printf("\nEnter the number of words (>0): ");
    scanf("%d", &M);
    printf("\n");
    if (N <= 1 || M < 1)
    {
        printf("Error!\n");
        return 0;
    }
    //создаём список из массива
    buildList(&Start_node, N);
    //printLinkedList(Start_node, N);
    //удаляем пятый элемент (индексация с нуля)
    while (N > 1)
    {
        VAL = deleteNth(&Start_node, M, N);
        N--;
        if (N < 4)
        {
            printf("Deleted: %d\n", VAL);
        }
    }
    printf("Left: ");
    printLinkedList(Start_node, N);
    printf("\n");
    ///считаю, что выбывшими считаются те, кто выбыл до того, как остался последний человек (он не считается выбывшим)
}
