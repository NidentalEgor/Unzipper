#include <QtConcurrent/qtconcurrentrun.h>

#include "MainWindow.h"

MainWindow::MainWindow()
    : layout_(new QVBoxLayout(this)),
      extracting_log_(new QTextEdit(this)),
      launch_button_(new QPushButton("&Launch game!", this)),
      path_to_executable_(),
      executable_launcher_()
{
    extracting_log_->setReadOnly(true);

    layout_->addWidget(extracting_log_);
    launch_button_->setEnabled(false);
    layout_->addWidget(launch_button_);
    setLayout(layout_);

    connect(launch_button_, &QPushButton::clicked, [=]() {
        launch_button_->setEnabled(false);
        QtConcurrent::
            run(&executable_launcher_,
                &ExecutableLauncher::LaunchExecutable,
                path_to_executable_);
    });

    connect(&executable_launcher_, &ExecutableLauncher::ExecutableLaunched, this, &MainWindow::OnExecutableLaunched);
}

void MainWindow::OnNewMessageToDisplay(const QString& message)
{
    extracting_log_->append(message);
}

void MainWindow::OnExtractingFinished(const QString& path_to_executable)
{
    path_to_executable_ = path_to_executable;
    launch_button_->setEnabled(true);
}

void MainWindow::OnExecutableLaunched()
{
    close();
}

#include "MainWindow.moc"
