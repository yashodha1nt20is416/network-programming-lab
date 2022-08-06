#include <stdio.h>

void bitStuffing(int N, int ar[])
{

    int result[30];//fot storing stuffed bits
    int one_count = 1;//count of 1's
    int i = 0, j = 0, k = 0;

    printf("stuffing 0 after 5 consiquitive 1 s ...\n");
    for(i=0;i<N;i++)
    {
       // one_count=1;
        
        if (ar[i] == 1) 
        {
            result[j] = ar[i];
            for (k = i + 1;ar[k] == 1&& k < N&& one_count < 5;k++) 
            {
                j++;
                result[j] = ar[k];
                one_count++;
                if (one_count == 5) 
                {
                    j++;
                    result[j] = 0;
                }
                i = k;
            }
        }
        else 
        {
            one_count=1;
            result[j] = ar[i];
        }
        j++;
    }

    printf("0 1 1 1 1 1 1 0 ");
    for (i = 0; i < j; i++)
    printf("%d ", result[i]);
    printf("0 1 1 1 1 1 1 0 ");
    printf("\n");
    
    int recv[50];
    int t=0;
    int count=0;
[3:32 pm, 05/08/2022] Asma Nmit: for(int i=0;i<j;i++)
    {
        if(result[i]==1)
        {
            count++;
            recv[t++]=1;
        }
        
        if(result[i]==0)
        {
            count=0;
            recv[t++]=0;
            
        }
        
        if(count==5&&result[i+1]==0)
        {
            i++;
            count=0;
        }
    }
    printf("\n received frame\n");
    for(int i=0;i<t;i++)
    printf("%d ", recv[i]);
}


int main()
{
    int ip[50],n;
    printf("enter the no of bits");
    scanf("%d", &n);

    printf("enter the bits");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ip[i]);
    }
    bitStuffing(n, ip);
    return 0;
}