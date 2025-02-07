/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/07 15:24:00 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# ifndef PIPE
#  define PIPE 6
# endif

# ifndef CMD
#  define CMD 5
# endif

# ifndef FILE
#  define FILE 4
# endif

# ifndef BREAK
#  define BREAK 3
# endif

# ifndef CONTINUE
#  define CONTINUE 2
# endif

# ifndef GO_ON
#  define GO_ON 1
# endif

typedef struct s_bash t_bash;
typedef struct s_var t_var;
typedef struct s_lst_fd t_lst_fd;

typedef struct s_char_arg
{
	char	*str;
	int		is_space;
}	t_char_arg;

typedef struct s_cmd_pos
{
	int	last_type; //1 = pipe 2
	int	start_of_arg;
	int start_of_char;
	int	end_of_arg;
	int end_of_char;
	int	i;
	int	j;
}	t_cmd_pos;

typedef struct s_lst_var
{
	struct s_lst_var	*next;
	char			*string; 
	int				id;
	int				is_squote;
	int				is_space;
}		t_lst_var;

typedef struct s_lst_cmd
{
	struct s_lst_cmd	*next;
	t_char_arg			*arg;
	int					is_space;
	int					id;
}		t_lst_cmd;

typedef struct s_lst_line
{
	struct s_lst_line	*next;
	char				*param;
}		t_lst_line;

typedef struct s_lst_arg
{
	struct s_lst_arg	*next;
	char 				*str;
	int					is_space;
}		t_lst_arg;

//PARSING
t_lst_var	*temp_creation(char *str);
char		*ft_subvar(char const *s, int start, int len, char quote);
int			search_for_quote(t_bash *shell, char *input);
int			ft_strcmp_var(const char *s1, const char *s2);
int			cmd_manager(t_bash *shell, char *input);
int 		parsing(t_bash *shell);
int			search_for_var(t_bash *shell);

//CMD
t_lst_var	*init_cmdarg(t_lst_var *m_lst, t_cmd_pos *pos, t_var *v);
void		move_pos_v(t_lst_var *tmp, t_var *v, t_cmd_pos *pos);
void		exec_create(t_lst_var *main_lst, t_lst_cmd	**cmd_list,
				t_cmd_pos *pos);
t_char_arg	*get_lst_arg(t_lst_var *main_lst, t_cmd_pos *pos);
t_char_arg	*make_arg(t_lst_arg *arg_stack, t_lst_arg *arg_str);
char		*get_lst_fd(t_lst_var *main_lst, t_cmd_pos *pos,
				char *type, char **limit);
int			is_bash_op(char chr, char mod);
int			cmd_parsing(t_bash *shell, t_lst_var *lst_var);
int			search_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
				t_lst_var **tmp, t_cmd_pos *pos);
int			act_as_end_of_line(t_lst_var *main_lst, t_lst_cmd **cmd_list,
				t_lst_var **tmp, t_cmd_pos *pos);
int			act_is_bash_op(t_lst_var *main_lst, t_lst_cmd **cmd_list,
				t_lst_var **tmp, t_cmd_pos *pos);
int			act_is_fd(t_lst_var *main_lst, t_lst_fd **fd_list,
				t_lst_var **tmp, t_cmd_pos *pos);
int			exec_fd(t_lst_var *main_lst, t_lst_cmd **cmd_list,
				t_lst_var **tmp, t_cmd_pos *pos);
int			cmd_list_count(t_lst_cmd **list);
char		find_char(t_lst_var **main_lst, t_cmd_pos *pos);
int			convert_lst_to_line(t_bash *shell, t_lst_line **lst_line,
				t_lst_cmd **lst_cmd, t_lst_fd **lst_fd);

//LST VAR
t_lst_var	*convert_lst(t_lst_var **lst_point);
t_lst_var	*create_new_node_var(char *string, int is_squote);
void		list_add_back_var(t_lst_var **list, t_lst_var *new_node);
void		ft_printf_list_var(t_lst_var **list, int output);
int			lst_create_new_var(t_lst_var **lst_var, 
				char *str, t_var v, char quote);

//LST CMD
t_lst_cmd	*create_new_node_cmd(t_char_arg *arg);
void		list_add_back_cmd(t_lst_cmd **list, t_lst_cmd *new_node);
void		ft_printf_list_cmd(t_lst_cmd **list, int output);

//LST ARG
t_lst_arg	*create_new_node_arg(char *string);
void		list_add_back_arg(t_lst_arg **list, t_lst_arg *new_node);

//LST_LIST
t_lst_line	*create_new_node_line(char *param);
void		list_add_back_line(t_lst_line **list, t_lst_line *new_node);
void		ft_printf_list_line(t_lst_line **list, int output);

//LST_FD
t_lst_fd	*create_new_node_fd(char *name, char type, char *limit);
void		list_add_back_fd(t_lst_fd **list, t_lst_fd *new_node);
void		ft_printf_list_fd(t_lst_fd **list, int output);

//PARSING CLEANING
void	free_list_cmd(t_lst_cmd **lst_cmd);
void	free_list_arg(t_lst_arg **lst_arg);
void	free_list_var(t_lst_var **lst_var);
void	free_list_point(t_lst_var ***lst_var, int len);
void	free_char_arg(t_char_arg *arg);
void	free_list_line(t_lst_line **lst_line);
void	free_list_fd(t_lst_fd **lst_fd);

#endif
