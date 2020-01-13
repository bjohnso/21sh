gcc memory_checker/memory_hooks.c -o memory_checker/memory_hooks.so -fPIC -shared -ldl -D_GNU_SOURCE
export LD_PRELOAD="/home/nullfinder/CProjects/Minishell/memory_checker/memory_hooks.so"
