#include <stdlib.h>

int is_sep(char c, char *sep)
{
    int i;

    i = 0;
    while (sep[i])
    {
        if (c == sep[i])
            return (1);
        i++;
    }
    return (0);
}

int count_words(char *str, char sep)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && str[i] == sep)
            i++;
        if (str[i] && str[i] != sep)
        {
            count++;
            while (str[i] && str[i] != sep)
                i++;
        }
    }
    return (count);
}

char *world_splitter(char *str, char sep)
{
    int len;
    char *word;
    int i;

    len = 0;
    while (str[len] && str[len] != sep)
        len++;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str, char *charset)
{
	int i;
    int j;
    char **result;

    result = (char **)malloc(sizeof(char *) * (count_words(str, charset[0]) + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        if (str[i] && !is_sep(str[i], charset))
        {
            result[j] = world_splitter(&str[i], charset[0]);
            j++;
            while (str[i] && !is_sep(str[i], charset))
                i++;
        }
        else
            i++;
    }
    result[j] = NULL;
	return (result);
}
