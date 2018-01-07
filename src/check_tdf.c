/*
** check_tdf.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Jun 24 19:01:46 2016 David Munoz
** Last update Fri Jun 24 23:22:37 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

int	check_tdf(int x, char *str)
{
  x++;
  while (str[x])
    {
      if (str[x] == '/')
        return (1);
      x++;
    }
  return (0);
}

int	search_for_tdf(char *str, char **av, int ac)
{
  FILE		*output;
  char		*ln;
  size_t	len;

  len = 0;
  ln = NULL;
  if ((output = popen(str, "r")) == NULL)
    cerr_exit("Internal error: Popen failed\n", 84);
  while (getline(&ln, &len, output) != -1)
    {
      check_line(ln, av, ac);
    }
  if (pclose(output) != 0)
    cerr_exit("Could not run more or other error.\n", 84);
  free(ln);
  exit(0);
  return (0);
}

int	create_tree_search(char **av, int ac)
{
  int	fd;
  char	*str;

  if ((str = malloc(my_strlen(av[1]) + 30)) == NULL)
    cerr_exit("Internal error: Malloc failed\n", 84);
  my_strcpy(str, "tree -Ffi --noreport ");
  my_strcat(str, av[1]);
  if (ac == 4)
    {
      if ((fd = open(av[3], O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
  	cerr_exit("Internal error: Open failed\n", 84);
      close(fd);
    }
  search_for_tdf(str, av, ac);
  return (0);
}
