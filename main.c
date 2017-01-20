#include <stdio.h>
#include "get_next_line.h"

static char     *ft_realloc(char *str1, char *str2)
{
    char    *new_string = (char *)malloc(ft_strlen(str1) * 2 + 1);

    if (new_string == NULL)
        return (NULL);
    ft_strcat(new_string, str1);
    ft_strcat(new_string, str2);
    free(str1);
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

static t_get    *check(t_get **current, const int fd)
{
    t_get *tmp;
    t_get *result;

    tmp = *current;
    if (tmp && tmp->fd == fd)
        return (tmp);
    while (tmp && (tmp = tmp->next) != *current)
        if (tmp->fd == fd)
            return (tmp);
    if ((result = (t_get *)(malloc(sizeof(t_get)))) == NULL)
        return (NULL);
    result->string = NULL;
    result->fd = fd;
    if (*current)
    {
        result->next = *current;
        tmp = *current;
        while (tmp->next != *current)
            tmp = tmp->next;
        tmp->next = result;
    }
    else
        result->next = result;
    return (result);
}

int				get_next_line(const int fd, char **line)
{
    static t_get	*ptr;
    int				i;

    if ((ptr = check(&ptr, fd)) == NULL || BUFF_SIZE <= 0 || fd < 0)
        return (READ_ERROR);
    if (ptr->string == NULL)
    {
        ptr->i = 0;
        if ((ptr->string = read_whole_file(fd)) == NULL)
            return (READ_ERROR);
        ptr->len = ft_strlen(ptr->string);
        i = -1;
        while (ptr->string[++i])
            if (ptr->string[i] == '\n')
                ptr->string[i] = '\0';
    }
    *line = ft_strdup(ptr->string + ptr->i);
    if (ptr->i >= ptr->len)
    {
		free(ptr);
        return (READ_COMPLETE);
    }
    ptr->i += 1 + ft_strlen(ptr->string + ptr->i);
    return (READ_SUCCESS);
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
    int fd = open("tmp", O_RDONLY);
    char *line;
    line = (char *)malloc(33);
    get_next_line(fd, &line);
    printf("%s---", line);
    get_next_line(fd, &line);
    printf("%s---", line);
    get_next_line(fd, &line);
    printf("%s---", line);
}