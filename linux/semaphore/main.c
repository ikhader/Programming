#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

/*
Notes: This is binary semaphore
Binary semaphores: 
1. this is also known as mutex
2. can only take two values 0 & 1
3. it can implemented across processes as well

this example we will have three threads sharing a semaphore

observations:
1. we can see that semaphore is intialized to 3 (SEMA_INTIAL_VAL) meaning that 3 threads are allowed to getin. For
every thread we get in semaphore counter decrements its value by 1.. once it reaches zero.. no more threads can enter
2. In the output we see that 3 thread ids are printed & sleep(3) will happen

steps to compile:
gcc main.c -lpthread
*/
#define SEMA_THREAD_SHARE  0
#define SEMA_PROCESS_SHARE 1

#define SEMA_INTIAL_VAL 3

sem_t sem;

void *pthread_func(void *b)
{
  int i = 0;
  for(i = 0; i < 3; i++)
  {
    sem_wait(&sem); //wait/acquire semaphore here
    printf("in thread: [%ld] \n", pthread_self()); 
    sleep(3);
    sem_post(&sem); //releaes & signal other threads
  }
  return NULL;
}

int main(int argc, char *argv[])
{

  sem_init(&sem, SEMA_THREAD_SHARE, SEMA_INTIAL_VAL);

  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, pthread_func, NULL);
  pthread_create(&t2, NULL, pthread_func, NULL);
  pthread_create(&t3, NULL, pthread_func, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  sem_destroy(&sem);

  printf("done executing \n");
  
  return 0;
}
