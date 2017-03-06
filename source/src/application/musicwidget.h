/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ������������ʵ��
**************************************************/
#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QSystemTrayIcon>

class TitleWidget;
class BottomWidget;
class MidWidget;
class LeftToolBar;

class QVBoxLayout;
class QHBoxLayout;

class MyPlayer;
class SkinWidget;
class KugouSystemTray;

class MusicWidget : public QFrame
{
    Q_OBJECT
public:
    MusicWidget(QWidget *parent = 0);
    ~MusicWidget();
private:
    void initForm();
    void initWidget();
    void initConnect();
    void translator();

Q_SIGNALS:
    void signalMax(int);

private Q_SLOTS:
    void slotHide();
    void slotClose();
    void slotShowMax();
    void slotShowMin();
    void slotShowSkinWidget();

    void slotShowOrHideWidget(int);

    void iconIsActived(QSystemTrayIcon::ActivationReason reason);

public:
    static MusicWidget *Instance();
private:
    static MusicWidget *m_pInstance;

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:

    bool m_isMax;
    bool m_isPressed;
    QPoint m_point;
    QRect m_location;

    TitleWidget *m_title;                //������
    BottomWidget *m_bottom;              //�ײ�������
    MidWidget *m_midWidget;              //�м���ʾ����
    LeftToolBar *m_leftToolBar;          //��߹�����
    QHBoxLayout *m_midLayout;            //�м�ˮƽ����
    QVBoxLayout *m_maintLayout;          //�ܲ���

    MyPlayer *m_player;                  //�������������ָ��

    SkinWidget *m_skinWidget;            //Ƥ������

    KugouSystemTray *m_tray;             //ϵͳ����

};

#endif // MUSICWIDGET_H
