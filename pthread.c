#include <stdio.h>
#include <pthread.h>

int sum; //var data shared by all threads
//git check
void *runner(void *param){  //function called by threads
    int i, upper=atoi(param);
    sum=0;

    for (i=1;i<=upper;i++){
        sum+=i;
    }
    pthread_exit(0);
}  

int main(int argc,char *argv){
    pthread_t tid;  //thread ID
    pthread_attr_t attr;  //set of threaad aattributes

    if (argc!=2){
        fprintf(stderr,"usage: a.out <int value>");
        return -1;
    }
    if (atoi(argv[1])<0){
        fprintf(stderr,"%d must be >=0\n",atoi(argv[1]));
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);

    printf("sum = %d",sum);
 }