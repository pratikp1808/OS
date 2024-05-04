#include<stdio.h>
int fs;
int j[5];
int m[5]; 
int count=0;
int job[5];

int main() 
{
   int mm,osm,um;
   int totalframes;
   
   
   printf("Enter the size Main memory:");
   scanf("%d",&mm);
   
   osm=mm*0.4;
   um=mm*0.6;
   
   printf("\nThe size allocated to the Operating System:%d",osm);
   printf("\nThe size remaining for User Process:%d",um);
   
   int i;
   
   for(i=0;i<5;i++)
   {
   	printf("\nEnter the Job name:");
   	scanf("%d",&j[i]);
   	printf("Enter memory required for job%d:",i+1);
   	scanf("%d",&m[i]);
   	}
   
   printf("\nJOb\t\tMemory\n");
    for(i=0;i<5;i++)
   {
   	printf("J%d\t\t%d\n",j[i],m[i]);
   }
   int k=0;
    do{
	
   	if(um>=m[k])
   	{
   		job[k]=j[k];
   		um-=m[k];
   		
   	k++;
   	}
	else 
	{
	break;
	}
   	
   	
   }while(k<5||um==0);
   
   printf("\nRemaining memory:%d",um);
   
    
    printf("\nProcesses Executed:");
    for(i=0;i<k;i++)
    {
  	 printf("|J%d|",job[i]);
    }
}
