
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "command.h"

int main() {
    Canvas canvas = createCanvas(10, 10);

    Command command;
    while ((command = readCommand()) != quit) {
        executeCommand(canvas, command);
    }

    destroyCanvas(canvas);
    return 0;
}