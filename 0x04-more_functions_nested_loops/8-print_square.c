void print_square(int size)
{
	int row, col;

	if (size <= 0)
	{
		_putchar('\n');
		break;
	}
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			_putchar(35);
		}
		_putchar('\n');
	}
}
