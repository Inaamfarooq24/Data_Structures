//e)Implement Binary Search.
#include <stdio.h>
int binarySearch(int a[], int low, int high, int key)
{
if(low > high)
return -1;
int mid = (low + high) / 2;
if(a[mid] == key)
return mid;
if(key < a[mid])
return binarySearch(a, low, mid - 1, key);
return binarySearch(a, mid + 1, high, key);
}
int main()
{
int a[100], n, key, result;
printf("Enter size: ");
scanf("%d", &n);
printf("Enter sorted array:\n");
for(int i = 0; i < n; i++)
scanf("%d", &a[i]);
printf("Enter element to search: ");
scanf("%d", &key);
result = binarySearch(a, 0, n - 1, key);
if(result != -1){
printf("Element found at index %d\n", result);
}
else{
printf("Element not found\n");
}
return 0;
}