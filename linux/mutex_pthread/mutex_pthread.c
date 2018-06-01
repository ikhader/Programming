#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void* pthread_func(void * lParam)
{
  int i;
  char *t = (char*)lParam;

  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  printf("Vol switch[%ld] invol[%ld]\n", usage.ru_nvcsw, usage.ru_nivcsw);
 
  for(i = 0; i < 5; i++)
  {
    pthread_mutex_lock(&m);
    sleep(1);
    printf("[%s]\n", t);
    pthread_mutex_unlock(&m);
  }
  printf("@@@@@[%s]@@@@@@@@@@@@@@@@ \n", t);
  getrusage(RUSAGE_SELF, &usage);
  printf("Vol switch[%ld] invol[%ld]\n", usage.ru_nvcsw, usage.ru_nivcsw);
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t thread_id_1 = 0;
  pthread_t thread_id_2 = 0;
  char t1[] = "Hello thread one";
  char t2[] = "Hello thread two";
  pthread_create(&thread_id_1, NULL, pthread_func, (void*)t1);
  pthread_create(&thread_id_2, NULL, pthread_func, (void*)t2);

  pthread_join(thread_id_1, NULL);
  pthread_join(thread_id_2, NULL);
  printf("Thread exit\n");
}
