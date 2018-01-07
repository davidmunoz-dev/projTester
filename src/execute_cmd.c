/*
** execute_cmd.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/projTester/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Jun 24 18:59:00 2016 David Munoz
** Last update Sat Jun 25 10:59:31 2016 David Munoz
*/

#include "utils.h"
#include "proj.h"

int	launch_cmd(char *line, char **av, int ac)
{
  FILE		*output;
  char		*cmd;
  char		*ln;
  size_t	len;

  len = 0;
  ln = NULL;
  if ((cmd = malloc(my_strlen(av[2]) + my_strlen(line) + 2)) == NULL)
    cerr_exit("Error: Malloc failed\n", 84);
  my_strcpy(cmd, av[2]);
  my_strcat(cmd, " ");
  my_strcat(cmd, line);
  if ((output = popen(cmd, "r")) == NULL)
    cerr_exit("Internal error: Popen failed\n", 84);
  while (getline(&ln, &len, output) != -1)
    fd_putstr(ln, av, ac);
  free(cmd);
  pclose(output);
  return (0);
}

int	get_info_files(char *str, char **av, FILE *fichier, int ac)
{
  char		*ln;
  char		*cmd;
  size_t	len;

  len = 0;
  ln = NULL;
  if ((cmd = malloc(BUFF_SIZE)) == NULL)
    cerr_exit("Error: Malloc failed\n", 84);
  str = epur_line(str);
  cmd[0] = 0;
  while (getline(&ln, &len, fichier) != -1)
    {
      if (my_strncmp(ln, "ARGS:", 5) == 0)
	my_strcat(cmd, ln);
      else if (my_strncmp(ln, "INPUT:", 6) == 0)
	{
	  my_strcat(cmd, str);
	  my_strcat(cmd, ln);
	}
    }
  cmd = my_epur_cmd(cmd);
  launch_cmd(cmd, av, ac);
  free(ln);
  return (PRO_OK);
}

int	open_files(char *str, char **av, int ac)
{
  FILE		*fichier;
  char		*path;

  path = strndup(str, my_strlen(str) - 1);
  if ((fichier = fopen(path, "r")) == NULL)
    cerr_exit("Error: Open failed\n", 84);
  fd_putstr(":  ", av, ac);
  get_info_files(str, av, fichier, ac);
  free(path);
  fclose(fichier);
  return (PRO_OK);
}

int	arg_lenght(char **av, char *str, int x, int ac)
{
  while (av[1][x] == str[x])
    x++;
  x++;
  if (check_tdf(x, str) == 1)
    fd_putchar('[', av, ac);
  return (x);
}

int	check_line(char *str, char **av, int ac)
{
  int	x;
  int	r;

  r = x = 0;
  if ((my_strstr(str, ".tdf") != NULL))
    {
      x = arg_lenght(av, str, x, ac);
      while (str[x] && r == 0)
        {
          if (str[x] == '/' && check_tdf(x, str) == 1)
            fd_putstr("] [", av, ac);
          else if (str[x] == '/' && check_tdf(x, str) == 0)
            fd_putstr("] ", av, ac);
          else if (str[x] == '.' && str[x+1] == 't'
                   && str[x+2] == 'd' && str[x+3] == 'f')
            {
              open_files(str, av, ac);
              x += 4;
            }
          else
            fd_putchar(str[x], av, ac);
          x++;
        }
    }
  return (PRO_OK);
}
