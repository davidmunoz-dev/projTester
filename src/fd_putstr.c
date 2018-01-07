/*
** fd_putstr.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Jun 24 22:51:07 2016 David Munoz
** Last update Fri Jun 24 23:45:50 2016 David Munoz
*/

#include "proj.h"
#include "utils.h"

void	fd_putstr(char *str, char **av, int ac)
{
  int	fd;

  if (ac == 3)
    my_putstr(str);
  else
    {
      if ((fd = open(av[3], O_APPEND | O_WRONLY)) == -1)
	cerr_exit("Internal error: Open failed\n", 84);
      write(fd, str, my_strlen(str));
      close(fd);
    }
}

void	fd_putchar(char c, char **av, int ac)
{
  int	fd;

  if (ac == 3)
    my_putchar(c);
  else
    {
      if ((fd = open(av[3], O_APPEND | O_WRONLY)) == -1)
	cerr_exit("Internal error: Open failed\n", 84);
      write(fd, &c, 1);
      close(fd);
    }
}
