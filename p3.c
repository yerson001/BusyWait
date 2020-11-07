#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h> 
#include<unistd.h>

#define SHMSZ     27

main()
{
    char *args[]={"./p1",NULL};
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
        printf("Star p3 program...\n");
    }
        
    //putchar('\n');

    //printf("num: %i\n",*ss-'0'+2);
    num = *ss-'0';
    if(num%2==1){
        printf("The number is ODD: %i\n",num);
        *shm = '*';
        execvp(args[0],args); 
    }
    exit(0);
}
