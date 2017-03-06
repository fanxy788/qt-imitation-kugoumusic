#ifndef MYMENU_H
#define MYMENU_H
#include <QAction>
#include "Common/menu.h"

class Play_Mode_Menu;
class AboutKugouDialog;

class MyMenu : public Menu
{
    Q_OBJECT
public:
   explicit MyMenu(QWidget *parent = 0);
    ~MyMenu();

    void translator();

Q_SIGNALS:
    void signal_quit();
private Q_SLOTS:
    void slotShowAboutKugou();                  //��ʾ���ڿṷ����

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QAction *m_actionLogin;                     //��¼

    Menu *m_menuAddMusic;
    QAction *m_actionAddLocalMusic;             //��ӱ�������
    QAction *m_actionAddLocalFolderMusic;       //���ظ����ļ���

    Play_Mode_Menu *m_playMode;                 //����ģʽ

    //ң���������˵�
    Menu *m_menuRemote;                         //ң����
    QAction *m_actionMagicRemote;               //ħ��ң����
    QAction *m_actionStripRemote;               //����ң����
    QAction *m_actionHideRemote;                //����ң����

    QAction *m_actionAverageBalance;            //������
    QAction *m_actionMusicPlug;                 //���ֲ��
    QAction *m_actiontimingSetting;             //��ʱ����

    QAction *m_actionAlwaysFront;               //����������ǰ
    QAction *m_actionRecoveryStatus;            //�ָ�����Ĭ��״̬

    //�������ö����˵�
    Menu *m_menuDownloadSetting;                //��������
    QAction *m_actionAllSpeedDownload;          //ȫ������
    QAction *m_actionCustomDownload;            //�Զ���
    QAction *m_actionBroadband;                 //��ʡ���

    QAction *m_actionOnLineUpdate;              //��������
    QAction *m_actionShowTodayRecommend;        //��ʾ�����Ƽ�

    //������������������˵�
    Menu *m_menuHelp;
    QAction *m_actionHelp;                      //����
    QAction *m_actionSuggest;                   //����
    QAction *m_actionAboutKugou;                //���ڿṷ

    QAction *m_actionSetting;                   //����
    QAction *m_actionQuit;                      //�˳�

    //�˵��ӹ���
    AboutKugouDialog *m_aboutKugou;             //���ڿṷ
};

#endif // MYMENU_H
