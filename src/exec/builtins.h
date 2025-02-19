/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:07:05 by tgoudman          #+#    #+#             */
/*   Updated: 2025/02/13 10:52:06 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_line	t_line;
typedef struct s_func	t_func;
typedef struct s_bash	t_bash;
typedef struct s_cmd	t_cmd;

//BUILTIN
int		ft_echo(t_bash *shell, t_cmd *cmd, int output);
int		ft_cd(t_bash *shell, t_cmd *cmd, int output);
int		ft_pwd(t_bash *shell, t_cmd *cmd, int output);
int		ft_export(t_bash *shell, t_cmd *cmd, int output);
int		ft_unset(t_bash *shell, t_cmd *cmd, int output);
int		ft_env(t_bash *shell, t_cmd *cmd, int output);
int		ft_exit(t_bash *shell, t_cmd *cmd, int output);
int		ft_execve(t_bash *shell);
void	ft_heredoc(char *str, char	*del);
int		init_execve(t_bash *shell);
void	open_fds(t_bash *shell);
int		ft_append(char *str);
int		ft_open_file(char *str, int file);
void	close_fd(t_bash *shell);
void	init_func(t_func *builtin);
char	*get_path(char *cmd);
char	*search_file(t_line *line, int index_cmd);
void	redirect_fd(t_bash *shell, char *str);

#endif