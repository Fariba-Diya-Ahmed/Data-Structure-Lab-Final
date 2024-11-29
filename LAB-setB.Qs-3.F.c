/*
Write a program in C to implement a queue using arrays.
The program should include the following operations:

a) Enqueue: Insert an element into the queue.

b) Dequeue: Remove an element from the queue.

c) Display: Display all elements on the queue
*/

#include<stdio.h>
#define N 100

int queue[N];
int front =-1,rear=-1;

void enqueue()
{
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d",&data);

    if(rear == N-1) printf("Queue overflow.\n");
    else if ( front == -1 && rear == -1)
    {
        front = rear=0 ;
        queue[rear]=data;
        printf("Enqueued: %d\n",queue[rear]);
    }
    else
    {
        rear++;
        queue[rear]=data;
        printf("Enqueued: %d\n",queue[rear]);
    }
}

void dequeue()
{
    int del;

    if(front == -1) printf("Queue underflow.\n");
    else if ( front == rear )
    {
        del = queue[front];
        front = rear= -1 ;
        printf("Dequeued: %d\n",del);
    }
    else
    {
        del = queue[front];
        front++ ;
        printf("Dequeued: %d\n",del);
    }
}

void display()
{
    if(front == -1) printf("Queue is empty.\n");
    else
    {
        printf("Queue: ");
        for(int i=front ; i<=rear; i++)  printf("%d  ",queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("Queue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program exited successfully !!!\n");
            return 0;

        default:
            printf("Invalid choice!! Try again.\n");
        }
        printf("------------------------------------\n");
    }
}
