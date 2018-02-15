#ifndef EXECUTABLE_LAUNCHER_H_INCLUDED
#define EXECUTABLE_LAUNCHER_H_INCLUDED
#pragma once

#include <QObject>
#include <QString>

class ExecutableLauncher : public QObject
{
    Q_OBJECT

signals:
    void ExecutableLaunched();

public:
    void LaunchExecutable(const QString& full_path_to_executable);
};

#endif // EXECUTABLE_LAUNCHER_H_INCLUDED
