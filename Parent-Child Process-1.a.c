
/*
 *Linda türkmen
 *parent process "a", child process "B" yazdıran program.
 * Program çıktısı aBaBaBaBaBaBaBaB
 *hm2
 *1.a
 */
#include <stdio.h>
#include <unistd.h>
#include <wait.h> 
#include <stdlib.h>
 int main(){
	 
	   
	   
	 for(int a =0; a<10;a++){
		 //parent
		 printf("a");
		 fflush(stdout);
		 
		 int p = fork();
		 if(p==0){
           //child
			 printf("B");
		 exit(0);
	 }
	 else wait(0);
	 
	 }
	   
	 return 0;
 }
