#ifndef LINUXCOMMAND_H
#define LINUXCOMMAND_H
#include <QString>
class LinuxCommand
{
    QString p_command;
public:
    LinuxCommand(QString);
    ~LinuxCommand();

    QString run();
};

#endif // LINUXCOMMAND_H
