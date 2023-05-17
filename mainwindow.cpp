#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMovie>
#include <iostream>
#include <cstdlib> // 랜덤으로 단어를 뽑아내기 위한 난수 생성 관련 전처리기
#include <ctime> // 좀 더 다양한 난수를 생성하기 위한 전처리기
#include <string> // String문을 사용하기 위한 전처리기
#include <windows.h> // Sleep()문을 사용하기 위한 전처리기

using namespace std;

int rand_int;
std::string word_print;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/main.gif");
    ui->main_image->setMovie(Movie);
    Movie->start();
    srand((unsigned int)time(NULL));
    rand_int = rand() % 10;
    string word_list[10] = {"아", "집가고싶다", "진짜루다가", "ㄹㅇ;;", "1", "2" , "3" , "4" , "5" , "6"};
    word_print = word_list[rand_int];
    QString qstr = QString::fromStdString(word_print);
    ui->word_title->setText(qstr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enter_clicked()
{
    QString word_input = ui->word_input->toPlainText();
    std::string word_input_str = word_input.toStdString();
    if (word_input_str != word_print) {
        ui->word_tf->setText("틀렸습니다!");
        QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/failed.gif");
        ui->main_image->setMovie(Movie);
        Movie->start();
    }
    else {
        ui->word_tf->setText("성공했습니다!");
        QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/success.gif");
        ui->main_image->setMovie(Movie);
        Movie->start();
    }
}

