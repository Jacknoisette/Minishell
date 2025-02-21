Problem found at date 21/02/25

Global problem :

Builtins problems :
Leak in export (ft_strdup) [not fix]
exit cause leak
exit don't manage exit code

Parsing problem :

Exec problem :
invalid read of size 8 in ft_execve in case of (Input  : >file1) works also if heredoc
  I think the problem comes from the fact that there is no cmd in the line because in case of (Input : >file1 | >file1) there is style the invalid read
Heredoc exit the program !!!
Heredoc leak 3 bytes
Certain probleme avec cat et avec heredoc
Erreur dans le cas ou builtins + |

Result of experience (Not a problem just something to know)
  if (input : echo $USER >file1 >>file1)
    bash write $USER in the first occurence of a file
