#ifndef LINUXCOMMAND_H
#define LINUXCOMMAND_H
#include <QString>
class LinuxCommand
{
    QString p_command;
public:
    LinuxCommand(QString);
    ~LinuxCommand();

    int run();
private:
    void synchronize();
};

#endif // LINUXCOMMAND_H
