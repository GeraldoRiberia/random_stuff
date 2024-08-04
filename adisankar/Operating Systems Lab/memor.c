#include<stdio.h>

void firstfit(int p_array[], int n, int m_blocks[], int m) {
    printf("First Fit\n");
    int i, j, flag, parray[100], marray[100];
    for(i = 0; i < n; i++) {
        parray[i] = p_array[i];
    }
    for(i = 0; i < m; i++) {
        marray[i] = m_blocks[i];
    }
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < m; j++) {
            if(marray[j] >= parray[i]) {
                printf("%d allocated in %d memory block", parray[i], marray[j]);
                marray[j] = marray[j] - parray[i];
                printf(" => %d space remaining \n", marray[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("%d cannot be allocated \n", parray[i]);
        }
    }
}

void worstfit(int p_array[], int n, int m_blocks[], int m) {
    printf("\t\tWorst Fit \n");
    int i, j, max, loc, parray[100], marray[100];
    for(i = 0; i < n; i++) {
        parray[i] = p_array[i];
    }
    for(i = 0; i < m; i++) {
        marray[i] = m_blocks[i];
    }
    for(i = 0; i < n; i++) {
        max = marray[0];
        loc = 0;
        for(j = 0; j < m; j++) {
            if(marray[j] > max) {
                max = marray[j];
                loc = j;
            }
        }
        if(max >= parray[i]) {
            printf("%d allocated in %d memory block", parray[i], marray[loc]);
            marray[loc] = marray[loc] - parray[i];
            printf(" => %d space remaining \n", marray[loc]);
        } else {
            printf("%d cannot be allocated \n", parray[i]);
        }
    }
}

void bestfit(int p_array[], int n, int m_blocks[], int m) {
    printf("\t\tBest Fit \n");
    int i, j, max, loc, parray[100], marray[100];
    for(i = 0; i < n; i++) {
        parray[i] = p_array[i];
    }
    for(i = 0; i < m; i++) {
        marray[i] = m_blocks[i];
    }
    for(i = 0; i < n; i++) {
        loc = -1;
        for(j = 0; j < m; j++) {
            if(marray[j] >= parray[i]) {
                if(loc == -1) {
                    loc = j;
                } else if(marray[loc] > marray[j]) {
                    loc = j;
                }
            }
        }
        if(loc != -1) {
            printf("%d allocated in %d memory block", parray[i], marray[loc]);
            marray[loc] = marray[loc] - parray[i];
            printf(" => %d space remaining \n", marray[loc]);
        } else {
            printf("%d cannot be allocated \n", parray[i]);
        }
    }
}

void main() {
    int i, p_array[100], m_blocks[100], n, m;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the array of processes : ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p_array[i]);
    }
    printf("Enter the number of memory blocks : ");
    scanf("%d", &m);
    printf("Enter the array of memory blocks : ");
    for(i = 0; i < m; i++) {
        scanf("%d", &m_blocks[i]);
    }
    firstfit(p_array, n, m_blocks, m);
    bestfit(p_array, n, m_blocks, m);
    worstfit(p_array, n, m_blocks, m);
}
