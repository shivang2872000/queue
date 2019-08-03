#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Queue
{
    struct Node *start, *end;
};
int dequeue(struct Queue *q)
{
    if (q->start == NULL)
    {
        printf ("Queue is empty");
        return -1;
    }
    int value;
    if (q->start == q->end)
    {
        value = q->start->data;
        free(q->start);
        q->start = NULL;
        q->end = NULL;
    }
    else
    {
        struct Node *temp = q->start;
        value = temp->data;
        q->start = q->start->next;
        q->end->next= q->start;
        free(temp);
    }
    return value ;
}
void enqueue( struct Queue *q, int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if (q->start == NULL)
        q->start = temp;
    else
        q->end->next = temp;

    q->end = temp;
    q->end->next = q->start;
}
void displayQueue(struct Queue *q)
{
    struct Node *temp = q->start;
    while (temp->next != q->start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
     }
    printf("%d", temp->data);
}

int main()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->start = q->end = NULL;
    enqueue(q, 50);
    enqueue(q, 72);
    enqueue(q, 83);
    displayQueue(q);
    printf(  "value deleted is %d", dequeue(q));
    printf("value deleted is %d\n", dequeue(q));
    displayQueue(q);
    enqueue(q, 96);
    enqueue(q, 105);
    displayQueue(q);
    return 0;
}
