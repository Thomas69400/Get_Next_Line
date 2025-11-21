#include "get_next_line.h"

void ft_memmove(char *dest, char *buf, size_t n)
{
    char *cop;

    if (!buf[0] || n == 0)
        return;
    cop = malloc(ft_len_to_n(&buf[ft_len_to_n(buf, 1)], 0));
    if (!cop)
        return;
    ft_bzero(cop, ft_len_to_n(&buf[ft_len_to_n(buf, 1)], 0));
    copy(cop, &buf[ft_len_to_n(buf, 1) + 1], 0);
    ft_bzero(buf, BUFFER_SIZE + 1);
    n--;
    while (n > 0)
    {
        dest[n] = cop[n];
        n--;
    }
    dest[n] = cop[n];
    free(cop);
}

char *get_complete_line(char *buf, int *bytes, int fd, int *trigger)
{
    char *s;

    s = NULL;
    while (!got_n(s) && (!*trigger && buf[0]))
    {
        if (!buf[0] && !is_end_of_file(*bytes, trigger))
            *bytes = read(fd, buf, BUFFER_SIZE);
        s = join(s, buf);
        if (ft_len_to_n(buf, 1) == ft_len_to_n(buf, 0))
        {
            ft_bzero(buf, BUFFER_SIZE + 1);
            *bytes = read(fd, buf, BUFFER_SIZE);
        }
        else
            ft_memmove(buf, &buf[ft_len_to_n(buf, 1)],
                       ft_len_to_n(&buf[ft_len_to_n(buf, 1)], 0));
    }
    return (s);
}

char *join(char *s, char *buf)
{
    char *ret;

    ret = malloc(ft_len_to_n(s, 0) + ft_len_to_n(buf, 1) + 2);
    if (!ret)
    {
        if (s)
            free(s);
        return (NULL);
    }
    ft_bzero(ret, ft_len_to_n(s, 0) + ft_len_to_n(buf, 1) + 1);
    if (s)
    {
        copy(ret, s, 1);
        free(s);
    }
    copy(&ret[ft_len_to_n(ret, 0)], buf, 1);
    return (ret);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int bytes = 0;
    char *s;
    static int trigger = 0;

    if (fd <= -1 || BUFFER_SIZE <= 0 || (trigger && !buf[0]))
    {
        bytes = 0;
        trigger = 0;
        return (NULL);
    }
    if (!buf[0])
    {
        ft_bzero(buf, BUFFER_SIZE + 1);
        bytes = read(fd, buf, BUFFER_SIZE);
    }
    s = get_complete_line(buf, &bytes, fd, &trigger);
    return (s);
}