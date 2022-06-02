#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define N strlen(g)
char t[20],cs[120],g[]="100000111";
int a,c,e;
void xor()
{
for(c=1; c<N; c++)
cs[c]=((cs[c] == g[c])?'0':'1');
}
void crc()
{
for(e=0; e<N; e++)
cs[e] = t[e];
do
{
if(cs[0] =='1') 
xor();
for(c=0; c<N-1; c++)
cs[c] = cs[c+1];
cs[c] = t[e++];
}
while(e<=a+N-1);
}
void main()
{
printf("Enetr the polynomial:\n");
scanf("%s",t);
printf("Generated polynomial is:%s\n",g);
a= strlen(t);
for(e=a; e<a+N-1; e++)
t[e]='0';
printf("Modified t[u] is %s\n",t);
crc();
printf("Checksum is:%s \n",cs);
for(e=a; e<a+N-1; e++)
t[e]=cs[e-a];
printf("Final codeword is:%s\n",t);
printf("Test error detection enter 0(yes) 1(no):");
scanf("%d",&e);
if(e==0)
{
do
{
printf("Enter the position where error has to be inserted:");
scanf("%d",&e);
}
while(e==0||e>a+N-1);
t[e-1]=(t[e-1]=='0')?'1':'0';
printf("Erroneous data:%s\n",t);
}
crc();
for(e=0; (e<N-1) && (cs[e]!='1');e++);
if(e<N-1)
printf("Error detected\n");
else
printf("Error not detected\n");
}
