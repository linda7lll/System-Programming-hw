/*
 *Linda türkmen
 *parent process ve child process kullanarak programın çıktısı cccaaaaBBBB olacak.
 *hm2
 *2.b
 */

#include <stdio.h>
#include <unistd.h>
#include <wait.h> 
#include <stdlib.h>
 int main(){
    
		 for(int a =0; a<20;a++){
		 int p = fork();
			 if(p==0){
				 //child(2)
				 printf("c");
			     exit(0);
		    	}
	               else wait(0);
                     }
          
				for(int a =0; a<20; a++){
				 //parent
				 printf("a");
				 fflush(stdout);	
						
					     }
			
			
                         for(int a =0; a<20;a++){
				 int p = fork();
				  if(p==0){
				   //child(1)
				   printf("B");
				 	 exit(0);
						}
					else wait(0);
				   }
          
		      return 0;
	      }
