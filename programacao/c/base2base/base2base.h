int pow(int base, int power)
{
	int output = 1;
	for(; power != 0; power--)
	{
		output = output * base;
	}
	return output;
}

int char_to_int(char input)
{
	if((input >= '0') && (input <= '9'))
	{
		return (input - '0');
	}

	else if((input >= 'a') && (input <= 'z'))
	{
		return (input - 'a' + 10);
	}

	else if((input >= 'A') && (input <= 'Z'))
	{
		return (input - 'A' + 10);
	}
}

char int_to_char(int input)
{
	if((input >= 0) && (input <= 9))
	{
		return ('0' + input);
	}

	else if((input >= 10) && (input <= 35))
	{
		return ('a' + input - 10);
	}

	else if((input >= 36) && (input <= 61))
	{
		return ('A' + input - 36);
	}
}

int decode(char *input, int base)
{
	int i, length, quantity = 0;
	for(length = 0; *(input + length) != '\0'; length++);
	for(i = 0; i < length; i++)
	{
		quantity = quantity + (pow(base, length - i - 1) * char_to_int(*(input + i)));
	}
	
	return quantity;
}

void encode(int quantity, int base, char *output)
{
	int max_position, position, value;
	for(max_position = 0; pow(base, max_position) - 1 < quantity; max_position++);
	for(position = max_position; position > 0; position--)
	{
		for(value = base - 1;(quantity - (value * (pow(base, position - 1)))) < 0;value--);
		quantity = (quantity - (value * (pow(base, position - 1))));
		*(output + (max_position - position)) = int_to_char(value);
	}
}
