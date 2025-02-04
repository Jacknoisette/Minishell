/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:00:55 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/04 14:45:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_bash t_bash;
typedef struct s_var t_var;

typedef struct s_cmd_pos
{
	int	start_of_arg;
	int start_of_str;
	int start_of_char;
	int	end_of_arg;
	int end_of_str;
	int end_of_char;
}	t_cmd_pos;

typedef struct s_lst_var
{
	struct s_lst_var	*next;
	char			*string; 
	int				is_squote;
}		t_lst_var;

typedef struct s_lst_cmd
{
	struct s_lst_cmd	*next;
	char				**arg; 
	int					id;
}		t_lst_cmd;

typedef struct s_lst_arg
{
	struct s_lst_arg	*next;
	char 				*str;
}		t_lst_arg;

//PARSING
t_lst_var	*temp_creation(char *str);
char		*ft_subvar(char const *s, int start, int len, char quote);
int			search_for_quote(t_bash *shell, char *input);
int			ft_strcmp_var(const char *s1, const char *s2);
int			cmd_manager(t_bash *shell, char *input);
int 		parsing(t_bash *shell);
int			search_for_var(t_bash *shell);

//LST VAR
t_lst_var	*create_new_node_var(char *string, int is_squote);
void		list_add_back_var(t_lst_var **list, t_lst_var *new_node);
void		ft_printf_list_var(t_lst_var **list, int output);
int			lst_create_new_var(t_lst_var **lst_var, 
				char *str, t_var v, char quote);

//LST CMD
t_lst_cmd	*create_new_node_cmd(char **arg);
void		list_add_back_cmd(t_lst_cmd **list, t_lst_cmd *new_node);
int			cmd_parsing(t_bash *shell, t_lst_var **lst_var, int len);

//LST ARG
t_lst_arg	*create_new_node_arg(char *string);
void		list_add_back_arg(t_lst_arg **list, t_lst_arg *new_node);

//PARSING CLEANING
void	free_list_arg(t_lst_arg **lst_arg);
void	free_list_var(t_lst_var **lst_var);
void	free_list_point(t_lst_var ***lst_var, int len);

#endif
