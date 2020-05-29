// Insertion sort : 

#include <stdio.h>
void insertion_sort(int arr[], int n);
void printArray(int A[], int size);

void main() 
{ 
    int arr[] = {78, 34, 62, 93, 27}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    insertion_sort(arr, arr_size); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
} 

/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* insertion sort function */			
void insertion_sort(int arr[], int n) 			
{ 										
	int i, j, temp;					
	for (i=1 ; i<n ; i++)				
	{									
    	temp = arr[i];     			
    	j = i - 1;
    	while (j>=0 && temp<arr[j])
	    {
    	    arr[j+1] = arr[j];
        	j--;
    	}
    	arr[j+1] = temp;
	}
} 

