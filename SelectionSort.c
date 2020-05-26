// program to sort the values in ascending order using SELECTION SORT method
#define SIZE 50
#include <stdio.h>
void main()
{
	int x[SIZE], n;
	void accept_array(int a[], int n);
	void show_array(int a[], int n);
	void selection_sort(int a[], int n);
	
	printf("\n How many values do you want to have in the array : ");
	scanf("%d",&n);
	if (n>=1 && n<=SIZE)
	{	
		accept_array(x,n);
		printf("\n values before sorting ");
		show_array(x,n);
		selection_sort(x,n);
		printf("\n values after sorting ");
		show_array(x,n);
	}
	else
	{
		printf("Please input a value in the range of 1 to %d",SIZE);
	}
	printf("\n *** end of program ***");
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
		printf("\t %d",a[index]);
	}
}
void selection_sort(int a[], int n)
{
	int c,d,temp;
	for(c=0;c<n-1;c++)
	{
		for(d=c+1;d<n;d++)
		{
			if(a[c] > a[d])
			{
				temp = a[c];    // swapping 
				a[c] = a[d];
				a[d] = temp;
			}
		}
	}
}
