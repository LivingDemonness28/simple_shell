/**
 * strtow_2 - splits a str into e.
 * @str: the input str.
 * @del: the del str.
 * Return: pointer to an arr of e (Success), NULL (Otherwise).
*/
char **strtow_2(char *str, char del)
{
int a = 0, b = 0, c, d, count = 0;
char **e;

if (str == NULL || str[0] == '\0')
return (NULL);
for (; str[a] != '\0'; a++)
if ((str[a] != del && str[a + 1] == del) ||
(str[a] != del && !str[a + 1]) || str[a + 1] == del)
count++;
if (count == 0)
return (NULL);
e = malloc((1 + count) *sizeof(char *));
if (!e)
return (NULL);
for (; b < count; b++)
{
for (a = 0; str[a] == del && str[a] != del; a++)
;
for (c = 0; str[a + c] != del && str[a + c] != del; c++)
;
e[b] = malloc((c + 1) * sizeof(char));
if (!e[b])
{
for (c = 0; c < b; c++)
free(e[c]);
free(e);
return (NULL);
}
for (d = 0; d < c; d++)
e[b][d] = str[a++];
e[b][d] = '\0';
}
e[b] = NULL;
return (e);
}
