#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum = 0;
int msum = 0;
void *runner(void *param);

int main(int argc, char *argv[])
	{

	 pthread_t tid;
	 pthread_attr_t attr;
	 pthread_attr_init(&attr);

	 pthread_create(&tid, &attr, runner, argv[1]);

	 //pthread_join(tid,NULL);
	
	 //printf("csum\n");
	 //printf("%d\n", csum);
	 int j;
	 int m = atoi(argv[1]);
	 for(j = 1; j <= m; j++) {
		 msum += j;
	}
	 //printf("msum\n");
	 //printf("%d\n", msum);
	 int ans = csum - msum;
	 printf("%d\n", ans);
	 return 0;
	}
void *runner(void *param) {
	int upper = atoi(param);
	int i;
	if(upper > 0) {
		for(i = 1; i <= upper * 2; i++) { 
			csum += i;
			//printf("%d\n", csum);
		}
	}
	pthread_exit(0);
}
