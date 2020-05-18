/* program to perform queue operations */

#include <stdio.h>
#define SIZE 10
int queue[SIZE], front=-1, rear=-1, limit=SIZE-1;
void enqueue();
void dequeue();
void display();
void swap();
void main()
{
	// the main driver program
	int ch;
	do
	{
		printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. swap \n 5. Exit");
		printf("\n Enter your choice (1-4) : ");
		scanf("%d",&ch);
		if (ch==1)
			enqueue();
		else if (ch==2)
			dequeue();
		else if (ch==3)
			display();
		else if (ch==4)
			swap();
		else if (ch==5)
			printf("    end of program    ");
		else
			printf("\n Invalid choice...Retry");
	}while(ch!=5);
}
void enqueue()
{
	rear++;
	if(rear>limit)   // checking for overflow
	{
		printf("Queue Overflow...no space new elements");
		rear--;
	}
	else
	{
		printf("enter a value to the Queue ");
		scanf("%d",&queue[rear]);
	    printf("element added");
	    if (rear==0)
	    	front=0;
	}
}
void dequeue()
{
	if(rear==-1)   // checking for underflow	
	{
		printf("Queue underflow...no elements to remove");
	}
	else
	{
		printf("%d will be deleted ", queue[front]);
		front++;
		printf("...element deleted");
		if (front>rear)		// to check if all elements are deleted
		{
			front = rear = -1;
			printf("\n Queue is now empty");
		}
    } 
}
void display()
{
	int c;
	if( rear==-1)
		printf("Queue underflow...no elements to display");	
	else
	{	printf("\n Queue elements are");
		for (c=front;c<=rear;c++)
		{
			printf("\n queue[%d] value is %d", c, queue[c]);
		}
	}
}
void swap()
{
	// swapping the first and last value 
	int temp;
	if (front==-1)
	printf("queue underflow");
	
	else if(front==rear)
		printf("Only one element exists in the queue..no swapping needed");
		
	else
	{
		temp= queue[front];
		queue[front]= queue[rear];
		queue[rear]= temp;
	    printf("swapping done");
	
	}

}

void swap()
{
	// swapping the first and last value 
	int temp;
	if (front==-1)
	printf("queue underflow");
	
	else if(front==rear)
		printf("Only one element exists in the queue..no swapping needed");
		
	else
	{
		for (c=front;c<=rear;c++)
		temp= queue[front];
		queue[front]= queue[rear];
		queue[rear]= temp;
	    printf("swapping done");
	
	}

}




