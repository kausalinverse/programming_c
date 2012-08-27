/**
 *
 *das ist mein Hello world template 
 *veroeffentlicht unter der GNU Lizens
 *
 *
 */

#include <stdlib.h> /* EXIT_ * */
#include <stdio.h>

// funtion declarations of mainframe
// that let the shell speak with you
void help(unsigned char *input_line);
void addToDispacher(unsigned char input, void (*handler)(unsigned char *input_line));
void commandNotRecognized(unsigned char *command_line);
void dispatch(unsigned char *input_line);
int readLine(unsigned char *str, unsigned max_lenght); 
void (*handler_[256])(unsigned char *input_line);

void quite();
void run();

// --- special funtion declarations so extras
//
void showList(unsigned char *input_line);



#define MAX_LINE_LENGTH 512
#define ILLEGAL_ARGUMENTS -1
#define FALSE 0
#define TRUE 1

// ------------------------------------------
main() 
 {
     
       addToDispacher('h', help);
       addToDispacher('s', showList); 
       addToDispacher('q', quite);
 run();
 return(0);
 };

//-------------------------------------------

void run()
{
    unsigned char *input_line = malloc(sizeof(unsigned char)*(MAX_LINE_LENGTH+1));

    int chars_read = 0;
    
    for(;;)
    {
        printf("my_shell> ");
        if((chars_read = readLine(input_line,MAX_LINE_LENGTH) == ILLEGAL_ARGUMENTS ))
        {
            printf("Error: readLine returned ILLEGAL_ARGUMENTS\n");
            exit(-1);
        }
        dispatch(input_line);
    }
}

// -----------------------------------------

void addToDispacher(unsigned char input, void (*handler) (unsigned char *input_line))
{
    handler_[input] = handler;
}

// -----------------------------------------

void dispatch(unsigned char *input_line)
{
    if (handler_[*input_line] != NULL)
        handler_[*input_line](input_line);
    else
        commandNotRecognized(input_line);
}

// ---------------------------------------

int readLine(unsigned char *str, unsigned max_lenght)
{
    unsigned char character_read = '\0';
    unsigned num_chars = 0;

    if ((max_lenght <= 1) || (str == NULL))
        return(ILLEGAL_ARGUMENTS);
    
    while((character_read = getchar()) != '\n')
    {
        *str++= character_read;
        if(++num_chars >= max_lenght)
            break;
    }
    *str = '\0';
    return(num_chars);
}

// ----------------------------------------

void commandNotRecognized(unsigned char *command_line)
{
   
    printf("Error: command not recognized... %s\n", command_line);
}

// --------------------------------------

void help(unsigned char *input_line)
{
    printf("\n \
  List of the Commands \n \
  -------------------- \n \
  h   show this help \n \
  s   show list \n \
  q   quite this programm \n ");
}


// ---------------------------------------
// the start of some real special funktion of my
// programm



void showList(unsigned char *input_line)
{
    
    printf("hier steht dann die Liste, wenn ich weis wie. \n");
}

// --------------------------------------


void quite(unsigned char *input_line)
{
    exit(0);
}
