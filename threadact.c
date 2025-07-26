/*
    threadact.c - thread activity using mutex and shared variable
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
    Description: Creates 5 threads, each adds its thread ID to a shared variable safely using a mutex.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared = 0;
pthread_mutex_t lock;

void* add_thread_id(void* arg) {
    pthread_t tid = pthread_self();

    pthread_mutex_lock(&lock);
    shared += (int)(uintptr_t)tid;
    printf("Thread ID: %lu\n", tid);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, add_thread_id, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final shared value: %d\n", shared);
    pthread_mutex_destroy(&lock);

    return 0;
}
