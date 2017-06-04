//
//  treethread.c
//  treethread
//
//  Created by Quentin Truong on 6/1/17.
//  Copyright © 2017 QT. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread(void *vargp);

struct nt{
    int deep;
    int num;
    int lr;
};

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    
    if (n > 1){
        struct nt* myntA = malloc(sizeof(struct nt));
        myntA->deep = n-1;
        myntA->num = 0;
        myntA->lr = 1;
        
        struct nt* myntB = malloc(sizeof(struct nt));
        myntB->deep = n-1;
        myntB->num = 0;
        myntB->lr = 2;
        
        pthread_t tidA;
        pthread_t tidB;
        
        pthread_create(&tidA, NULL, thread, (void*) myntA);
        pthread_create(&tidB, NULL, thread, (void*) myntB);
        
        pthread_join(tidA, NULL);
        pthread_join(tidB, NULL);
    }
    printf("Thread %d done\n", (int) 0);
    exit(0);
}

void *thread(void *vargp){
    if (((struct nt*)vargp)->deep > 1){
        struct nt* myntA = malloc(sizeof(struct nt));
        myntA->deep = ((struct nt*)vargp)->deep - 1;
        myntA->num = 2*((struct nt*)vargp)->num + ((struct nt*)vargp)->lr;
        myntA->lr = 1;
        
        struct nt* myntB = malloc(sizeof(struct nt));
        myntB->deep = ((struct nt*)vargp)->deep - 1;
        myntB->num = 2*((struct nt*)vargp)->num + ((struct nt*)vargp)->lr;
        myntB->lr = 2;
        
        pthread_t tidA;
        pthread_t tidB;
        
        pthread_create(&tidA, NULL, thread, (void*) myntA);
        pthread_create(&tidB, NULL, thread, (void*) myntB);
        
        pthread_join(tidA, NULL);
        pthread_join(tidB, NULL);
    }
    
    printf("Thread %d done\n", 2*((struct nt*)vargp)->num + ((struct nt*)vargp)->lr);
    return NULL;
}
