#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPushButton();


private:
    Ui::MainWindow *ui;

    QLineEdit *display;
};
#endif // MAINWINDOW_H
