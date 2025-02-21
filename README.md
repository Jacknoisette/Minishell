Problem found at date 21/02/25

Global problem :

Builtins problems :
Leak in export (ft_strdup) [not fix]

Parsing problem :

Exec problem :
invalid read of size 8 in ft_execve in case of (Input  : >file1) works also if heredoc
  I think the problem comes from the fact that there is no cmd in the line because in case of (Input : >file1 | >file1) there is style the invalid read
Heredoc exit the program !!!
Heredoc leak 3 bytes
