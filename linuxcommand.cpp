#include "linuxcommand.h"
#include <unistd.h>
#include <stdio.h>
#define LENGTH 256 //ToDo maybe move it to class options?

LinuxCommand::LinuxCommand(QString command) : p_command(command){}

QString LinuxCommand::run() {
    FILE* pipe = popen(this->p_command.toStdString().c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[LENGTH];
    QString result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, LENGTH, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

LinuxCommand::~LinuxCommand(){}
