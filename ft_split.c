#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

static int	m_alloc(char **tab, int position, size_t size)
{
	tab[position] = malloc(size);
	if (tab[position] == NULL)
	{
		while (0 < position)
			free(tab[--position]);
		return (1);
	}
	return (0);
}

static int	filla(char **tab, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (*s)
	{
		if (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (m_alloc(tab, i, len + 1))
				return (1);
			ft_strlcpy(tab[i], s - len, len + 1);
			len = 0;
			i++;
		}
	}
	return (0);
}

static size_t	count_words(const char *str, char delimeter)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimeter)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != delimeter)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	counts;
	char	**tab;

	if (!s)
		return (NULL);
	counts = count_words(s, c);
	tab = malloc((counts + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[counts] = NULL;
	if (filla(tab, s, c))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

