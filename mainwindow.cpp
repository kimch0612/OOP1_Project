#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMovie>
#include <iostream>
#include <cstdlib> // 랜덤으로 단어를 뽑아내기 위한 난수 생성 관련 전처리기
#include <ctime> // 좀 더 다양한 난수를 생성하기 위한 전처리기
#include <string> // String문을 사용하기 위한 전처리기
#include <windows.h> // Sleep()문을 사용하기 위한 전처리기

using namespace std;

int rand_int, win = 0;
string word_print, word_previous, wintext;
string word_list[] = {
    "물건", "사람", "집중", "즐거움", "행복", "사랑", "음식", "꿈꾸다", "공부", "건강",
    "웃음", "도전", "성공", "생각", "친구", "가족", "여행", "자유", "도움", "열정",
    "희망", "기다림", "도움", "긍정", "기쁨", "용기", "믿음", "존중", "자신", "소중",
    "자리", "여유", "느낌", "협력", "경험", "창조", "성장", "소통", "환경", "행동",
    "발전", "변화", "기대", "영감", "미래", "추억", "설레임", "신뢰", "아름다움", "힘내다"
    };

void word(){
    while (true){
        srand((unsigned int)time(NULL));
        rand_int = rand() % 50;
        word_print = word_list[rand_int];

        if (word_previous == word_print) continue;
        else {
            word_previous = word_print;
            break;
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/main.gif");
    ui->main_image->setMovie(Movie);
    Movie->setScaledSize(QSize(240,240));
    Movie->start();
    word();
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
        Movie->setScaledSize(QSize(240,240));
        Movie->start();
        win = 0;
    }
    else {
        win++;
        string win_str = to_string(win);
        wintext = "성공했습니다! 현재 " + win_str + "연속 성공중입니다.";
        QString wintext_qstr = QString::fromStdString(wintext);
        ui->word_tf->setText(wintext_qstr);
        QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/success.gif");
        ui->main_image->setMovie(Movie);
        Movie->setScaledSize(QSize(240,240));
        Movie->start();
    }
    ui->word_input->setText("");
    word();
    QString qstr = QString::fromStdString(word_print);
    ui->word_title->setText(qstr);
}

