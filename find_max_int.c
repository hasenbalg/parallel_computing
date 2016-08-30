#include <stdio.h>
//#include <time.h>
#include <sys/time.h>


#include <limits.h>
long long start_time;



long long current_timestamp() {
//http://stackoverflow.com/a/17083824
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}


find_max_verbose(){
	int i = 1;
	while(i > 0){
		if(++i%100000000 == 0)printf("%d\n", i);
		if (i < 0)return i;
	}
}
find_max(){
        int i = 1;
        while(i > 0){
                //if(++i%100000000 == 0)printf("%d\n", i);
		i += 1;
                if (i < 0)return i;
        }
}

set_start_time(){
	start_time = current_timestamp();
}

get_end_time(){

 printf("%lld ms took\n", current_timestamp() - start_time); 
}
main(){
	set_start_time();
	printf("max int value is %d\n",find_max_verbose()-1);
	get_end_time();	
	
	set_start_time();
        printf("max int value is %d\n",find_max()-1);
	get_end_time();	
	
	set_start_time();
        printf("max int value is %d\n",INT_MAX);
	get_end_time();	
}
