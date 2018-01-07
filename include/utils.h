/*
** dante.h for  in /include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu May  5 12:32:55 2016 David Munoz
** Last update Fri Jun 24 22:36:39 2016 David Munoz
*/

#ifndef UTILS_H_
# define UTILS_H_

/*
** Include header files
*/
# define _BSD_SOURCE
# define _GNU_SOURCE
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include "my.h"

/*
** Color macro definition
*/
# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define PURPLE                 "\033[1;35m"
# define CYAN                   "\033[1;36m"
# define BROWN                  "\033[0;33m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define BLANK                  "\033[0m"

/*
** Error macro definition
*/
# define	ERROR			"Error "
# define	ERR_USAGE		"on usage\n"
# define	ERR_MALL		RED": Malloc failed\n"BLANK
# define	ERR_OPEN		RED": Open failed\n"BLANK
# define	ERR_FILE		RED": Wrong file\n"BLANK
# define	ERR_DIR			"Error : First argument is not a file\n"
# define	FILE_FORM		"Error: .tdf must begin with 'ARGS:' or 'INPUT:'\n"

/*
** Macro definition
*/
# define	PRO_OK		0
# define	PRO_ERR		-1
# define	BUFF_SIZE	4096

#endif /* UTILS_H_ ! */
