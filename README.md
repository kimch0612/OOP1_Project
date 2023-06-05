# OOP1 Team Project

## 개발 환경
| Type | Content |
|:---|:---|
| OS | Windows 11 22H2 22621.1702 |
| Architecture | amd64 |
| Compiler | MinGW 11.2.0 64-Bit for C++ |
| IDE | Desktop Qt 6.5.0 MinGW 64-Bit & Code-Server (VSC) |

## 폴더 구조

    .
    ├── .gitignore                   # Git Repository에 추가되지 말아야 할 리스트가 담긴 파일입니다.
    ├── CMakeLists                   # 빌드환경을 위한 빌드 파일을 생성하는 유틸리티입니다.
    ├── CMakeLists.txt.user          # 위와 동일합니다.
    ├── main.cpp                     # 이 프로그램의 메인 C++ 파일로, GUI를 불러오는 역할을 합니다.
    ├── mainwindow.cpp               # 이 프로그램의 주 C++ 파일로, 프로그램의 구성 및 동작에 필요한 코드가 여기에 있습니다.
    ├── mainwindow.h                 # 이 프로그램에서 사용된 함수나 기타 기능들이 정의돼있습니다.
    ├── mainwindow.ui                # 이 프로그램의 GUI 관련 코드가 이곳에 있습니다.
    ├── resources.qrc                # 파일 동작에 필요한 img가 정의되어 있는 파일입니다.
    └── README.md                    # 마크다운 문법으로 작성된 프로그램의 소개 페이지입니다.

## 애플리케이션 구조
![슬라이드1](https://github.com/kimch0612/OOP1_Project/assets/10193967/91567dc3-23b2-4646-a730-887b96139d44)
#### 5초 내외로 주어진 제시어를 제시어 입력란에 입력 후 엔터키를 클릭합니다.<br>그러면 주어진 제시어가 바뀌며 제한시간이 초기화됩니다.<br>성공할 때마다 제한시간이 0.15초씩 감소하며 실패시 5초로 초기화됩니다.<br> 

## 빌드 및 실행 방법
- CMakeLists.txt 파일을 Qt Creator IDE로 실행합니다.
- 디버깅 모드로 빌드 및 실행합니다.

## P.S.
- 저작권 이슈로 img 폴더는 업로드하지 않았습니다.
