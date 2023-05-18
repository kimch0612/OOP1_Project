#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMovie>
/*
프로그램이 GUI를 사용하는데 필요한 전처리기들
*/
#include <iostream>
#include <cstdlib> // 랜덤으로 단어를 뽑아내기 위한 난수 생성 관련 전처리기
#include <ctime> // 좀 더 다양한 난수를 생성하기 위한 전처리기
#include <string> // String문을 사용하기 위한 전처리기
#include <QTimer>

using namespace std;

/*

/// 변수 이름 설명 ///
rand_int : word_list에서 랜덤으로 단어를 뽑아내기 위한 난수를 저장할 변수
win : 단어 입력 성공 횟수를 저장할 변수
word_print : 랜덤으로 뽑아낸 단어를 저장할 string 타입의 변수
word_previous : 직전에 뽑힌 단어를 저장해뒀다가 추후 새로 뽑힌 단어와 중복되진 않는지 체크하는 용도로 사용되는 변수
wintext : 현재 몇승중인지 표시하기 위한 String을 저장하는 용도로 사용하는 변수
word_list : 단어들이 들어있는 리스트

*/

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
    "기대감", "도움말", "봄날", "미소", "아침", "날씨", "마음", "바람", "노래", "행운", "기분", "햇빛",
    "소리", "사람들", "힐링", "빛나는", "자유로운", "따뜻한", "기분 좋은", "새로운", "사랑스러운", "설레는",
    "아름다운", "순간", "작은", "예쁜", "기적", "기억되는", "용기 있는", "힘찬", "신나는", "편안한",
    "사랑하는", "기대하는", "들리는", "신비로운", "기대감", "꿈을", "꽃잎", "미소짓는", "아이들", "빛나는",
    "따뜻함", "스릴", "달콤한", "아름다움", "낭만", "즐거운", "설렘", "기대심", "행복한", "사랑스러움",
    "신선함", "달콤함", "사랑스러움", "아련한", "동화", "사랑받는", "설레는", "은은한", "맑은", "산뜻한",
    "신나는", "신선한", "미래", "웃음짓는", "아름답게", "믿을만한", "신뢰할", "즐거움을", "흥분", "포근한",
    "웃을", "설레는", "소중한", "상큼한", "감미로운", "재미있는", "사랑스러운", "설레는", "즐거워지는", "상쾌한",
    "달콤한", "활력", "따뜻함", "기대감을", "신뢰하고", "존경하는", "멋진", "활기찬", "기분 좋게", "설레는",
    "웃으며", "아름다운", "즐거운", "상큼한", "촉촉한", "맑은", "기쁨을", "웃음소리", "상쾌한", "감동적인"
    };

void word(){
    while (true){
        srand((unsigned int)time(NULL)); // 난수를 더 다양하게 생성하기 위해 현재의 시간을 불러와 난수를 생성하는데 사용함
        rand_int = rand() % 200; // 난수를 생성해주는데, 그 범위를 200까지로 한정함
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

MainWindow::MainWindow(QWidget *parent) // MainWindow Activity에서 사용되는 함수
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QMainWindow::setWindowFlags( Qt::WindowTitleHint |  Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint ); // 창 최대화 기능 비활성화
    ui->setupUi(this);
    /*
    맨 처음 실행시 나오는 GIF 애니메이션 재생
    */
    QMovie *Movie=new QMovie("C:/Users/Chals/Documents/OOP1_Project/img/main.gif");
    ui->main_image->setMovie(Movie);
    Movie->setScaledSize(QSize(240,240));
    Movie->start();
    word(); //  무작위 단어 생성
    QString qstr = QString::fromStdString(word_print); // 무작위로 생성한 단어가 String 타입이므로 GUI에서 사용 가능한 타입인 QString으로 캐스팅
    ui->word_title->setText(qstr); // 무작위로 생성한 단어를 word_title의 Text값으로 Setting
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

