/*
** utils2.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 23 22:09:31 2016 David Munoz
** Last update Fri Jun 24 23:03:39 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

void	print_coma(int j)
{
  int   r;

  r = j % 4;
  while (r >= 0)
    {
      my_putchar('-');
      r--;
    }
}

int	check_input(char *str, int i)
{
  while (str[i] >= 'A' && str[i] <= 'Z')
    i++;
  if (str[i] == ':')
    return (0);
  return (1);
}

char	*my_epur_cmd(char *str)
{
  char	*cmd;
  int	i;
  int	x;

  if ((cmd = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    cerr_exit("Error: Malloc failed\n", 84);
  i = x = 0;
  while (str[i])
    {
      if (str[i] == '\n')
        cmd[x++] = ' ';
      else if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  if (check_input(str, i) == 0)
	    while (str[i] >= 'A' && str[i] <= 'Z')
	      i++;
	  else
	    cmd[x++] = str[i];
	}
      else
        cmd[x++] = str[i];
      i++;
    }
  cmd[x] = 0;
  return (cmd);
}

char	*epur_line(char *str)
{
  char	*line;
  int	i;
  int	x;
  int	j;

  j = 0;
  i = -1;
  x = 0;
  if ((line = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
    cerr_exit("Error: Malloc failed\n", 84);
  while (str[++i])
    if (str[i] == '/')
      x++;
  i = -1;
  while (str[++i] && x > 0)
    {
      if (str[i] == '/')
	x--;
      line[j] = str[i];
      j++;
    }
  line[j] = 0;
  return (line);
}
