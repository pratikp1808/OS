#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1;
int n = 5;
int q[5];
int st[5] = {0};
int et[5]={0};
int v=0;
void dis();

void enqueue(int c, int start,int execution) {
    int i, j;
    if (rear == n - 1) {
        printf("\nQUEUE IS FULL!");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        q[rear] = c;
        st[rear] = start;
        et[rear]=execution;
    } else {
        rear++;
        q[rear] = c;
        st[rear] = start;
        et[rear]=execution;
    
       
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
    dis();
}

void view() {
    if (front == -1 && rear == -1) {
        printf("\nQUEUE IS EMPTY!");
    } else {
        printf("\nPeek element is: %d", q[front]);
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
        printf("\nprocess\t\tstart time\texecution time\twait\n");
        for (j = front; j <= rear; j++) 
		{
			
			
            if (j == front) {
                wait = 0;
            } else {
                wait = st[j] + et[j-1]+wait;
                sum+=wait;
            }
            printf("%d\t\t%d\t\t%d\t\t%d\n", q[j], st[j], et[j],wait);
            
        }
        avg=sum/v;
        printf("\nAvg.wating time:%.2f",avg);
    }
}

int main()
 {
    int y, c, start = 0,exe=0;
     do{
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) {
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                 printf("\nEnter the execution time: ");
                scanf("%d", &exe);
                enqueue(c, start,exe);
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
               
            
                
        }
    }while (y != 4);
    return 0;
}


