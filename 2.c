#include<stdio.h>
int main()
{
    int i,j,k,l;
    //Get Frame 
    int fs;
    printf("\n Enter Frame size: ");
    scanf("%d",&fs);
    
    int f[20];
    printf("\n Enter Frame:");
    for(i=0;i<fs;i++)
    {
        scanf("%d",&f[i]);
    }
    
    //Get Generator
    int gs;
    printf("\n Enter Generator size: ");
    scanf("%d",&gs);
    
    int g[20];
    printf("\n Enter Generator:");
    for(i=0;i<gs;i++)
    {
        scanf("%d",&g[i]);
    }
    
    //sender side
    printf("\n Sender Side:");
    printf("\n Frame: ");
    for(i=0;i<fs;i++)
    {
        printf("%d",f[i]);
    }
    
    printf("\n Generator :");
    for(i=0;i<gs;i++)
    {
        printf("%d",g[i]);
    }
    
    //Append 0's
    int z=gs-1;//highest degree of generator polynomial 
    printf("\n Number of 0's to be appended: %d",z);
    
    for (i=fs;i<fs+z;i++)
    {
        f[i]=0;//appending 0's to sender polynomial 
    }
    
    int temp[20];//temp = msg with appended 0's
    for(i=0;i<fs+z;i++)
    {
        temp[i]=f[i];
    }
    
    printf("\n Message after appending 0's :");
    for(i=0; i<fs+z;i++)
    {
        printf("%d",temp[i]);
    }

    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
    
    //CRC
    int crc[15];
    for(i=0,j=fs;i<z;i++,j++)
    {
        crc[i]=temp[j];
    }
    
    printf("\n CRC bits: ");
    for(i=0;i<z;i++)
    {
        printf("%d",crc[i]);
    }
    
    
    
    //transmitted frane
    printf("\n Transmitted Frame: ");
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    
    for(i=fs,j=0;i<fs+z;i++,j++)
    {
        tf[i]=crc[j];
    }
    
    for(i=0;i<fs+z;i++)
    {
        printf("%d",tf[i]);
    }
    
    printf("\n Receiver side : ");
    printf("\n Received Frame: ");
    for(i=0;i<fs+z;i++)
    {
        printf("%d",tf[i]);
    }
    
    for(i=0;i<fs+z;i++)
    {
        temp[i]=tf[i];
    }
    
    //Division
    for(i=0;i<fs+z;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
    
    //Remainder
    printf("\n Reaminder: ");
    int rrem[15];
    for (i=fs,j=0;i<fs+z;i++,j++)
    {
        rrem[j]= temp[i];
    }
     
    for(i=0;i<z;i++)
    {
        printf("%d",rrem[i]);
    }
    
    int flag=0;
    for(i=0;i<z;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
    
    if(flag==0)
    {
        printf("\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct");
    }
    else
    {
        printf("\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error");
    }
}