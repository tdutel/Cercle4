/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:10:28 by llevasse          #+#    #+#             */
/*   Updated: 2023/09/18 23:11:58 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "ft_joinf/ft_joinf.h"
# include "gnl/get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char				*ft_strdup(char *src);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char *s1, char *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_str_nb_base(unsigned int nb, const char *base);
void				ft_str_revert(char *str);
char				*ft_strsep(char **p_str, const char *delim);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);

int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);

void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);

char				**ft_split(char const *s, char c);
char				**free_tab(char **tab, int index_word);
char				**alloc_tab(char const *s, char c);
char				*get_word(char const *s, char c, int i);
int					skip_char(const char *s, char c, int i);

int					ft_isspace(char c);
int					ft_atoi(const char *str);

unsigned long long	ft_atoi_ullong(const char *str);

void				ft_bzero(void *s, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

char				*ft_itoa(int n);
int					ft_isspace(char c);

char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_is_in_str(const char *str, char c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));

#endif
