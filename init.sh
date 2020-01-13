gcc memory_checker/memory_checker.c -o memory_checker/memory_checker.so -fPIC -shared -ldl -D_GNU_SOURCE
export LD_PRELOAD="/home/nullfinder/CProjects/Minishell/memory_checker/memory_checker.so"
