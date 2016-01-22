/******************************************************************
 * Program for setting up semaphores/shared memory before running
 * the Producer and Consumer 
 ******************************************************************/

# include "helper.h"

using namespace std;

int main (int argc, char **argv){

  //initializing size of the queue
  int size = check_arg(argv[1]);

  //check input
  if(size == -1){
    cout<<"arg not a valid number"<<endl;
    exit(1);
  }
  
  //create a shared memory segment
  int shmid = shmget(SHM_KEY,SHM_SIZE, 0666 | IPC_CREAT);

  //create and initialize the semaphores
  int semid = sem_create(SEM_KEY,3);

  sem_init(semid,MUTEX,1);
  sem_init(semid,SPACE,size);
  sem_init(semid,JOBS,0);
  

  /*Associate with shared memory segment, IF available*/
  queue* data;
  data = (queue*)shmat(shmid, (void *)0, 0);
  if(data == (queue*)(-1)){
    perror("shmat");
  }

  //set size of queue to argv[1]
  data->size = size;
  //set front and end to be the first element in job array;
  data->front = 0;
  data->end = 0;

  /*detach from memory segment*/
  shmdt(data);

  return 0;
}
