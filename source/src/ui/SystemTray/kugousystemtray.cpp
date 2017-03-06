/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-01
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---ϵͳ���̵�ʵ��
**************************************************/
#include "kugousystemtray.h"
#include <QMenu>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidgetAction>
#include <QToolButton>
#include <QLabel>
#include <QSlider>
#include <QAction>
#include "voicebutton.h"
#include "musictraybutton.h"
#include "controlvalues.h"

KugouSystemTray::KugouSystemTray(QWidget *parent)
    :QSystemTrayIcon(parent)
{
    this->setIcon(QIcon(":/image/kugou.png"));
    m_trayMenu = new QMenu();
    setContextMenu(m_trayMenu);

    this->initMusiControlInfo();
    this->initMidInfo();
    this->initBottomInfo();
    this->initAction();
    this->initForm();
    this->initConnect();
}

KugouSystemTray::~KugouSystemTray()
{
}

//��������������Ϣ��ʼ��
void KugouSystemTray::initMusiControlInfo()
{
    m_topWidget = new QWidget();
    m_topWidgetAction = new QWidgetAction(m_trayMenu);

    m_play = new MusicTrayButton(m_topWidget,":/image/playControl/play.png",
                                 QString::fromLocal8Bit("����"));
    m_next = new MusicTrayButton(m_topWidget,":/image/playControl/next.png",
                                 QString::fromLocal8Bit("��һ��"));
    m_previous = new MusicTrayButton(m_topWidget,":/image/playControl/previous.png",
                                 QString::fromLocal8Bit("��һ��"));

    m_songName = new QLabel();
    m_songName->setAlignment(Qt::AlignCenter);
    m_songName->setText(QString::fromLocal8Bit("�ṷ8.0����������"));

    QHBoxLayout *playLayout = new QHBoxLayout;
    playLayout->addSpacing(6);
    playLayout->addWidget(m_previous);
    playLayout->addWidget(m_play);
    playLayout->addWidget(m_next);
    playLayout->addSpacing(6);

    QVBoxLayout *topMainLayout = new QVBoxLayout();
    topMainLayout->addLayout(playLayout);
    topMainLayout->addWidget(m_songName);
    m_topWidget->setLayout(topMainLayout);
    m_topWidgetAction->setDefaultWidget(m_topWidget);
}

//�м�˵���ʼ��
void KugouSystemTray::initMidInfo()
{
    m_playWidget = new QWidget();
    m_playVoiceWidgetAction = new QWidgetAction(m_trayMenu);

    m_noVoice = new VoiceButton;
    m_noVoice->setToolTip(QString::fromLocal8Bit("����"));

    m_musicSlider = new QSlider(Qt::Horizontal);    //ˮƽ������
    m_musicSlider->setObjectName("musicVoice");
    m_musicSlider->setValue(VOICE_DEFAULT_VALUE);


    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addSpacing(2);
    mainLayout->addWidget(m_noVoice);
    mainLayout->addWidget(m_musicSlider);
    mainLayout->addSpacing(2);
    m_playWidget->setLayout(mainLayout);
    m_playVoiceWidgetAction->setDefaultWidget(m_playWidget);
}

void KugouSystemTray::initBottomInfo()
{
    m_showDesktopLrc = new QAction(this);
    m_showDesktopLrc->setText(QString::fromLocal8Bit("��ʾ������"));

    m_unlockLrc = new QAction(this);
    m_unlockLrc->setText(QString::fromLocal8Bit("�������"));

    m_optionSetting = new QAction(this);
    m_optionSetting->setIcon(QIcon(":/image/SystemTray/option.png"));
    m_optionSetting->setText(QString::fromLocal8Bit("ѡ������"));

    m_logout = new QAction(this);
    m_logout->setText(QString::fromLocal8Bit("ע��"));

    m_exit = new QAction(this);
    m_exit->setText(QString::fromLocal8Bit("�˳�"));
}

void KugouSystemTray::initAction()
{
    m_trayMenu->addAction(m_topWidgetAction);
    m_trayMenu->addSeparator();
    m_trayMenu->addAction(m_playVoiceWidgetAction);
    m_trayMenu->addAction(m_showDesktopLrc);
    m_trayMenu->addAction(m_unlockLrc);
    m_trayMenu->addSeparator();
    m_trayMenu->addAction(m_optionSetting);
    m_trayMenu->addSeparator();
    m_trayMenu->addAction(m_logout);
    m_trayMenu->addAction(m_exit);
}

//�źźͲܵ¹���
void KugouSystemTray::initConnect()
{
    connect(m_noVoice,SIGNAL(clicked(bool)),
            this,SLOT(slotVoiceStateChange()));
    connect(m_exit,SIGNAL(triggered(bool)),
            this,SIGNAL(signalClose()));

    //��������仯����
    connect(m_musicSlider,SIGNAL(valueChanged(int)),this,
            SLOT(slotMusicSliderValueChange(int)));
}

void KugouSystemTray::initForm()
{
    m_unlockLrc->setEnabled(false);
}

void KugouSystemTray::slotVoiceStateChange()
{
    if (m_noVoice->getCheck())
    {
        emit signalVoiceNormal();
        m_musicSlider->setValue(VOICE_DEFAULT_VALUE);
#if QDEBUG_OUT
        qDebug()<<"voice";
#endif
    }
    else{
        emit signalNoVoice();
        m_musicSlider->setValue(NO_VOICE);
#if QDEBUG_OUT
        qDebug()<<"no voice";
#endif
    }
}

void KugouSystemTray::slotMusicSliderValueChange(int value)
{
    if (NO_VOICE == value)
    {
        m_noVoice->setCheck(false);
    }else
    {
        m_noVoice->setCheck(true);
    }
}
