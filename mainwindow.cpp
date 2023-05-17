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
    "발전", "변화", "기대", "영감", "미래", "추억", "설레임", "신뢰", "아름다움", "힘내다",
    "숨결", "오후", "햇살", "공동", "감정", "소원", "정원", "소금", "정상", "예측",
    "인생", "눈물", "춤추다", "향기", "목소리", "약속", "설명", "소망", "어깨", "아침",
    "시간", "의지", "이야기", "삶의", "사랑해", "고민", "달리다", "선물", "눈동자", "가슴",
    "표정", "자연", "목표", "자세", "변신", "피로", "영화", "허락", "소리", "유념",
    "이해", "만남", "웃음꽃", "참여", "기억", "세상", "다가가다", "의미", "웃기다", "충고",
    "기대감", "도움말"
    };

void word(){
    while (true){
        srand((unsigned int)time(NULL));
        rand_int = rand() % 100;
        word_print = word_list[rand_int];
        /*
        제시어가 직전에 주워진 것과 지금의 것이 같은지 확인하고
        같지 않다면 새로 생성할 필요가 없으므로 while문을 break,
        같다면 다시 단어가 생성되게끔 Continue 해준다.
        */
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

