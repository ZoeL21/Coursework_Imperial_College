// Producer

# include "helper.h"

using namespace std;

int main (int argc, char *argv[])
{  

  /*read in two command line arguments
    (id of producer and number of jobs to generate*/
  int id = check_arg(argv[1]);

  //check input
  if(id == -1){
    cout<<"arg not a valid number"<<endl;
    exit(1);
  }
  
  //get the number of jobs to create
  int num = check_arg(argv[2]);
  
  if(num == -1){
    cout<<"arg not a valid number"<<endl;
    exit(1);
  }
  
  /*connect to shared memory created in start.cc*/
  int shmid = shmget(SHM_KEY,SHM_SIZE, 0666);

  /*Associate with shared memory segment, IF available*/
  queue* data;
  data = (queue*)shmat(shmid, (void *)0, 0);
  if(data == (queue*)(-1)){
    perror("shmat");
  }
  
  /*attach to semaphore created in startet.cc*/
  int semid = sem_attach(SEM_KEY);

  /*create a struct shmid_ds to count number of processes attached to 
    a shared memory segment and consult OS about status */
  struct shmid_ds checkAttached;
  struct shmid_ds* ca_ptr = &checkAttached;  
  shmctl(shmid,IPC_STAT,ca_ptr); 

 
 /*Add the required number of jobs to the circular queue.
    Block if queue is full*/
  int time = 0;
  int job_produced = 0;
  while(job_produced < num){

    //wait two to four seconds
    int wait_seconds = 2 + rand() % (4 - 2 + 1);    
    //generate jobduration between 2 and 7 seconds
    int jobduration = 2 + rand() % (7 - 2 + 1);    
    
    
    /*if the shared memory is full, wait for it to get empty.
      If no jobs get taken by consumers, within 1000 seconds, assuming 
      there are no consumers,quit*/    
    if(sem_timewait(semid,SPACE,1000) != 0){
      break;
    }

    /*check if the shared memory is free.
      calls a down operation on the semaphore and blocks
      if shared memory is being used.*/ 
    sem_wait(semid,MUTEX);
    
    //produce job and add it to memory
    JOBTYPE job;   
    int jobid = 1 + data->end;
    job.id = jobid;   
    job.duration = jobduration;
    data->job[data->end] = job;   


    //increase the end in queue 
    data->end += 1;   
    data->end = data->end % (data->size); 

    
    //call up on Mutex semaphore to free access to shared mem
    sem_signal(semid,MUTEX);

    //increase semaphore value which counts jobs in queue
    sem_signal(semid,JOBS);

    
    //Print status
    cout<<"Producer("<<id<<") ";
    cout<<"time: "<<time<<" Job id: "<<jobid;
    cout<<" duration "<<jobduration<<endl;
    
    //wait two to four seconds until asking for memory access again
    sleep(wait_seconds);

    //reset time
    time += wait_seconds;

    //increase job_produced counter
    job_produced++;        
    
  }
  cout<<"Producer("<<id<<"): no more jobs to generate"<<endl;
 

  //detach from shared memory
  shmdt(data);
  shmctl(shmid,IPC_STAT,ca_ptr);

  /*in this design it was decided,that the producer would
    not be able to delete the shared mamory and the semaphores*/

  /*however, it was decided to make the producer wait until
    all other processes are detached from memory, before exiting
    as otherwise, semaphores may be reset too early*/
  while(true){
    if(ca_ptr->shm_nattch == 0){
      break;
    }
  }

  return 0;
}
