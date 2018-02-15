#ifndef MAIN_WINDOW_H_INCLUDED
#define MAIN_WINDOW_H_INCLUDED
#pragma once

#include <qpushbutton.h>
#include <qtextedit.h>
#include <QDialog>
#include <QLayout>

#include "ExecutableLauncher.h"

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();

signals:
    void LaunchButtonPushed();

public slots:
    void OnNewMessageToDisplay(const QString& message);
    void OnExtractingFinished(const QString& path_to_executable);
    void OnExecutableLaunched();

private:
    QVBoxLayout*       layout_;
    QTextEdit*         extracting_log_;
    QPushButton*       launch_button_;
    QString            path_to_executable_;
    ExecutableLauncher executable_launcher_;
};

#endif // MAIN_WINDOW_H_INCLUDED