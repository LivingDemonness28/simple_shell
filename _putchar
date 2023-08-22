/**
* _putchar – writes char c to standard output.
* @c: The char.
* Return: 1 (Success), -1 (Otherwise)
*/
int _putchar(char c)
{
	static int a;
	static char buffer[1024];
	
	if (c == -1 || a >= 1024)
	{
		write(1, buffer, a);
	}
	if (c != -1)
		buffer[a++] = c;
	return (1);
}
