/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-01
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---ϵͳ���̵�ʵ��
**************************************************/
#ifndef KUGOUSYSTEMTRAY_H
#define KUGOUSYSTEMTRAY_H

#include <QSystemTrayIcon>
class QWidgetAction;
class QToolButton;
class QLabel;
class QSlider;
class QAction;
class VoiceButton;
class MusicTrayButton;

class KugouSystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    KugouSystemTray(QWidget *parent = 0);
    ~KugouSystemTray();


Q_SIGNALS:
    void signalNoVoice();
    void signalVoiceNormal();
    void signalLogOut();
    void signalClose();
private Q_SLOTS:
    void slotVoiceStateChange();
    void slotMusicSliderValueChange(int value);

private:
    void initMusiControlInfo();
    void initMidInfo();
    void initBottomInfo();
    void initAction();
    void initConnect();
    void initForm();

private:
    QMenu *m_trayMenu;

    QWidget *m_topWidget;
    QWidgetAction *m_topWidgetAction;
    MusicTrayButton *m_play;                    //����
    QToolButton *m_next;                        //��һ��
    QToolButton *m_previous;                    //��һ��
    QLabel *m_songName;                         //��������

    QWidget *m_playWidget;
    QWidgetAction *m_playVoiceWidgetAction;     //������������
    VoiceButton *m_noVoice;                     //����
    QSlider *m_musicSlider;

    QAction *m_showDesktopLrc;                  //��ʾ������
    QAction *m_unlockLrc;                       //�������
    QAction *m_optionSetting;                   //ѡ������
    QAction *m_logout;                          //ע��
    QAction *m_exit;                            //�˳�
};

#endif // KUGOUSYSTEMTRAY_H
