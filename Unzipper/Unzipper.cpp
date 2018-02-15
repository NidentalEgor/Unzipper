#include <ZipFile.h>

#include "Unzipper.h"

void Unzipper::Run(
    const QString& path_to_zip_file,
    const QString& work_directory,
    const QString& password)
{
    ZipArchive::Ptr archive = ZipFile::Open(path_to_zip_file.toStdString());
    for (size_t i = 0; i < archive->GetEntriesCount(); ++i)
    {
        QString entry_name(archive->GetEntry(i)->GetName().c_str());

        emit FileExtractingStarted(entry_name);

        ZipFile::ExtractEncryptedFile(
            path_to_zip_file.toStdString(),
            entry_name.toStdString(),
            QDir(work_directory).filePath(entry_name).toStdString(),
            password.toStdString());
    }

    emit ArchiveExtractingFinished(QDir(work_directory).filePath("game.exe"));
}

#include "Unzipper.moc"
