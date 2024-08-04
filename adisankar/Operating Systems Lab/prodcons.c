#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 4, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int n;
    printf("\nProducer Consumer Problem\n");
    printf("\n1. To produce the item\n2. To consume the item\n3. To end the program\n");

    while(1) {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch(n) {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full");
                break;
            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produced item %d", x);
    printf("\nThe number of available items in buffer is: %d", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumed item %d", x);
    x--;
    printf("\nThe number of available items in buffer is: %d", x);
    mutex = signal(mutex);
}
