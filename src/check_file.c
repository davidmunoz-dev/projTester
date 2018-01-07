/*
** check_file.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 22 19:06:03 2016 David Munoz
** Last update Fri Jun 24 19:34:08 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

int	check_file(char *av)
{
  struct stat	sb;
  int		fd;

  fd = stat(av, &sb);
  if (fd == PRO_OK)
    {
      if (S_ISDIR(sb.st_mode))
	return (PRO_OK);
    }
  return (PRO_ERR);
}
