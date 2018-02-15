#include <QCommandLineParser>
#include <QDirIterator>

#include "ZipFile.h"

void AddEncryptedFilesToArchive(
    const QString& directory,
    const QString& password,
    const QString& archive_name)
{
    QDirIterator it(directory, QDir::Files);
    while (it.hasNext())
    {
        it.next();
        ZipFile::AddEncryptedFile(
            archive_name.isEmpty() ? "archive.zip" : archive_name.toStdString(),
            it.filePath().toStdString(),
            it.fileName().toStdString(),
            password.toStdString());
    }
}

void AddFilesToArchive(const QString& directory, const QString& archive_name)
{
    QDirIterator it(directory, QDir::Files);
    while (it.hasNext())
    {
        it.next();
        ZipFile::AddFile(
            archive_name.isEmpty() ? "archive.zip" : archive_name.toStdString(),
            it.filePath().toStdString());
    }
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Zipper");
    QCoreApplication::setApplicationVersion("Version: 1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Application to zipping with password.");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption directory_option(
        {"d", "directory"},
        QCoreApplication::
            translate("main", "Path to directory containing files for zipping."),
        QCoreApplication::translate("main", "directory"));

    QCommandLineOption password_option(
        {"p", "password"},
        QCoreApplication::translate("main", "Password of zip archive."),
        QCoreApplication::translate("main", "password"));

    QCommandLineOption archive_name_option(
        {"n", "archive-name"},
        QCoreApplication::translate("main", "Name of zip archive."),
        QCoreApplication::translate("main", "name"));

    parser.addOption(directory_option);
    parser.addOption(password_option);
    parser.addOption(archive_name_option);

    parser.process(app);

    const QStringList args = parser.optionNames();
    if (args.size() < 1)
    {
        fprintf(
            stderr,
            "%s\n",
            qPrintable(
                QCoreApplication::
                    translate("main", "Error: Must specify an arguments.")));
        parser.showHelp(1);
    }

    QString directory = parser.value(directory_option);
    if (!QDir(directory).exists())
    {
        fprintf(
            stderr,
            "%s\n",
            qPrintable(QCoreApplication::
                           translate("main", "Directory does not exist!")));
        parser.showHelp(1);
    }

    QString password = parser.value(password_option);
    QString archive_name = parser.value(archive_name_option);

    if (!password.isEmpty())
    {
        AddEncryptedFilesToArchive(directory, password, archive_name);
    }
    else
    {
        AddFilesToArchive(directory, archive_name);
    }

    return 0;
}