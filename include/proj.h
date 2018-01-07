/*
** palindrome.h for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/palindrome
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun 16 09:11:31 2016 David Munoz
** Last update Fri Jun 24 23:02:47 2016 David Munoz
*/

#ifndef PROJ_H_
# define PROJ_H_

/*
** utils
*/
void    *cerr_msg_exit(char *log, int status);
int     cerr_exit(char *log, int status);
int     my_len_tab(char *str);
void	free_tab(char **tab);
void    print_coma(int j);
char	*my_epur_cmd(char *str);
char	*epur_line(char *str);

/*
** tree
*/
int	my_tree(char *av);

/*
** path
*/
int	my_path(char *str, char **av);

/*
** check_file
*/
int     check_file(char *av);

/*
** get lines tree
*/
int     check_tdf(int x, char *str);
int	create_tree_search(char **av, int ac);

/*
** execute cmd
*/
int	check_line(char *str, char **av, int ac);

/*
** print
*/
void	fd_putstr(char *str, char **av, int ac);
void	fd_putchar(char c, char **av, int ac);

#endif /* PROJ_H_ ! */
