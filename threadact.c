/*
    threadact.c - thread activity using mutex and shared variable
    Name: Pablo Valdes
    Affirmation of Originality: This program is my own original work
    Description: Creates 5 threads, each adds its thread number to a shared variable safely using a mutex.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared = 0;
pthread_mutex_t lock;

void* add_thread_num(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&lock);
    shared += id;
    printf("Thread ID: %d\n", id);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1; // IDs: 1 to 5
        pthread_create(&threads[i], NULL, add_thread_num, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final shared value: %d\n", shared);
    pthread_mutex_destroy(&lock);

    return 0;
}
