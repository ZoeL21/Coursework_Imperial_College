// Consumer
# include "helper.h"

using namespace std;

int main (int argc, char *argv[])
{ 
  
  /*read in one command line argument
    (id of consumer)*/
  int id = check_arg(argv[1]);

  //check input
  if(id == -1){
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
    a shared memory segment and consult OS about status*/
  struct shmid_ds checkAttached;
  struct shmid_ds* ca_ptr = &checkAttached;
  
  shmctl(shmid,IPC_STAT,ca_ptr);
  


  int time = 0;
  while(true){
       
    //check if queue is  empty,
    int time_waited = sem_timewait(semid,JOBS,10);
    if (time_waited == -1){
      break;
    }    
    
    //check if shared memry is accessible
    sem_wait(semid,MUTEX);  

    /*get information about job*/
    int jobid = data->job[data->front].id;
    int jobduration = data->job[data->front].duration;

    //increase front pointer inside queue
    data->front += 1;
    data->front = data->front % data->size;

    //release memory
    sem_signal(semid,MUTEX); 
   
    //increase count of empty spaces inside queue
    sem_signal(semid,SPACE);

    
    /*print status*/
    cout<<"Consumer("<<id<<") "<<"time: "<<time;
    cout<<" Job id: "<<jobid;
    cout<<" executing sleep duration: "<<jobduration<<endl;  
 
    //sleep for duration of job in queue
    sleep(jobduration);

    //update time
    time += jobduration;

    /*print status*/
    cout<<"Consumer("<<id<<") "<<"time: "<<time;
    cout<<" Job id: "<<jobid;
    cout<<" completed"<<endl;    
 } 
  
  cout<<"Consumer("<<id<<") no jobs left"<<endl;
 
  //detach from shared memory
  shmdt(data);
  shmctl(shmid,IPC_STAT,ca_ptr);
  cout<<checkAttached->shm_nattch<<endl;

  /*use the struct shmid_ds to delete shared memory
    if this process is the last one attached to it*/
  while(true){

    if(ca_ptr->shm_nattch == 0){
      /*delete memory*/
     int shm = shmctl(shmid,IPC_RMID,ca_ptr);
     if(shm ==  0){
       cout<<"Consumer("<<id<<") DELETED  mem "<<endl;
     }     
     /*delete semaphores*/
     if( sem_close(semid) == 0){
      cout<<"Consumer("<<id<<") DELETED  sem"<<endl;
     }
      break;
    }
  }
 
  return 0;
}
