// program to implement circular single linked list

#include <stdio.h>
#include <stdlib.h>
void create_node();
void display();
void insertAtBegin();
void insertAtMiddle();
void insertAtEnd();
void deleteFirst();
void deleteLast();
void deleteFromMiddle();

struct node
{
	int data;
	struct node *link;
};
struct node *first, *neu, *temp, *last;
void main()
{
	first=temp=neu=last=NULL;
	char ans;
	int ch;
	do
	{
		create_node();
		if (first==NULL)
		{
			first=last=neu;
			last->link=first;	// circular linking
		}
		else
		{
			neu->link=last->link;  	// linking the nodes
			last->link=neu;
			last=neu;       // to move last to neu
		}
		printf("\n repeat y/n ");
		fflush(stdin);  // to clear the standard input buffer
		scanf("%c",&ans);
	}while(ans=='y' || ans=='Y');
	do {
		printf("\n 1 Display ");
		printf("\n 2 insert element at the begining ");
		printf("\n 3 Insert element in the middle");
		printf("\n 4 Insert element in the end");
		printf("\n 5 Delete first element");
		printf("\n 6 Delete last element");
		printf("\n 7 Delete middle element");
		printf("\n 8 Exit");
		printf("\n Enter your choice (1-8): ");
		scanf("%d", &ch);
		if(ch == 1)
			display();
		else if (ch==2)
			insertAtBegin();
		else if (ch==3)
			 insertAtMiddle();
		else if (ch==4)
			insertAtEnd();
		else if (ch==5)
			deleteFirst();
		else if (ch==6)
			deleteLast();
		else if (ch==7)
			deleteFromMiddle();
		else if (ch==8)
			printf("** end of program ** ");
		else 
			printf("\n invalid choice ");
	}while (ch!=8);	
}
void create_node()
{
	neu = (struct node*) malloc(sizeof(struct node));
	printf("enter value for data portion ");
	scanf("%d",&neu->data);
	neu->link=NULL;
}
void display()
{
	if (first==NULL)
		printf("list underflow...no elements to display");
	else
	{
		temp=first;	//  position temp to initial node
		do
		{
			printf("\n %u\t%d",temp,temp->data);
			temp=temp->link;	// temp moves to next node
		}while (temp != last->link);
	}
}
void insertAtBegin()
{
	create_node();
	if (first==NULL)
		first=last=neu; 
	else
	{
		neu->link=first;
		first=neu; 
		last->link=first;	// circular linking
    } 
}
void insertAtMiddle()
{
	int n, c;
	create_node();
	if (first==NULL)
		first=last=neu;
 	else
		printf("Insert node after which poisition :");
		scanf("%d",&n);   // suppose input is 4
		temp=first;  // c=1 , we still have to move n-1 times 
		for(c=1;c<n;c++)
		{
			temp=temp->link;  // temp move one step forward
		}
		neu->link=temp->link;
		temp->link=neu;
}

void insertAtEnd()
{
	create_node();
	if (first==NULL)
		first=last=neu;
	else
	{
		neu->link=first;	
		last->link=neu;
		last=neu;
	}	
}
void deleteFirst()
{
	if (first==NULL)
		printf("underflow...no elements in the list to delete");
	else
	{
		neu=first;
		first=first->link;
		neu->link=NULL;
		last->link=first;
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
		temp=first;
		while(temp->link->link!=first)	// to reach the last but one node
		{
			temp=temp->link;
		}
		neu=temp->link;
		temp->link=first;
		neu->link=NULL;
		last=temp;
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
			temp=temp->link;  // temp move one step forward
		}
		neu=temp->link;
		temp->link=neu->link;
		neu->link=NULL;
		printf("deleted element is..%d",neu->data);
		free(neu);
		neu=NULL;
	}
}
