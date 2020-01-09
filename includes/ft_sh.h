# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

//Artifacts
typedef struct      s_shell
{
    char            **environ;
    char            *dir;
    char            *home_dir;
    bool            exit;
}                   t_shell;

typedef struct      s_agent
{
    char            *alias;
    char            *target;
    char            *options;
    char            **files;
    char            **exec_args;
    bool            execution_status;
}                   t_agent;

typedef struct      s_token
{
    char            *lexeme;
    char            *type;
    int             pos;
}                   t_token;

typedef struct      s_token_list
{
    t_token         *tokens;
    t_agent         *agent;
    int             size;
}                   t_token_list;

typedef struct      s_buffer
{
    char            *str;
    int             size;
}                   t_buffer;

//Shell
t_shell             *new_shell();

//Environ
char                **environ_init(char **env);
void                environ_push(t_shell *shell, char *pair);
int                 environ_search(char **env, char *pair, int split);
void                environ_replace(t_shell *shell, char *pair, int position);
void                environ_delete(t_shell *shell, int position);
char                *environ_pair_clone(char *original);

//Parser
char                *lexer(char *str);
t_token_list        *parser(char *str);

//Token
t_token             *generate_token(char  *lexeme, int pos);
t_token             *new_token(char  *lexeme, int pos, char *type);
t_token_list        *new_token_list();
void                token_list_push(t_token_list *token_list, t_token *token);
void                token_list_destroy(t_token_list *token_list);

//Input Reader
char                *input_reader();

//Buffer
t_buffer            *new_buffer();
void                buffer_push(t_buffer *buffer, char c);

//Agency
void                compute_execute(t_agent *approved_agent, t_token_list *token_list);

//Agent
t_agent             *new_agent(char *alias);
char                *agent_map_target(char *alias);
void                agent_options_push(t_agent *agent, char option);
void                agent_files_push(t_agent *agent, char *file);
void                agent_generate_exec_args(t_agent *agent);
void                agent_clone(t_agent *clone, t_agent *agent);

//Executor Manager
int                 execute(t_shell *shell, t_agent *agent);

//Shell-Builtins
void                mini_echo(t_agent *agent);
int                 mini_cd(t_shell *shell, t_agent *agent);
void                mini_env(t_shell *shell);
int                 mini_setenv(t_shell *shell, t_agent *agent);
int                 mini_unsetenv(t_shell *shell, t_agent *agent);

#endif