#include "philo.h"

// void *print_pid()
// {
//         printf("%d\n",(int)getpid());
//         while(1)
//                 return(NULL);
// }

// int main()
// {
//         pthread_t pid;
//         printf("THE PID IS:%d\n",(int)getpid());
//         pthread_create(&pid,NULL,&print_pid,NULL);
//         while(1)
//                 return(0);
// }
void function(int n, char c)
{
        int i;
        
        i = 0;
        while(i <= n)
        {
                printf("%c\n",c);
                i++;
        }
}
void *thread_A()
{
        function(10,'A');
        printf("\nfin de A\n");
        pthread_exit(NULL);
}
void *thread_C()
{
        function(10,'C');
        printf("\nfin de C\n");
        pthread_exit(NULL);
}

void *thread_B()
{
pthread_t B ;
pthread_create(&B , NULL , thread_C , NULL) ;
function(10,'B');
printf( "\nB attend la finc de C\n " ) ;
pthread_join(B ,NULL) ;
printf( "\n Fin du thread B\n " ) ;
pthread_exit(NULL) ;
}

// int main()
// {
//         pthread_t a;
//         pthread_t b;

//         pthread_create(&a,NULL,&thread_A,NULL);
//         pthread_create(&b,NULL,&thread_B,NULL);
//         sleep(1);

//         pthread_join(a,NULL);
//         pthread_join(b,NULL);
//         exit(0);
// }