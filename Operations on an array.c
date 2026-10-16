#include <stdio.h>
void traversal(int a[], int n)
{
for(int i = 0; i < n; i++){
printf("%d ", a[i]);
printf("\n");
}
}
int linearSearch(int a[], int n, int key)
{
for(int i = 0; i < n; i++){
if(a[i] == key)
return i;
}
return -1;
}
int binarySearch(int a[], int n, int key){
int low = 0, high = n - 1;
while(low <= high){
int mid = (low + high) / 2;
if(a[mid] == key)
return mid;
else if(key < a[mid]){
high = mid - 1;
}
else{
low = mid + 1;
}
}
return -1;
}
void insertion(int a[], int *n, int pos, int value){
for(int i = *n; i > pos; i--){
a[i] = a[i - 1];
a[pos] = value;
(*n)++;
}
}
void deletion(int a[], int *n, int pos)
{
for(int i = pos; i < *n - 1; i++)
a[i] = a[i + 1];
(*n)--;
}
void merging(int a[], int n1, int b[], int n2, int c[])
{
int k = 0;
for(int i = 0; i < n1; i++)
c[k++] = a[i];
for(int i = 0; i < n2; i++)
c[k++] = b[i];
printf("Merged array: ");
traversal(c, n1 + n2);
}
void splitting(int a[], int n)
{
int mid = n / 2;
printf("First part: ");
for(int i = 0; i < mid; i++)
printf("%d ", a[i]);
printf("\nSecond part: ");
for(int i = mid; i < n; i++)
printf("%d ", a[i]);
printf("\n");
}
void bubbleSort(int a[], int n)
{
for(int i = 0; i < n - 1; i++)
{
for(int j = 0; j < n - i - 1; j++)
{
if(a[j] > a[j + 1]){
int temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
}
int main()
{
int a[100], b[100], c[200];
int n, n2, key, pos, value;
printf("Enter size of array: ");
scanf("%d", &n);
printf("Enter elements:\n");
for(int i = 0; i < n; i++)
scanf("%d", &a[i]);
printf("\nTraversal: ");
traversal(a, n);
printf("\nEnter element for linear search: ");
scanf("%d", &key);
pos = linearSearch(a, n, key);
if(pos != -1)
printf("Element found at index %d\n", pos);
else
printf("Element not found\n");
bubbleSort(a, n);
printf("\nSorted array: ");
traversal(a, n);
printf("Enter element for binary search: ");
scanf("%d", &key);
pos = binarySearch(a, n, key);
if(pos != -1)
printf("Element found at index %d\n", pos);
else
printf("Element not found\n");
printf("\nEnter position for insertion (0 to %d): ", n);
scanf("%d", &pos);
printf("Enter value: ");
scanf("%d", &value);
insertion(a, &n, pos, value);
printf("After insertion: ");
traversal(a, n);
printf("\nEnter position for deletion: ");
scanf("%d", &pos);
deletion(a, &n, pos);
printf("After deletion: ");
traversal(a, n);
printf("\nEnter size of second array: ");
scanf("%d", &n2);
printf("Enter elements:\n");
for(int i = 0; i < n2; i++)
scanf("%d", &b[i]);
merging(a, n, b, n2, c);
printf("\nSplitting first array:\n");
splitting(a, n);
return 0;
}