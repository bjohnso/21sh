#define _GNU_SORCE

#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>


static void		*(*malloc_hook)(size_t size) = NULL;
static void		(*free_hook)(void *ptr) = NULL;

static void		malloc_trace_init(void)
{
	malloc_hook = dlsym(RTLD_NEXT, "malloc");
	if (NULL == malloc_hook)
	{
		fprintf(stderr, "ERROR in dlsym : %s\n", dlerror());
	}
}

static FILE		*init_logfile(char *log_file)
{
  	int fd;
  	if((fd=open(log_file,O_CREAT|O_APPEND|O_WRONLY,0644))!=-1)
  	{
    	dup2(fd,2);
  	}
  	else
  	{
    	perror(log_file);
  	}
}

static void		free_trace_init(void)
{
	free_hook = dlsym(RTLD_NEXT, "free");
	if (NULL == free_hook)
	{
		fprintf(stderr, "ERROR in dlsym : %s\n", dlerror());
	}
}

void	*malloc(size_t size)
{
	init_logfile("malloc.log");
	malloc_trace_init();
	void	*p = NULL;
	p = malloc_hook(size);
	//fprintf(stderr, "malloc(%ld) = ", size);
	fprintf(stderr, "%p\n", (unsigned int *)p);
	return p;
}

void	free(void *ptr)
{
	init_logfile("free.log");
	free_trace_init();
	fprintf(stderr, "%p\n", (unsigned int *)ptr);
	free_hook(ptr);
}
