#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h>

#define SHMSZ 27

main()
{
    char *args[]={"./p1","./p3",NULL};
    int shmid,num;
    key_t key;
    char *shm, *s,*ss;

    key = 5678;

    if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    for (s = shm; *s != NULL; s++){
            ss=s;
        //putchar(*s);
        printf("Start p2 Program...\n");
    }
        
    //putchar('\n');

    //printf("num: %i\n",*ss-'0'+2);
    num = *ss-'0';
    if(num%2==0){
        printf("The number is EVEN: %i\n",num);
        *shm = '*';
        execvp(args[0],args); 
    }
    else{
        execvp(args[1],args); 
    }
    
    
    

    exit(0);
}
