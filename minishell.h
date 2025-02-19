/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:47:13 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/17 10:36:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <signal.h>
# include <errno.h>
# include "src/parsing/parsing.h"
# include "src/exec/builtins.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

typedef enum e_command
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	CMD_COUNT
}	t_command;

typedef struct s_var
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_var;

typedef struct s_cmd
{
	char	*name;
	char	**args;
	int		input;
	int		output;
}	t_cmd;

typedef struct s_lst_fd
{
	struct s_lst_fd	*next;
	char			*name;
	int				fd;
	char			type; // i = input o = output h = here_doc a = append
	char			*limit;
}	t_lst_fd;

typedef struct s_line
{
	struct s_lst_fd	*lst_fd;
	char			**group;
	t_cmd			*cmd;
	int				cmd_nbr;
}	t_line;

typedef struct s_lst
{
	struct s_lst	*next;
	char			*name;
	char			*data;
}		t_lst;

typedef struct s_bash	t_bash;

typedef int				(*t_builtins)(t_bash *, t_cmd *, int );

typedef struct s_func
{
	const char	*name;
	t_builtins	exec;
	int			rtn;
}	t_func;

typedef struct s_bash
{
	struct s_lst	*lst_env;
	t_line			line;
	int				prev_return;
	t_func			func[7];
}	t_bash;

//EXEC
int		single_function(t_bash *shell, t_cmd *cmd);

//INIT FUNCTION
void	init_env(t_bash *shell, char **env);
int		init_struct(t_bash *shell, char **env);

// MAIN FUNCTION
int		main(int argc, char **argv, char **env);
int		ft_minishell(t_bash *shell, char **env);

// SIGNALE
void	init_signale(struct sigaction *sa);
void	handler(int signum);
int		return_signal(int sig, int access);

//CLEANING
void	free_list(t_lst **shell);
void	free_cmd(char **cmd);

//LST
t_lst	*create_new_node(char *data, char *name);
void	list_add_back(t_lst **list, t_lst *new_node);
void	ft_printf_list(t_lst **list, int output);
char	*get_name(char *str);
char	*get_data(char *str);

//UTILS
char	**join_tab(char **tab_dst, char **tab_src);
int		count_line_lst(t_lst *lst);
char	**lst_to_tab(t_lst *lst);
void	print_tabs(char **str, char *s);
int		count_tab(char **str);

#endif
