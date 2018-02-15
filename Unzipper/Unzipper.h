#ifndef UNZIPPER_H_INCLUDED
#define UNZIPPER_H_INCLUDED
#pragma once

#include <QtWidgets>

class Unzipper : public QObject
{
    Q_OBJECT

signals:
    void FileExtractingStarted(const QString& file_name);
    void ArchiveExtractingFinished(const QString& path_to_executable);

public:
    void Run(
        const QString& path_to_zip_file,
        const QString& work_directory,
        const QString& password);
};

#endif // UNZIPPER_H_INCLUDED