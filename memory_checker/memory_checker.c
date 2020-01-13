#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdint.h>

void	*malloc(size_t size)
{
	void	*(*malloc_hook)(size_t size);
	void	*result;
	malloc_hook = dlsym(RTLD_NEXT, "malloc");
	result = malloc_hook(size);
	write(1, "1", 1);
	return result;
}

void	free(void *ptr)
{
	void	(*free_hook)(void *ptr);
	free_hook = dlsym(RTLD_NEXT, "free");
	free_hook(ptr);
	write(1, "0", 1);
}
