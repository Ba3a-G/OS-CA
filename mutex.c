#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 5;

pthread_mutex_t mutex; // mutex variable

void *increment() {
    pthread_mutex_lock(&mutex); // locking the mutex
    int local = shared;
    local++;
    sleep(1); // ctx switch
    shared = local;
    pthread_mutex_unlock(&mutex);
}

void *decrement() {
    pthread_mutex_lock(&mutex);
    int local = shared;
    local--;
    sleep(1);
    shared = local;
    pthread_mutex_unlock(&mutex);
}

int main() {
    int times = 10;
    int count = times;
    int race = 0;
    while(count--) {
        pthread_t thread1, thread2;
        shared = 5;
        pthread_create(&thread1, NULL, increment, NULL);
        pthread_create(&thread2, NULL, decrement, NULL);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        if (shared!=5) {
            printf("Race condition detected. Expected 5 got %d.\n", shared);
            race++;
        } else {
            printf("Race was not detected. Expected 5, got %d.\n", shared);
        }
    }
    printf("Process ran for %d times, out of which race was detected %d times.\n", times, race);
    return 0;

}