#include<stdio.h>

int deadline[5]={-1}; 
int profit[5]={0};
int job[5]={0};
int max_deadline=0;
int totalprofit=0;
int arr[5]={0};

void sort(int c,int de,int jo) 
{
    int i;
    if (deadline[0]==-1) 
	{
        profit[0]=c;
        deadline[0]=de;
        job[0]=jo;
    } 
	else 
	{
        for (i=4;i>=0;i--) 
		{
            if (c>profit[i]) 
			{
                if (i<4) 
				{ 
                    profit[i+1]=profit[i];
                    deadline[i+1]=deadline[i];
                    job[i+1]=job[i];
                }
            }
			else
			{
                break;
            }
        }
        profit[i+1]=c; 
        deadline[i+1]=de;
        job[i+1]=jo;
    }
}

int main() 
{
    int i,j=1,k=0,n=1;
    int pro[5],del[5];
    int d;
    
    printf("Enter the maximum deline is: ",i+1);
    scanf("%d",&max_deadline);
    

    for(i=0;i<5;i++) 
	{
        printf("\nEnter the profit of %d Job: ",i+1);
        scanf("%d",&pro[i]);
        printf("Enter the deline of %d Job: ",i+1);
        scanf("%d",&del[i]);
        sort(pro[i],del[i],j);
        j++;
    }
    printf("\nJob\t\tProfit\t\tDeadline\n");
	for(i=0;i<5;i++) 
	{
        printf("\nJ%d\t\t%d\t\t%d",job[i],profit[i],deadline[i]);
    }
    
    do
    {
    	if(max_deadline>=deline[k])
    	{
    		totalprofit+=profit[k];
    		max_deadline-=deadline[k];
    		arr[n]=job[k];
    		n++;
    		k++;
		}
		else
		{
			k++;
		}
	}while(max_deadline!=0||k==5);
    

    printf("\n\nTotal profit is:%d",totalprofit);
    
    printf("\nThe Jobs excuted are: ");
    for(d=1;d<n;d++)
    {
    	printf("|J%d|",arr[d]);
	}
    return 0;
}
