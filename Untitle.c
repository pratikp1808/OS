#include <stdio.h>

struct process {
    int pid;
    int btime; // Burst time
    int wtime; // Waiting time
    int ttime; // Turnaround time
    int prtime; // Priority
};

int main() {
    int n, i, j, ttur = 0, twat = 0;
    float awat, atur;
    struct process p[10];

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nBurst time for process P%d (in ms): ", (i + 1));
        scanf("%d", &p[i].btime);
        printf("Enter priority: ");
        scanf("%d", &p[i].prtime);
        p[i].pid = i + 1;
    }

    // Sorting processes based on priority
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].prtime > p[j].prtime) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculating waiting time and turnaround time
    p[0].wtime = 0;
    for(i = 1; i < n; i++) {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
    }

    // Calculating average waiting time and turnaround time
    for(i = 0; i < n; i++) {
        ttur += p[i].ttime;
        twat += p[i].wtime;
    }
    awat = (float)twat / n;
    atur = (float)ttur / n;

    printf("\nPriority Scheduling Algorithm\n\n");
    printf("Process\tB-Time\tT-Time\tW-Time\tPriority\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].btime, p[i].ttime, p[i].wtime, p[i].prtime);
    }

    printf("\nAverage waiting time: %.2fms", awat);
    printf("\nAverage turn around time: %.2fms\n", atur);

    return 0;
}

