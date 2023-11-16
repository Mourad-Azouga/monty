#include "monty.h"
stack_t *head = NULL;
/**
 * main - the main program that'll run everything else
 * @argc: the number of arguments needs to be 2
 * @argv: argument holder
 * Return: Not decided yet
 */
int main(int argc, char *argv[])
{
	FILE *read;

	if (argc != 2)
    {
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*Now we need to open the file in a read only manner*/
	read = fopen(argv[1], "r");
	if (!read)
    {
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(read);
	free_node();
	fclose(read);
	return (0);
}
/**
 * Now we read the file using getline so that we can send it to be
 * tokenized line by line then word by word
 */
/**
 * read_file - Reads the file and calls strtok to tokenize and stores
 * @file: the file pointer
 * Return: not decided yet
 */
void read_file(FILE *file)
{
	int counter = 0, type = 0;/*We assume it's a stack at first*/
	char *buffer = NULL;
	size_t len = 0;
	for (counter = 1; getline(&buffer, &len, file) != -1; counter++)
	{
		tokenizer(buffer, type, counter);
	}
	free(buffer);
}
/**
 * After taking each line we need to tokenize the input
 * so that we can get the opcode and the values
 */
/**
 * tokenizer - separates the line word by word
 * @line: the line
 * @type: initially 0 but this function will find out for sure
 * @count: the line number
 * Return: it should return the type of the structure(stack or queue)
 */
int tokenizer(char *line, int type, int count)
{
	char *opcode, *value;

	opcode = strtok(line, "\n ");
	if (!opcode)
		return (type);
	value = strtok(NULL, "\n ");
	if (strcmp(opcode, "stack") == 0)
    {
		type = 0;
		return (type);
	}
	if (strcmp(opcode, "queue") == 0)
    {
		type = 1;
		return (type);
	}

	/**Ok now that we got the opcode and value as well
     *  as the type, we look for the function */
	func_search(opcode, value, count, type);
	return(type);
}
/**
 * func_search - searchs for the function by name and
 * launchs the opcode's function
 * @opcode: the actual opcode
 * @value: the value that will be passed to the function push
 * to be stored in the list
 * @count: the line count
 * @type: stack 0 or queue 1
 * Return: 1 if it works 0 if something wrong happens
 */
int func_search(char *opcode, char *value, int count, int type)
{
	int i;
	instruction_t function_list[] =
    {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
        {"swap", swap},
		{"add", add},
		  {"sub", sub},
		  {"div", divi},
		  {"mul", muli},
		  {"mod", modus},
		  {"pchar", pchar},
		  {"pstr", pstr},
		  {"rotl", rotl},
		  {"rotr", rotr},
		{NULL, NULL},
	};
	if (strcmp(opcode, "#") == 0)
	{
		free_node();
		return (0);
	}
		
	for (i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			magic(function_list[i].f, opcode, value, type, count);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	exit(EXIT_FAILURE);
}
/**
 * magic - Works the magic and make stuff happen(Calls the functions)
 * @funk: the function name
 * @opcode: opcode that we'll use the recheck, seems dumb ik but it's a test
 * @value: the value that will be passed to stack_t->n
 * @type: 1 stack 0 queue for pushing purposes
 * @line_n: line number
 */
/**
 * Why did we add push here if we were to make it
 * work via the func_search? Good question,
 * It's because in the .h file we see that we can only
 * have as input stack and the line number
 * but push needs more than that as it is the most important function
 * it needs the type, is
 * it a stack or a queue?? haa, so we'll need to make 2
 * different functions
 */
void magic(op_func funky, char *opcode, char *value, int type, int line_n)
{
	int sign = 1, i;
	stack_t* hamood;
	if (strcmp(opcode, "push") == 0)
    {
		if (value && value[0] == '-')
        {
			sign = -1;
			value = value + 1; /*To remove the - character*/
		}
		if (!value)
        {
			fprintf(stderr, "L%d: usage: push integer", line_n);
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
        {
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer", line_n);
				exit(EXIT_FAILURE);
			}
		}
		hamood = create_new_node(atoi(value), sign);
		if (type == 1)/*queue*/
			add_queue(&hamood, line_n);
		if (type == 0)/*stack*/
			funky(&hamood, line_n);
	}
	else
	{
		funky(&head, line_n);
	}
}
