/*
** search.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 23 12:04:24 2016 David Munoz
** Last update Fri Jun 24 13:28:32 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

char	**get_file_path(FILE *output, char **av)
{
  char		**tab;
  char		*ln;
  size_t	len;
  int		x;

  x = 0;
  ln = NULL;
  len = 0;
  while (getline(&ln, &len, output) != -1);
  if ((tab = malloc(sizeof(char *) * my_len_tab(ln) + 2)) == NULL)
    cerr_exit("Internal error: Malloc failed\n", 84);
  tab = my_str_to_wordtab(ln, ':');
  free(ln);
  while (tab[x])
    {
      my_strcat(tab[x], "/");
      my_strcat(tab[x], av[2]);
      x++;
    }
  return (tab);
}

int	my_path(char *str, char **av)
{
  FILE  *output;
  char  **path;
  int	i;

  i = 0;
  if ((output = popen(str, "r")) == NULL)
    cerr_exit("Internal error: Popen failed\n", 84);
  path = get_file_path(output, av);
  if (pclose(output) != 0)
    cerr_exit("Could not run more or other error.\n", 84);
  if (access(av[2], F_OK | X_OK) == 0)
    return (0);
  while (path[i])
    {
      if (access(path[i], F_OK | X_OK) == 0)
	return (0);
      i++;
    }
  return (cerr_exit("Binary not found !\n", 84));
}
