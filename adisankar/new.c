#include<stdio.h>
#include<stdlib.h>

#define MAX_TRACKS 200 

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void fcfs(int request[], int head, int n) {
    int i, total_movement = 0;

    printf("FCFS Disk Scheduling\n");
    printf("Sequence of tracks visited: ");
    for (i = 0; i < n; i++) {
        printf("%d ", request[i]);
        total_movement += abs(request[i] - head);
        head = request[i];
    }
    printf("\nTotal head movement: %d\n", total_movement);
}

void scan(int request[], int head, int n, int direction) {
    int i, total_movement = 0;
    int left[n], right[n];
    int left_count = 0, right_count = 0;

    printf("SCAN Disk Scheduling\n");
    printf("Sequence of tracks visited: ");
    
    for (i = 0; i < n; i++) {
        if (request[i] < head)
            left[left_count++] = request[i];
        else
            right[right_count++] = request[i];
    }

    if (direction == 0) {
        sort(left, left_count);
        sort(right, right_count);
    } else {
        sort(right, right_count);
        sort(left, left_count);
    }

    if (direction == 0) {
        for (i = left_count - 1; i >= 0; i--) {
            printf("%d ", left[i]);
            total_movement += abs(left[i] - head);
            head = left[i];
        }
        printf("0 ");
        total_movement += head;
        head = 0;
        for (i = 0; i < right_count; i++) {
            printf("%d ", right[i]);
            total_movement += abs(right[i] - head);
            head = right[i];
        }
    } else {
        for (i = 0; i < right_count; i++) {
            printf("%d ", right[i]);
            total_movement += abs(right[i] - head);
            head = right[i];
        }
        printf("%d ", MAX_TRACKS - 1);
        total_movement += (MAX_TRACKS - 1 - head);
        head = MAX_TRACKS - 1;
        for (i = left_count - 1; i >= 0; i--) {
            printf("%d ", left[i]);
            total_movement += abs(left[i] - head);
            head = left[i];
        }
    }
    printf("\nTotal head movement: %d\n", total_movement);
}

void cscan(int request[], int head, int n) {
    int i, total_movement = 0;
    int left[n], right[n];
    int left_count = 0, right_count = 0;

    printf("CSCAN Disk Scheduling\n");
    printf("Sequence of tracks visited: ");
    
    for (i = 0; i < n; i++) {
        if (request[i] < head)
            left[left_count++] = request[i];
        else
            right[right_count++] = request[i];
    }

    sort(left, left_count);
    sort(right, right_count);

    for (i = 0; i < right_count; i++) {
        printf("%d ", right[i]);
        total_movement += abs(right[i] - head);
        head = right[i];
    }
    printf("%d ", MAX_TRACKS - 1);
    total_movement += (MAX_TRACKS - 1 - head);
    head = MAX_TRACKS - 1;

    printf("0 ");
    total_movement += head;
    head = 0;
    for (i = 0; i < left_count; i++) {
        printf("%d ", left[i]);
        total_movement += abs(left[i] - head);
        head = left[i];
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, head, i, choice, direction;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int request[n];
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);
    printf("Enter the initial position of head: ");
    scanf("%d", &head);
    printf("Enter the direction of head movement (0 - left, 1 - right): ");
    scanf("%d", &direction);
    while(1){
        printf("Choose the disk scheduling algorithm:\n");
        printf("1. FCFS\n");
        printf("2. SCAN\n");
        printf("3. CSCAN\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fcfs(request, head, n);
                break;
            case 2:
                scan(request, head, n, direction);
                break;
            case 3:
                cscan(request, head, n);
                break;
            case 4 : exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
