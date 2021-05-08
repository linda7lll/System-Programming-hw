/*
 *Linda türkmen
 *parent process ve child process kullanarak programın çıktısı BBBBBBBBBBBBaaaaaaaa olacak.
 *hm2
 *1.b
 */

#include <stdio.h>
#include <unistd.h>
#include <wait.h> 
#include <stdlib.h>
 int main(){
	 
	   
	 for(int a =0; a<20;a++){
		 //parent process
		 printf("a");
		 fflush(stdout);
		 
		 int p = fork();
		 if(p==0){
			 //child(1)
			 printf("B");
			 //child(2)
			 printf("c");
		 exit(0);
	 }
	 else wait(0);
	 
	 }
	   
	 return 0;
 }
