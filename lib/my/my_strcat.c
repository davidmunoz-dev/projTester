/*
** my_strcat.c for strcat in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:49:03 2015 munoz david
** Last update Wed Jun 22 14:54:05 2016 David Munoz
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
