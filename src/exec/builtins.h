/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:07:05 by tgoudman          #+#    #+#             */
/*   Updated: 2025/03/04 17:06:59 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_line	t_line;
typedef struct s_func	t_func;
typedef struct s_bash	t_bash;
typedef struct s_cmd	t_cmd;
typedef struct s_lst	t_lst;

/* # define close(fd) \
do \
{ \
	fprintf(stderr, "close(%d) at %s:%d\n", \
			fd, __FILE__, __LINE__); \
	close(fd); \
} while (0)

# define pipe(pipefd) \
({ \
	int ret = pipe(pipefd); \
	if (ret == -1) \
		fprintf(stderr, "pipe(%p) at %s:%d failed: %s\n", \
				pipefd, __FILE__, __LINE__, strerror(errno)); \
	else \
		fprintf(stderr, "pipe("#pipefd") = {%d,%d} at %s:%d\n", \
		pipefd[0], pipefd[1], \
		__FILE__, __LINE__); \
	ret; \
})

# define dup(fd) \
({ \
	int ret = dup(fd); \
	fprintf(stderr, "dup(%d) = %d at %s:%d\n", \
			fd, ret, __FILE__, __LINE__); \
	 if (ret == -1) \
	 	perror("dup"); \
	ret; \
})

# define dup2(fd1, fd2) \
do \
{ \
	fprintf(stderr, "dup2(%d, %d) at %s:%d\n", \
			fd1, fd2, __FILE__, __LINE__); \
	 if (dup2(fd1, fd2) == -1) \
	 	perror("dup2"); \
} while (0) */

//BUILTIN
int		ft_echo(t_bash *shell, t_cmd *cmd, int output);
int		ft_cd(t_bash *shell, t_cmd *cmd, int output);
int		ft_pwd(t_bash *shell, t_cmd *cmd, int output);
int		ft_export(t_bash *shell, t_cmd *cmd, int output);
int		ft_unset(t_bash *shell, t_cmd *cmd, int output);
int		ft_env(t_bash *shell, t_cmd *cmd, int output);
int		ft_exit(t_bash *shell, t_cmd *cmd, int output);
int		init_execve(t_bash *shell);
int		ft_append(char *str);
int		ft_open_file(char *str, int file);
void	close_fd(t_bash *shell);
void	init_func(t_func *builtin);
char	*search_file(t_bash *shell, int index_cmd);
void	redirect_fd(t_bash *shell, char *str);
int		get_fd(t_bash *shell, char *str);
int		check_cmds(t_bash *shell);
int		redirect_fd_infile(t_bash *shell, char *str);
int		check_function(t_cmd cmd);
int		open_fds(t_bash *shell);
int		check_cmds(t_bash *shell);
void	launch_builtins(t_bash *shell, int index, int *pipe_fd, int oldpipe);
char	*get_path(t_bash *shell, char *cmd);
int		ft_atoi_exit(const char *nptr);
char	get_input(t_bash *shell, char *str);
int		search_pipe(t_bash *shell, int nbr);
// void	launch_cmd(t_bash *shell, t_cmd cmd, int index);
// char	*search_infile(t_bash *shell, int index);
// void	do_pipe(t_bash *shell, t_cmd cmd, int index, int *pipe_fd);
// void	print_open_fds(const char *where);

//HEREDOCS
void	init_heredocs(t_bash *shell);
int		ft_heredoc(char *del, char *str);
char	*handle_multiple_heredocs(t_bash *shell);
void	ft_execve_heredocs(t_bash *shell, char *str);
int		get_cmd(t_bash	*shell, char *str);
void	close_fd_heredocs(t_bash *shell);
char	*search_infile(t_bash *shell);
int		ft_execve(t_bash *shell);
int		search_infile_remake(t_bash *shell);
void	launch_cmd(t_bash *shell, t_cmd cmd, int index);
int		do_pipe(t_bash *shell, int index, int old_fd, int *pipe_fd);
int		ft_command_one(t_bash *shell, int index);
int		get_fd_infile(t_bash *shell, char *str);
char	*search_file_two(t_bash *shell, int index_cmd);

// CLEANING
void	free_cmds(t_bash *shell);
void	free_cmd_exec(char **cmd);
void	free_list_env(t_lst *env);
void	free_tab(char **tab);
void	ft_exit_signale(t_bash *shell, pid_t pid);

#endif