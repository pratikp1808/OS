#include<stdio.h>
int fs;
int j[5];
int m[5]; 
int f[5];
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
   
   printf("\nEnter the fixed size of frame:");
   scanf("%d",&fs);
   
   totalframes=um/fs;
   printf("\nThe total number of frames available:%d",totalframes);
   
   int i;
   
   for(i=0;i<5;i++)
   {
   	printf("\nEnter the Job name:");
   	scanf("%d",&j[i]);
   	printf("Enter memory required for job%d:",i+1);
   	scanf("%d",&m[i]);
   	f[i]=m[i]/fs;
   	}
   
   printf("\nJOb\t\tMemory\t\tFrame Required\n");
    for(i=0;i<5;i++)
   {
   	printf("J%d\t\t%d\t\t%d\n",j[i],m[i],f[i]);
   }
   int k=0;
    do{
	
   	if(totalframes>=f[k])
   	{
   		job[k]=j[k];
   		totalframes-=f[k];
   		
   	k++;
   	}
	else 
	{
	break;
	}
   	
   	
   }while(k<5||totalframes==0);
   
    
    printf("\nProcesses Executed:");
    for(i=0;i<k;i++)
    {
  	 printf("|J%d|",job[i]);
    }
}
