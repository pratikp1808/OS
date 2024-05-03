#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;
int n = 5;
int q[5];
int startTime[5] = {0};
int v=0;
int pri[5];
int bt[5];
void enqueue(int c, int start,int bru,int pr) {
    int i, j;
    if (rear == n - 1) {
        printf("\nQUEUE IS FULL!");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = c;
        startTime[rear] = start;
        bt[rear]=bru;
        pri[rear]=pr;
    } else {
        rear++;
    
        for (i = rear - 1; i >= front; i--) {
            if (start<startTime[i] || pr<pri[i]) {
                q[i + 1] = q[i];
                startTime[i + 1] = startTime[i];
                bt[i+1]=bt[i];
                pri[i+1]=pri[i];
            } else {
                break;
            }
            
        }
        q[i + 1] = c;
        startTime[i + 1] = start;
        bt[i+1]=bru;
        pri[i+1]=pr;
    }
    
    v++;   
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else if (front == rear) {
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } else {
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
}



void dis() {
	int j;
    int wait;
    int sum;
    float avg;
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nprocess\tStart time\tBrust Time\tpriority\twait\n");
        for (j = front; j <= rear; j++) 
		{
			
			
            if (j == front) {
                wait = 0;
            } else {
                wait = startTime[j] + wait;
                sum+=wait;
            }
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", q[j], startTime[j],bt[j],pri[j] ,wait);
            
        }
        avg=sum/v;
        printf("\nAvg.wating time:%.2f",avg);
    }
}

int main(){
    int ch, c, start ,p,brust;
    while (ch!= 5) {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                printf("\nEnter the burst time:");
                scanf("%d",&brust);
                printf("\nEnter the priority of the process:");
                scanf("%d",&p);
                enqueue(c, start,brust,p);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                dis();
                break;
            case 4:
                exit(0);
                break;
            default:{
            	printf("INvalid");
				break;
			}
                
        }
    }
}

