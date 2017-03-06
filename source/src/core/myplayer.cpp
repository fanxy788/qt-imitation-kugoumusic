#include "myplayer.h"

#include <QMediaPlayer>

MyPlayer::MyPlayer(QObject *parent) : QObject(parent)
{
    this->initWidget();
    this->initWidget();
    this->initConnect();
}

//���ò�������
void MyPlayer::setMusicPlay()
{
    m_player->play();
    emit signalPlayStateChanged(PLAYING);
}

//��ͣ����
void MyPlayer::setMusicPause()
{
    m_player->pause();
    emit signalPlayStateChanged(PAUSE);
}

//������������
void MyPlayer::slotSetMusicVoice(int voice)
{
    m_player->setVolume(voice);
    emit signalPlayStateChanged(PLAYING);
}

//�ۺ���---��������
void MyPlayer::slotPlayMusic()
{
    m_player->play();
    emit signalPlayStateChanged(PLAYING);
}

//�ۺ���--��ͣ����
void MyPlayer::slotPauseMusic()
{
    m_player->pause();
    emit signalPlayStateChanged(PAUSE);
}

//�ۺ���--������һ������
void MyPlayer::slotPlayPre()
{
}

//�ۺ���--������һ������
void MyPlayer::slotPlayNext()
{
}

void MyPlayer::initForm()
{
}

void MyPlayer::initWidget()
{
    m_player = new QMediaPlayer;
}

void MyPlayer::initConnect()
{
}

