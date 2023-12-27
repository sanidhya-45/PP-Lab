// Write a program to sort an array of n elements using both sequential and parallel merge
// sort(using Section). Record the difference in execution time
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
// Simple Merge Function to join the two sorted parts
// We don't need to include pragma clauses here
void merge(int a[],int low, int mid, int high){
int n1 = mid-low+1, n2 = high-mid;
int L[n1], R[n2];
for(int i=0;i<n1;i++)
L[i] = a[low+i];
for(int i=0;i<n2;i++)
R[i] = a[mid+1+i];
int i=0,j=0,k=low;
while(i<n1 && j<n2){
if(L[i]<=R[j]){
a[k] = L[i];
i++;
k++;
}
else{
a[k] = R[j];
k++;
j++;
}
}
while(i<n1){
a[k] = L[i];
i++;
k++;
}
while(j<n2){
a[k] = R[j];
j++;
k++;
}
}
// This is the merge sort function for sequential execution
// Here we are not providing any parallel programming clause
void mergeSortSequential(int a[], int low, int high){
if(low<high){
int mid = (low+high)/2;
mergeSortSequential(a,low,mid);
mergeSortSequential(a,mid+1,high);
merge(a,low,mid,high);
}
}
// This is the merge sort function for parallel execution
// We are using sections clause from openmp library which divides the work
// into seperate non-iterative contructs and process them parallelly
// Note that we are using section clause only for division purpose not for
// the merging purpose
void mergeSortParallel(int a[], int low, int high){
if(low<high){
int mid = (low+high)/2;
#pragma omp parallel sections
{
#pragma omp section
mergeSortParallel(a,low,mid);
#pragma omp section
mergeSortParallel(a,mid+1,high);
}
merge(a,low,mid,high);
}
}
int main(){
int n;
scanf("%d",&n);
int a[n],a_copy[n];
for(int i=0;i<n;i++){
a[i] = rand()%1000;
a_copy[i] = a[i];
}
printf("Original Array\n");
for(int i=0;i<n;i++)
printf("%d ",a[i]);
double start,end;
// for calculating time for sequential execution
start = omp_get_wtime();
mergeSortSequential(a,0,n-1);
end = omp_get_wtime();
printf("\nSorted Array:-\n");
for(int i=0;i<n;i++)
printf("%d ",a[i]);
printf("\nTime taken Sequential = %f\n",end-start);
for(int i=0;i<n;i++)
a[i] = a_copy[i];
// for calculating time for parallel execution
start = omp_get_wtime();
mergeSortParallel(a,0,n-1);
end = omp_get_wtime();
printf("Sorted Array:-\n");
for(int i=0;i<n;i++)
printf("%d ",a[i]);
printf("\nTime taken Parallel = %f\n",end-start);
return 0;
}
// Output:-
// 10
// Original Array
// 383 886 777 915 793 335 386 492 649 421
// Sorted Array:-
// 335 383 386 421 492 649 777 793 886 915
// Time taken Sequential = 0.000010
// Sorted Array:-
// 335 383 386 421 492 649 777 793 886 915
// Time taken Parallel = 0.001229