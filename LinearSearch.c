// linear search on an array

#define SIZE 50
#include <stdio.h>
void main()
{
	int x[SIZE], n, v, pos;
	int linear_search(int a[], int n, int key);		// this function returns index position of value
	void accept_array(int a[], int n);
	void show_array(int a[], int n);
	
	printf("\n how many values do you want to have in the array : ");
	scanf("%d",&n);
	if (n>=1 && n<=SIZE)
	{
		accept_array(x,n);
		show_array(x,n);
		printf("\n enter a value to search : ");
		scanf("%d",&v);
		pos=linear_search(x,n,v);
		if (pos==-1)
			printf("value %d is not found in the list",v);
		else
			printf("value %d is found at index %d",v,pos);
	}
	else
	{
		printf("Please input a value in the range of 1 to %d",SIZE);
	}	
	printf("\n *** end of program ***");
}
int linear_search(int a[], int n, int key)		// this function returns index position of value
{
	int index, res=-1;
	for (index=0;index<n;index++)
	{
		if (a[index]==key)
		{
			res=index;
			break;
		}
	}
	return res;
}
void accept_array(int a[], int n)
{
	int index;
	for (index=0;index<n;index++)
	{
		printf("enter value for x[%d] : ",index);
		scanf("%d",&a[index]);
	}
}
void show_array(int a[], int n)
{
	int index;
    printf("\n values in the array are : \n");
	for (index=0;index<n;index++)
	{
		printf("\t %d : ",a[index]);
	}
}

