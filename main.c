#include "monty.h"
/**
 * main - the main program that'll run everything else
 * @argc: the number of arguments needs to be 2
 * @argv: argument holder
 * Return: Not decided yet
*/
int main(int argc, char* argv[])
{
    FILE* read;
    if (argc != 2){
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    /*Now we need to open the file in a read only manner*/
    read = fopen(argv[1],"r");
    if (!read){
        fprintf(stderr,"Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    read_file(read);
    fclose(read);
    return (0);
}
    /*Now we read the file using getline so that we can send it to be tokenized line by line then word by word*/
/**
 * read_file - Reads the file and calls strtok to tokenize and store the opcodes
 * @file: the file pointer
 * Return: not decided yet
*/
void read_file(FILE* file)
{
    int counter = 0, type = 0;/*We assume it's a stack at first*/
    char* buffer = NULL;
    size_t len = 0;
    for (counter = 1; getline(&buffer, &len, file) != -1; counter++)
    {
        tokenizer(buffer, type, counter);
    }
    free(buffer);
}
        /*After taking each line we need to tokenize the input so that we can get the opcode and the values*/
/**
 * tokenizer - separates the line word by word 
 * @line: the line
 * @type: initially 0 but this function will find out for sure
 * @count: the line number 
 * Return: it should return the type of the structure(stack or queue)
*/
int tokenize(char* line, int type, int count)
{
    char* opcode, value;

    opcode = strtok(line, "\n ");
    if (!opcode)
        return (type);
    value = strtok(NULL, "\n ");
    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);
    /*Ok now that we got the opcode and value as well as the type, we look for the function */
    func_search(opcode, value, count, type);
    return(type);
}
/**
 * func_search - searchs for the function by name and launchs the opcode's function
 * @opcode: the actual opcode
 * @value: the value that will be passed to the function
 * @count: the line count
 * @type: stack 0 or queue 1
 * Return: 1 if it works 0 if something wrong happens
*/
int func_search(char* opcode, char* value, int count, int type)
{
    int i, ptr;
    stack_t *stack = NULL;
    instruction_t function_list[] = {
                    {"push", push},
                    {"pall", pall},
		            {"pint", pint},
		            {"pop", pop},
		            {"nop", nop},

		           // {"swap", swap},
		            //{"add", add},
		            //{"sub", sub},
		            //{"div", div},
		            //{"mul", mul},

		           // {"mod", mod},
		           // {"pchar", pchar},
		           // {"pstr", pstr},
		           // {"rotl", rotl},
            	//	{"rotr", rotr},
		            {NULL, NULL},
    };
    if (opcode == "#")
        return (1);

        for (i = 0; function_list[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, function_list[i].opcode) == 0)
        {
            function_list[i].f(&stack, count); // Assuming the functions take two arguments (value is NULL here)
            return (1);
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
    exit(EXIT_FAILURE);
}