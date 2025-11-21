#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
void ft_bzero(char *s, size_t n);
void ft_memmove(char *dest, char *buf, size_t n);
void copy(char *dest, char *src, int to_n);
size_t ft_len_to_n(char *s, int find_n);
char *get_complete_line(char *buf, int *bytes, int fd, int *trigger);
int got_n(char *s);
char *join(char *s, char *buf);
int is_end_of_file(int bytes, int *trigger);

#endif