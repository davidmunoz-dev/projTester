/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:13:03 2016 David Munoz
** Last update Wed Jun 22 10:17:56 2016 David Munoz
*/

#include <stdlib.h>
#include <unistd.h>

void	my_ps_synthesis()
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == 0)
    {
      if ((execlp("ps", "ps", NULL)) == -1)
        exit(84);
    }
  wait(&status);
}
