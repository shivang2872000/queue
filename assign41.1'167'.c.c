#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear =-1;
void insert(int element)
{
    if(full())
    printf("\n Queue is full!! \n");
    else
    {
        if(front == -1)
        front=0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}
int full()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1))
    return 1;
    else
    return 0;
}
int empty()
{
    if(front == -1)
    return 1;
    else
    return 0;
}
int rmv()
{
    int element;
    if(empty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;

        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}
void display()
{
    int i;
    if(empty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}

int main()
{
    rmv();

    insert(10);
    insert(20);
    insert(37);
    insert(49);
    insert(50);
    insert(61);
    display();
    rmv();
    display();
    insert(71);
    display();
    insert(84);
    return 0;
}
