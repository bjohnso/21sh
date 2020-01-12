# ifndef FT_SH_H
# define FT_SH_H

#include "libft.h"

//Artifacts
typedef struct      s_shell
{
    char            **environ;
    char            **dir;
    bool            exit;
}                   t_shell;

typedef struct      s_agent
{
    char            *alias;
    char            *target;
    char            *options;
    char            **files;
    char            **exec_args;
    bool            command_status;
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
    size_t			size;
}                   t_token_list;

typedef struct      s_buffer
{
    char            *str;
    size_t			size;
}                   t_buffer;

//Shell
t_shell             *new_shell();

//Directory
char                *file_search(char *dir, char *alias);
void				build_file_path(char *file, char *dir, char *alias);

//Environ
char                **environ_init(char **env);
void                environ_push(t_shell *shell, char *pair);
int                 environ_search(char **env, char *pair, int split);
char                *environ_get_value(char **env, int pos);
void                environ_replace(t_shell *shell, char *pair, int position);
void                environ_delete(t_shell *shell, int position);
char                *environ_pair_clone(char *original);

//Parser
char                *lexer(char *expansion, char *str);
t_token_list        *parser(t_shell *shell, char *str);
int                 quote_lex(char *str);
char                *space_lex(char *str);
char                *new_lexeme(char *str, int size);
int                 delim(char *str);
char                *expand(char *lexeme, char *expansion, int pos);
int					fill_alt(char *expanded, char *expansion, size_t c, size_t pos);
char				*expand_return(char *lexeme, char *expanded);

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
t_agent             *compute_execute(t_shell *shell, t_token_list *token_list);

//Agent
t_agent             *new_agent(t_shell *shell, t_token *token);
char                *agent_map_target(char **env, char *alias);
void                agent_opt_push(t_agent *agent, char option);
void                agent_files_push(t_agent *agent, char *file);
void                agent_generate_exec_args(t_agent *agent);
void                agent_clone(t_agent *clone, t_agent *agent);

//Executor Manager
int                 execute(t_shell *shell, t_agent *agent);
int					execute_builtin(t_shell *shell, t_agent *agent);

//Shell-Builtins
void                mini_echo(t_shell *shell, t_agent *agent);
int                 mini_cd(t_shell *shell, t_agent *agent);
void                mini_env(t_shell *shell);
int                 mini_setenv(t_shell *shell, t_agent *agent);
int                 mini_unsetenv(t_shell *shell, t_agent *agent);

#endif