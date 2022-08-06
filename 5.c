#include<stdio.h>
#include<stdlib.h>
#define min(x,y) (x>y)?y:x
int main()
{
    //oprate=outputrate
    //cap=capacity of the bucket
    //i = 0 ; i keeps the input count 
    //nsec , to kepp count of n-seconds i,e inputcount-1
    
	int cap,oprate,ip[100],i,ch,nsec,drop=0,x,count=0;
	
	printf("\n enter bucket size : ");
	scanf("%d",&cap);
	
	printf("\n enter output rate :");
	scanf("%d",&oprate);
	
	do
	{
	printf("\n enter number of packets coming at second %d :",i+1);
	scanf("%d",&ip[i]);
	
	if(ip[i]>cap)
	{
		printf("Bucket overflow\n");		
		printf("Packet Discarded\n");
		exit(0);
	}
	
	i++;
	
	printf("\n enter 1 to contiue or 0 to quit to see the table..........");
	scanf("%d",&ch);
	
    }
    
    while(ch);
    
    // end of do-while loop here,if ch=1 then whilw is true and the do-while loop iterates ,if ch=0 then controls comes out of do-whilw loop
    //here the i value will be one-more then the input-second value
    
    nsec=i;
    printf("\n Second \t Recieved \t Sent \t Dropped \t Remained \n");//i,ip[i],logic,drop,count
    //sent means ,sent out of bucket
    
    for(i=0; count || i <nsec; i++) //i or count coz i stops at i<nsec but we need to empty the bucket so count also we use
    {
	    printf("  %d",i+1);
	    printf(" \t \t%d\t ",ip[i]);
	    printf(" \t%d\t ",min((ip[i]+count),oprate)); //logic for left out packets in bucks to be sent out 
	    if((x=ip[i]+count-oprate)>0) //x is the value of pckets after removing oprate pakets i,e remaining packets which should > 0
	                                 // inshort x=remaining packets=count
	   {
	    	if(x>cap)                 //is remaining packets > cap
		    {
			    count=cap;            //give remaining 
			    drop=x-cap;           //then drop the extra packets
		    }
		    else
		    {
		    	count=x;             //if remain < cap 
			    drop=0;
		    }
    	}
    	else
	    {
	    	drop=0;
	    	count=0;
    	}
	      printf(" \t %d\t %d \n",drop,count);
     }
     //count is for remaining packets 
     //count or remaing packets should always be <=cap
      
 return 0;
}