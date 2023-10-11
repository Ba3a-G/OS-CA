#include <stdio.h>
#include <pthread.h>

void *even()
{
    for (int i = 2; i <= 100; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void *odd()
{
    for (int i = 1; i <= 99; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    pthread_t threadEven, threadOdd;
    pthread_create(&threadEven, NULL, even, NULL);
    pthread_create(&threadOdd, NULL, odd, NULL);
    pthread_join(threadEven, NULL);
    pthread_join(threadOdd, NULL);
    return 0;
}