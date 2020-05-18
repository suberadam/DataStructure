// program to implement Double linked list

#include <stdio.h>
#include <stdlib.h>
void create_node();
void displayFirstToLast();
void displayLastToFirst();
void insertAtBegin();
void insertAtMiddle();
void insertAtEnd();
void deleteFirst();
void deleteLast();
void deleteFromMiddle();

struct node
{
	struct node *llink;
	int data;
	struct node *rlink;
};
struct node *first, *last, *neu, *temp;
void main()
{
	first=last=temp=neu=NULL;
	char ans;
	int ch;
	do
	{
		create_node();
		if (first==NULL)	// to verify if 'neu' is the initial node
		{
			first=last=neu;
			first->llink=last;
			last->rlink=first;
		}
		else
		{
			last->rlink=neu;	// linking temp to the node forward
			neu->llink=last;	// linking neu to the node backward
			last=neu;       // to move temp and last to neu
			first->llink=last;
			last->rlink=first;
		}
		printf("\n repeat y/n ");
		fflush(stdin);  // to clear the standard input buffer
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
	do
	{
		printf("\n 1 Display first to last node ");
		printf("\n 2 Display last to first node ");
		printf("\n 3 Insert element at the begining ");
		printf("\n 4 Insert element in the middle");
		printf("\n 5 Insert element in the end");
		printf("\n 6 Delete first element");
		printf("\n 7 Delete last element");
		printf("\n 8 Delete middle element");
		printf("\n 9 Exit");
		printf("\n Enter your choice (1-9): ");
		scanf("%d", &ch);
		if(ch == 1)
			displayFirstToLast();
		else if(ch == 2)
			displayLastToFirst();
		else if (ch==3)
			insertAtBegin();
		else if (ch==4)
			 insertAtMiddle();
		else if (ch==5)
			insertAtEnd();
		else if (ch==6)
			deleteFirst();
		else if (ch==7)
			deleteLast();
		else if (ch==8)
			deleteFromMiddle();
		else if (ch==9)
			printf("** end of program ** ");
		else 
			printf("\n invalid choice ");
	}while (ch!=9);	
}
void create_node()
{
	neu = (struct node*) malloc(sizeof(struct node));
	printf("enter value for data portion : ");
	scanf("%d",&neu->data);
	neu->llink = neu->rlink = NULL;
}
void displayFirstToLast()
{
	if (first==NULL)
		printf("list underflow...no elements to display");
	else
	{
		printf("\nlist of value from first to last");
		temp=first;	//  position temp to initial node
		do 
		{
			printf("\n %u\t%d",temp,temp->data);
			temp=temp->rlink;	// temp moves to next node
		}while (temp!=last->rlink);
	}
}
void displayLastToFirst()
{
	if (first==NULL)
		printf("list underflow...no elements to display");
	else
	{
		printf("\nlist of value from last to first");
		temp=last;	//  position temp to last node
		do 
		{
			printf("\n %u\t%d",temp,temp->data);
			temp=temp->llink;	// temp moves to previous node
		}while (temp!=first->llink);
	}
}
void insertAtBegin()
{
	create_node();
	if (first==NULL)
		first=last=neu; 
	else
	{
		neu->rlink=first;
		first->llink=neu;
		first=neu; 
		first->llink=last;
		last->rlink=first;
    } 
}
void insertAtMiddle()
{
	int n, c;
	create_node();
	if (first==NULL)
		first=last=neu;
 	else
	{
		printf("Insert node after which poisition : ");
		scanf("%d",&n);   // suppose input is 4
		temp=first;  // c=1 , we still have to move n-1 times 
		for(c=1;c<=n-1;c++)		// to reach the given node position
		{
			temp=temp->rlink;  // temp moves one step forward
		}
		neu->rlink=temp->rlink;
		temp->rlink->llink=neu;
		temp->rlink=neu;
		neu->llink=temp;
	}
}
void insertAtEnd()
{
	create_node();
	if (first==NULL)
		first=last=neu; 
	else
	{
		last->rlink=neu;
		neu->llink=last;
		last=neu; 
		last->rlink=first;
		first->llink=last;
    }
}
void deleteFirst()
{
	if (first==NULL)
		printf("underflow...no elements in the list to delete");
	else
	{
		neu=first;
		first=first->rlink;
		neu->rlink = first->llink = last->rlink= NULL;
		last->rlink=first;		
		printf("deleted element is..%d",neu->data);
		free(neu);
		neu=NULL;
	}		
}
void deleteLast()
{	
	if (first==NULL)
		printf("underflow...no elements in the list to delete");
	else
	{
		neu=last;
		last=last->llink;
		last->rlink = neu->llink = first->llink = NULL;	
		last->rlink=first;
		first->llink=last;	
		printf("deleted element is..%d",neu->data);
		free(neu);
		neu=NULL;
	}
}
void deleteFromMiddle()
{
	int c,n;
	if (first==NULL)
		printf("underflow...no elements in the list to delete");
	else
	{
		printf("Delete node at which poisition : ");
		scanf("%d",&n);   // suppose input is 3
		temp=first;  // c=1 , we still have to move n-1 times 
		for(c=1;c<n-1;c++)
		{
			temp=temp->rlink;  // temp move one step forward
		}
		neu=temp->rlink;
		temp->rlink = neu->rlink;
		neu->rlink->llink = temp;
		neu->llink = neu->rlink = NULL;
		printf("deleted element is..%d",neu->data);
		free(neu);
		neu=NULL;
	}
}
