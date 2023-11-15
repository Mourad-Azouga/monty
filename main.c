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
    int counter = 0;/*We assume it's a stack at first*/
    char* buffer = NULL;
    size_t len = 0;
    for (counter = 1; getline(&buffer, &len, file) != -1; counter++)
    {
        printf("%s", buffer);
    }
    free(buffer);
}