/*
** tree.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 23 09:17:06 2016 David Munoz
** Last update Fri Jun 24 19:11:47 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

int	pars_file(char *tab)
{
  int   j;

  j = 0;
  while (tab[j])
    {
      if (tab[j] < 0 || tab[j] == ' ')
        {
          my_putchar('-');
          if (j % 4 == 0)
            print_coma(j);
        }
      else if (tab[j] != '\n' && tab[j] != '*')
        my_putchar(tab[j]);
      j++;
    }
  return (PRO_OK);
}

int	check_eof(char *ln)
{
  if (ln[0] == '\n')
    return (1);
  return (0);
}

int	get_file(FILE *output)
{
  char  *ln;
  size_t len;
  int   r;
  int	del;

  del = r = 0;
  ln = NULL;
  len = 0;
  while (getline(&ln, &len, output) != -1)
    {
      if (r == 0)
	if ((r = check_eof(ln)) == PRO_OK)
	  {
	    if (del != 0)
	      my_putchar('\n');
	    pars_file(ln);
	    del++;
	  }
    }
  my_putchar('\n');
  free(ln);
  return (PRO_OK);
}

int	my_tree(char *av)
{
  FILE  *output;

  if ((output = popen(av, "r")) == NULL)
    cerr_exit("Internal error: Popen failed\n", 84);
  get_file(output);
  if (pclose(output) != 0)
    cerr_exit("Could not run more or other error.\n", 84);
  return (0);
}
