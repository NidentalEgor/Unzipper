#include <qapplication.h>
#include <QObject>
#include <QString>
#include <QtConcurrent/QtConcurrentRun>


#include "MainWindow.h"
#include "Unzipper.h"

QString GetRandomString(const size_t random_string_length)
{
    const static QString possible_characters(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString random_string(random_string_length, 'A');
    for (auto& symbol : random_string)
    {
        const int index = qrand() % possible_characters.length();
        symbol = possible_characters.at(index);
    }
    return random_string;
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow   main_window;

    const QString temp_directory_full_path(
        QDir::temp().filePath(GetRandomString(8)));
    if (QDir(temp_directory_full_path).exists())
    {
        QDir().rmdir(temp_directory_full_path);
    }
    QDir().mkdir(temp_directory_full_path);
    const QString path_to_extracted_file =
        QDir(temp_directory_full_path).filePath("extracted_archive.zip");

    QFile::copy(":/archive.zip", path_to_extracted_file);

    main_window.show();

    Unzipper unzipper;

    QObject::
        connect(&unzipper, &Unzipper::FileExtractingStarted, &main_window, &MainWindow::OnNewMessageToDisplay);
    QObject::
        connect(&unzipper, &Unzipper::ArchiveExtractingFinished, &main_window, &MainWindow::OnExtractingFinished);

    QString password("12345");
    QtConcurrent::
        run(&unzipper,
            &Unzipper::Run,
            path_to_extracted_file,
            temp_directory_full_path,
            password);

    return app.exec();
}
