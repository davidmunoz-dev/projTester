/*
** utils.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/FASTAtools/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun 19 19:46:59 2016 David Munoz
** Last update Thu Jun 23 21:03:46 2016 David Munoz
*/

#include "proj.h"
#include "utils.h"

void	*cerr_msg_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int	cerr_exit(char *log, int status)
{
  write(2, log, my_strlen(log));
  exit(status);
}

int	my_len_tab(char *str)
{
  int   i;
  int   r;

  r = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == ':')
        r++;
      i++;
    }
  return (r);
}

void	free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
