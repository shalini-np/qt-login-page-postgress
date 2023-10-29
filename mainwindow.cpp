#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost:5432");
    db.setDatabaseName("qt_login_db");
    db.setUserName("postgres");
    db.setPassword("");

    if (db.open()) {
        QSqlQuery query;
        //query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
        query.prepare("SELECT * FROM qt-login.login-table WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (query.exec() && query.next())
        {
            qDebug() << "Login successful";
            QString message = "username: " + username + "\nPassword: " + password ;

            QMessageBox::information(this, "login Successful", message);


            // Handle successful login, e.g., open a new window
        } else {
            qDebug() << "Login failed:" << query.lastError().text();
            // Handle login failure, e.g., show an error message

            QString message = "username: " + username+ "\nPassword: " + password ;



            QMessageBox::warning (this, "Login", "Login failed!", message);
        }

        db.close();
    } else {
        qDebug() << "Failed to connect to the database:" << db.lastError().text();
        // Handle database connection failure, e.g., show an error message


        QString message = "username: " + username + "\nPassword: " + password ;



        QMessageBox::warning (this,"Login", "Failed to connect to the database!", message);
    }



}



void MainWindow::on_clear_clicked()
{
    ui->username->clear();
    ui->password->clear();
}

