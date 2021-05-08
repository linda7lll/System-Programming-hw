/*linda türkmen
 * "$ls -1|cut-d'.'-f1|sort|uniq|tee dirents" terminal komutlarını exec ve pip sistem çağrılarıyla gerçekleştiren program
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
		
	int fds[2];
	pipe(fds);
	pid_t pid = fork();
	if(pid == -1)
		pid = fork();
		
	if(pid==0)		//child
	{
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		execlp("ls", "ls", "-1", (char*) NULL);
		exit(1);
	}
	else
	{ 
		sleep(1);
		pid=fork();
		if(pid == -1)
			pid = fork();
		if(pid==0)
		{
			dup2(fds[0], 0);
			close(fds[1]);
			close(fds[0]);
			execlp("cut", "cut", "-f1", "-d.", (char *)NULL); 
			exit(-1);
		}
		else
		{
			sleep(1);
			pid=fork();
			if(pid == -1)
				pid = fork();
			if(pid==0)
			{
				dup2(fds[0], 0);
				close(fds[1]);
				close(fds[0]);
				execlp("sort", "sort", (char*) NULL);
				exit(-1);
			}
					else
					{
						sleep(1);
						pid=fork();
						if(pid == -1)
							pid = fork();
						if(pid==0)
						{
							dup2(fds[0], 0);
							close(fds[1]);
							close(fds[0]);
							execlp("uniq", "uniq", (char*) NULL);
							exit(-1);
						}
						else
						{ sleep (1);
							pid=fork();
							if(pid == -1)
								pid = fork();
							if(pid==0)
							{ 
								dup2(fds[0], 0);
								close(fds[1]);
								close(fds[0]);
								execlp("tee", "tee", "dirents", (char*) NULL);
								exit(-1);
							}
							else
							{ sleep(1);
								int status;
								close(fds[0]);
								close(fds[1]);
								waitpid(pid, &status, 0);
							}
						}
					}
				}
			}
			return 0;
		}
