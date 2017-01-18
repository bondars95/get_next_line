#include <stdio.h>
#include "get_next_line.h"

static char     *ft_realloc(char *str1, char *str2)
{
    char    *new_string = (char *)malloc(ft_strlen(str1) * 2 + 1);

    if (new_string == NULL)
        return (NULL);
    ft_strcat(new_string, str1);
    ft_strcat(new_string, str2);
    return new_string;
}

static char     *read_whole_file(const  int fd)
{
    char    *buff;
    char    *file;
    int     i;
    size_t byte;

    i = 0;
    if (!(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
        return (NULL);
    file = ft_memalloc(BUFF_SIZE);
    int capacity = BUFF_SIZE;
    while ((byte = (size_t) read(fd, buff, BUFF_SIZE)) > 0)
    {
        i = (int) (i + byte);
        buff[byte] = '\0';
        if (i > capacity && (capacity *= 2))
            file = ft_realloc(file, buff);
        else
            ft_strcat(file, buff);
        if (!file)
            return (NULL);
    }
    return ((byte < 0) ? (NULL) : (file));
}

static t_get    check(t_get **current, const int fd)
{
    t_get *tmp;
    while (tmp && tmp->next != (struct s_get *) current) {

    }
}

int		get_next_line(const int fd, char **line)
{
    static t_get	*ptr;

    // check if struct is already in list


}
int     main(int argc, char **argv) {
    // case sig_abbort
    /*char *src;
    char *new_string;
    char *new_string2;

    if (!(new_string = (char *)ft_memalloc(ft_strlen(src) * 2 + 1)))
        return (NULL);
    src = "hello_world";
    new_string = ft_realloc(src);
   // ft_memcpy(new_string, src, ft_strlen(src));
    printf("%s", new_string);*/

    //file open read all file
//    char *src = "hello world";
//    char    *new_string;
//
//    if (!(new_string = (char *)ft_memalloc(ft_strlen(src) * 2 + 1)))
//        return (NULL);
//    ft_memcpy(new_string, src, ft_strlen(src));
//    printf("%s", new_string);
    printf("%s", read_whole_file(0));
}