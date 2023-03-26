/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:08:41 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 16:30:30 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

// PARTIE I

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
int			ft_atoi(const char *str);
char		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(char *str);

// PARTIE II

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// BONUS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *n);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *n);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PERSO

char	*ft_uitoa(intmax_t n, int base);
char	*ft_strtoupper(char *str);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strnew(size_t size);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strncat(char *dst, const char *src, size_t len);
char	*ft_strmap(char const *s, char (*f)(char));
void	ft_strdel(char **as);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strclr(char *s);
char	*ft_strcat(char *dst, const char *src);
int		ft_min(int a, int b);
void	**ft_memfree(void **ar, int size);
void	ft_memdel(void **ap);
int		ft_max(int a, int b);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
int		ft_get_ptrsize(intptr_t n, intptr_t *pow, int base);
void	ft_free(void **ar, int size);
int		ft_arlen(char **ar);
void	*ft_realloc(void *source, size_t old_size, size_t new_size);
int		ft_abs(int n);
int		ft_strdigit(char *str);

// GET NEXT LINE

char	*ft_strjoins(char *s1, char *s2, size_t len);
char	*get_next_line(int fd);

#endif
