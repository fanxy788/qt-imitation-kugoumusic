/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-06
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---ң�������ܵ�ʵ��
**************************************************/
#ifndef REMOTEWIDGET_H
#define REMOTEWIDGET_H

#include "core/musicabstractremotewidget.h"
//class MusicAbstractRemoteWidget;

#include <QMap>
class QGridLayout;
class QSlider;
class MusicAbstractRemoteButton;
class PlayMusicWidget;
class NextMusicWidget;
class PreviousMusicWidget;
class OpenKugouWidget;
class DesktopPhotoWidget;
class RightRwmoteMenu;

class RemoteWidget : public MusicAbstractRemoteWidget
{
    Q_OBJECT
public:
    explicit RemoteWidget(QWidget *parent = 0);
    ~RemoteWidget();

Q_SIGNALS:
    void signalShowOrHidMainWidget(int);
    void signalHideRemote();

private Q_SLOTS:
    void slotShowMenu(const QPoint&);
    void slotAlwayOnTop();              //������ǰ
    void slotShowOrHidMainWidget();     //��ʾ������������
    void slotShowRectangleRemote();     //��ʾ����ң����
    void slotShowMagicRemote();         //��ʾħ��ң����
private:
    void initForm();                    //��ʽ��ʼ��
    void initLayout();                  //��ʼ������
    void initStyle();
    void initConnect();                 //��ʼ���ź���۵�����

private:
    //QMap<QString,QString> m_iconMap;            //ͼƬ·��
    PlayMusicWidget *m_midWidget;               //���봰��
    NextMusicWidget *m_nextWidget;
    PreviousMusicWidget *m_previousWidget;
    OpenKugouWidget *m_kugouWidget;
    DesktopPhotoWidget *m_desktopWidget;

    MusicAbstractRemoteButton *m_tbnPlayOrPause;
    MusicAbstractRemoteButton *m_tbnNext;
    MusicAbstractRemoteButton *m_noVoice;
    QSlider *m_musicSlitter;
    MusicAbstractRemoteButton *m_tbnPrevious;
    MusicAbstractRemoteButton *m_tbnOpenOrHideKugou;
    MusicAbstractRemoteButton *m_tbnOpenOrCloseDesktop;

    QGridLayout *m_gridLayout;

    RightRwmoteMenu *m_rightRemoteMenu;
    bool m_isShowMainWidget;
};

#endif // REMOTEWIDGET_H
