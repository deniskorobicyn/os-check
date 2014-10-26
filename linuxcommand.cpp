#include "linuxcommand.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <signal.h>

LinuxCommand::LinuxCommand(QString command) : p_command(command){}

int LinuxCommand::run(){

    int fork_id = vfork();
    int status = -1;
    if( fork_id == 0 ){
        prctl(PR_SET_PDEATHSIG, SIGHUP);
        exit(execl("/bin/sh","sh","-c", this->p_command.toStdString().c_str(), (char*) NULL));
    }
    else if( fork_id > 0 ){
        status = 0;
        this->synchronize();
    }
    else{
        status = -1;
    }
    return(status);
}

void LinuxCommand::synchronize(){
    while( 1 ){
        int child_status = 0;
        int dead_id = waitpid(-1, &child_status, WNOHANG);
        if( dead_id < 0  ) break;
        sleep(0.1);
    }
}

LinuxCommand::~LinuxCommand(){}
