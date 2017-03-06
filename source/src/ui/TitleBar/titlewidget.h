/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---��������ʵ��
**************************************************/
#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

class PushButton;
class QLabel;
class QHBoxLayout;
class SearchLineEdit;
class MyMenu;
class RemoteWidget;

typedef enum TbnStatus{
    BtnMax = 0,
    BtnMin
}TBNSTATUS;

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

    void Translator();

Q_SIGNALS:
    void signalClose();
    void signalHideWidget();
    void signalMax();
    void signalMix();
    void signalShowSkin();

    //ת��ң�����ź�
    void signalShowOrHideWidget(int);

private Q_SLOTS:
    void slotChangeBtnStatus(int status);
    void slotOpenOrHideRemote();
    void slotHideRemote();

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QLabel *m_labelIcon;

    PushButton *m_TbnLogin;            //��¼
    QLabel *m_label_div;
    PushButton *m_TbnRegister;         //ע��

    SearchLineEdit *m_search;           //������

    PushButton *m_TbnGame;             //��Ϸ
    PushButton *m_TbnNews;             //��Ϣ֪ͨ
    PushButton *m_TbnSkin;             //Ƥ��

    PushButton *m_TbnMenu;             //���˵�
    PushButton *m_TbnRemote;           //ң����
    PushButton *m_TbnMenu_max;         //���
    PushButton *m_TbnMenu_min;         //��С��
    PushButton *m_TbnMenu_close;       //�ر�

    QHBoxLayout *m_mainLayout;

    MyMenu *m_menu;
    RemoteWidget *m_remoteWidget;
    bool m_isOpenRemote;                  //�Ƿ��ң����
};

#endif // TITLEWIDGET_H
