/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:13:03 2016 David Munoz
** Last update Sat Jun 25 11:05:50 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

int	help()
{
  my_putstr("\tUSAGE\t\t./projTester TRD [BFT] [outputFile]\n\n");
  my_putstr("\tTRD\t\troot directory of all the tests\n");
  my_putstr("\tBFT\t\tbinary file to be tested\n\toutputFile\t");
  my_putstr("file in which the ressult is printed\n");
  return (84);
}

int	get_path(char **av, int ac)
{
  char	*str;

  if ((str = malloc(12)) == NULL)
    cerr_exit("Internal error: Malloc failed\n", 84);
  if (check_file(av[2]) == 0)
    cerr_exit("Error: 2nd argument is not a binary\n", 84);
  my_strcpy(str, "echo $PATH");
  my_path(str, av);
  free(str);
  create_tree_search(av, ac);
  return (0);
}

int	get_tree(char *av)
{
  char	*str;
  int	i;

  if ((str = malloc(my_strlen(av) + 12)) == NULL)
    cerr_exit("Internal error: Malloc failed\n", 84);
  strcpy(str, "tree -FS ");
  my_strcat(str, av);
  i = my_strlen(av) - 1;
  if (av[i] != '/')
    my_strcat(str, "/");
  my_tree(str);
  free(str);
  exit(PRO_OK);
}

int	main (int ac, char **av)
{
  if (ac == 2)
    check_file(av[1]) == 0 ? get_tree(av[1]) : cerr_exit(ERR_DIR, 84);
  else if (ac == 3 || ac == 4)
    check_file(av[1]) == 0 ? get_path(av, ac) : cerr_exit(ERR_DIR, 84);
  return (help());
}
