// command.c
#include <stdio.h>
#include <stdlib.h>
#include "command.h"
Command readCommand() {
   Command command;
   // Implement the logic to read and parse the command from the user
   // You can use scanf or fgets to read user input, and then parse it accordingly
   return command;
}
void executeCommand(Canvas canvas, Command command) {
   // Implement the logic to execute the command on the canvas
   // Depending on the command type, perform the corresponding action on the canvas
   switch (command.type) {
       case write:
           // Implement write command logic
           break;
       case erase:
           // Implement erase command logic
           break;
       case resize:
           // Implement resize command logic
           break;
       case add:
           // Implement add command logic
           break;
       case delete:
           // Implement delete command logic
           break;
       case save:
           // Implement save command logic
           break;
       case load:
           // Implement load command logic
           break;
       case quit:
           // Implement quit command logic
           break;
       case help:
           // Implement help command logic
           break;
       default:
           printf("Invalid command type\n");
           break;
   }
}