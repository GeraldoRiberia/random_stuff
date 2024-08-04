#include <stdio.h>

struct Process {
    int id, Bt, Pr, Wt, TAt;
} P[20], temp;

int main() {
    int i, j, n, total_wt = 0, total_tat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter process id, burst time and priority of P-%d: ", i + 1);
        scanf("%d%d%d", &P[i].id, &P[i].Bt, &P[i].Pr);
    }

    // Sort processes based on priority
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (P[j].Pr > P[j + 1].Pr) {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turn-around time
    P[0].Wt = 0;
    P[0].TAt = P[0].Bt;

    for (i = 1; i < n; i++) {
        P[i].Wt = P[i - 1].TAt;
        P[i].TAt = P[i].Bt + P[i].Wt;
    }

    // Print process details
    printf("PROCESS ID\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].id, P[i].Bt, P[i].Pr, P[i].Wt, P[i].TAt);
    }

    // Calculate total waiting time and turn-around time
    for (i = 0; i < n; i++) {
        total_wt += P[i].Wt;
        total_tat += P[i].TAt;
    }

    // Print average waiting time and turn-around time
    printf("Average waiting time = %f\n", (float)total_wt / n);
    printf("Average turn-around time = %f\n", (float)total_tat / n);

    return 0;
}