#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define SHMSZ     27

char IntChar(int numero){
    return numero + '0';
}

main()
{   
    srand(time(NULL));
    char c,n;
    int shmid,num,cont=0;
    key_t key;
    char *shm, *s;

    key = 5678;
    //asgigna segmento
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    //for (c = 'a'; c <= 'z'; c++)
    //    *s++ = c;
    //*s = 's';
    num = rand() % 10;
    n = IntChar(num);
    *s++ = n;
    *s = NULL;

    while (*shm != '*'){
        printf("Wait client Num: %i Cont : %i\n",num,cont++);
        sleep(1);
    }
        

    exit(0);
}

