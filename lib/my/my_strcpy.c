/*
** my_strcpy.c for Exercice 2 in /home/munoz_d/rendu/Piscine_C_J06/ex_02
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Oct  5 12:11:44 2015 munoz david
** Last update Wed Jun 22 18:43:26 2016 David Munoz
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
