#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char res[100];

void sender()
{
    int n,i,len;
    char frm[100],l[100];
    
    printf("Enter the number of frames\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the frame %d\n",i+1);
        scanf("%s",&frm);
        
        len=strlen(frm);
        //printf("%d\n",len);
       
        sprintf(l,"%d",len);//here l is a buffer used,where the string(len integer value) is stored. It is the buffer to put the data in.
        //here to convert integer len value into string type,sprintf is used 
        
        strcat(l,frm);//here frm is appended to l,and it returns l(dest)
        //printf("%s/n",l);
        
        strcat(res,l);
    }
    printf("The final message is %s\n",res);
}

void receiver()
{
    int len,i,j;
    printf("Received frame \n");
    
    //printf("%d",strlen(res));
    
    for(i=0;i<strlen(res);i++)
    {
        len=res[i]-'0';//converts the character at position i to a numeric digit.
                        
       // printf("%d",'0');//'0' ascii value is 48
       
        for(j=i+1;j<=(i+len);j++)
        printf("%c",res[j]);
        
        i=i+len;
        
        printf("\n");
    }
    
    
}

void main()
{
    sender();
    receiver();

}