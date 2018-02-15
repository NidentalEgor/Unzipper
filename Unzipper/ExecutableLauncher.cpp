#include <qprocess.h>

#include "ExecutableLauncher.h"

void ExecutableLauncher::LaunchExecutable(
    const QString& full_path_to_executable)
{
    QProcess process;
    process.startDetached(full_path_to_executable);

    emit ExecutableLaunched();
}
