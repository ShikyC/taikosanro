#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class NoteChart;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void showEvent(QShowEvent *event);
private:
    Ui::MainWindow *ui;
    NoteChart *chart_;
    QElapsedTimer fpsTimer_;
    int fpsCount_;
};

#endif // MAINWINDOW_H
