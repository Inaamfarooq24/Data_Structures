#include <stdio.h>
int length(char str[])
{
int count = 0;
while(str[count] != '\0' && str[count] != '\n')
count++;
return count;
}
void copy(char str1[], char str2[])
{
int i = 0;
while(str1[i] != '\0' && str1[i] != '\n')
{
str2[i] = str1[i];
i++;
}
str2[i] = '\0';
}
void concatenate(char str1[], char str2[])
{
int i = 0, j = 0;
while(str1[i] != '\0' && str1[i] != '\n')
i++;
while(str2[j] != '\0' && str2[j] != '\n')
{
str1[i] = str2[j];
i++;
j++;
}
str1[i] = '\0';
}
int compare(char str1[], char str2[])
{
int i = 0;
while(str1[i] != '\0' && str1[i] != '\n' &&
str2[i] != '\0' && str2[i] != '\n')
{
if(str1[i] != str2[i])
return 0;
i++;
}
if((str1[i] == '\0' || str1[i] == '\n') &&
(str2[i] == '\0' || str2[i] == '\n'))
return 1;
return 0;
}
void reverse(char str[])
{
int i = 0, j = 0;
char temp;
while(str[j] != '\0' && str[j] != '\n')
j++;
j--;
while(i < j)
{
temp = str[i];
str[i] = str[j];
str[j] = temp;
i++;
j--;
}
}
int palindrome(char str[])
{
int i = 0, j = 0;
while(str[j] != '\0' && str[j] != '\n')
j++;
j--;
while(i < j)    {
if(str[i] != str[j])
return 0;
i++;
j--;
}
return 1;
}
int substring(char str[], char sub[])
{
int i, j;
for(i = 0; str[i] != '\0' && str[i] != '\n'; i++)
{
j = 0;
while(sub[j] != '\0' &&
sub[j] != '\n' &&
str[i + j] == sub[j])
{
j++;
}
if(sub[j] == '\0' || sub[j] == '\n')
return i;
}
return -1;
}
int main()
{
char str1[200], str2[100], str3[200], sub[100];
int choice, result;
printf("Enter first string: ");
fgets(str1, 200, stdin);
printf("Enter second string: ");
fgets(str2, 100, stdin);
printf("Enter substring: ");
fgets(sub, 100, stdin);
printf("\nLength = %d\n", length(str1));
copy(str1,str3);
printf("Copied string = %s", str3);
concatenate(str1, str2);
printf("\nConcatenated string = %s", str1);
if (compare(str3, str2))
printf("\nStrings are equal");
else
printf("\nStrings are not equal");
reverse(str3);
printf("\nReversed string = %s", str3);
if (palindrome(str3))
printf("\nPalindrome");
else
printf("\nNot palindrome");
result = substring(str1, sub);
if (result != -1){
printf("\nSubstring found at index %d", result);
}
else{
printf("\nSubstring not found");
}
return 0;
}    

    
