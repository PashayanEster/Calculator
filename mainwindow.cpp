#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
   // QVBoxLayout *vLayout = new QVBoxLayout(ui->centralwidget);
    QWidget *window = new QWidget(this);
   setCentralWidget(window);
    QVBoxLayout *vLayout = new
   QVBoxLayout(window);
    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);
    vLayout->addWidget(display);

    QGridLayout *gridLayout = new QGridLayout();
    vLayout->addLayout(gridLayout);

    QStringList buttons {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "C", "0", "=", "+"
    };
    int position = 0;
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QPushButton *button = new QPushButton(buttons[position]);
            gridLayout->addWidget(button, i, j);
            ++position;

            // connect(sender, signal, receiver, slot)
            connect(button, &QPushButton::clicked, this, &MainWindow::onPushButton);
        }
    }

    setFixedSize(300, 400);




}

void MainWindow::onPushButton() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button->text() == "C") {
        display->clear();
        return;
    }
    display->setText(display->text() + button->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}
