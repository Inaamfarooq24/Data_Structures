#include <stdio.h>
int length(char *s)
{
int count = 0;
while (*s != '\0' && *s != '\n')
{
count++;
s++;
}
return count;
}
void copy(char *s1, char *s2)
{
while (*s1 != '\0' && *s1 != '\n'){
*s2 = *s1;
s1++;
s2++;
}
*s2 = '\0';
}
void concatenate(char *s1, char *s2)
{
while (*s1 != '\0' && *s1 != '\n')
s1++;
while (*s2 != '\0' && *s2 != '\n')
{
*s1 = *s2;
s1++;
s2++;
}
*s1 = '\0';
}
int compare(char *s1, char *s2)
{
while (*s1 != '\0' && *s1 != '\n' && *s2 != '\0' && *s2 != '\n'){
if (*s1 != *s2)
return 0;
s1++;
s2++;
}
if ((*s1 == '\0' || *s1 == '\n') &&
(*s2 == '\0' || *s2 == '\n'))
return 1;
return 0;
}
void reverse(char *s)
{
char *start = s;
char *end = s;
char temp;
while (*end != '\0' && *end != '\n')
end++;
if (end == start)
return;
end--;
while (start < end)
{
temp = *start;
*start = *end;
*end = temp;
start++;
end--;
}
}
int palindrome(char *s)
{
char *start = s;
char *end = s;
while (*end != '\0' && *end != '\n')
end++;
if (end == start)
return 1;
end--;
while (start < end)
{
if (*start != *end)
return 0;
start++;
end--;
}
return 1;
}
int substring(char *s, char *sub)
{
char *start, *p, *q;
if (*sub == '\n' || *sub == '\0')
return 0;
for (start = s; *start != '\0' && *start != '\n'; start++)
{
p = start;
q = sub;
while (*p == *q && *q != '\0' && *q != '\n')
{
p++;
q++;
}
if (*q == '\0' || *q == '\n')
return start - s;
}
return -1;
}
int main()
{
char s1[200], s2[100], s3[200], sub[100];
int result;
printf("Enter first string: ");
fgets(s1, sizeof(s1), stdin);
printf("Enter second string: ");
fgets(s2, sizeof(s2), stdin);
printf("Enter substring to search: ");
fgets(sub, sizeof(sub), stdin);
printf("\n1. Length = %d\n", length(s1));
copy(s1, s3);
printf("2. Copied string = %s\n", s3);
concatenate(s1, s2);
printf("3. Concatenated string = %s\n", s1);
result = compare(s3, s2);
if (result == 1)
printf("4. Strings are equal\n");
else
printf("4. Strings are not equal\n");
reverse(s3);
printf("5. Reversed string = %s\n", s3);
if (palindrome(s3))
printf("6. Palindrome\n");
else
printf("6. Not palindrome\n");
result = substring(s1, sub);
if (result != -1)
printf("7. Substring found at index %d\n", result);
else
printf("7. Substring not found\n");
return 0;
}