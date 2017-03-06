#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QObject>
class QMediaPlayer;

class MyPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MyPlayer(QObject *parent = 0);

    enum PlayerState{
        NOMUSIC,
        PAUSE,
        PLAYING
    };
public:
    void setMusicPlay();                       //���ò���
    void setMusicPause();                       //������ͣ

signals:
    void signalPlayStateChanged(int state);     //����״̬�ı�

public slots:
    void slotSetMusicVoice(int voice);          //���ò���������С
    void slotPlayMusic();                       //��������
    void slotPauseMusic();                      //��ͣ����
    void slotPlayPre();                         //������һ��
    void slotPlayNext();                        //������һ��
private:
    void initForm();
    void initWidget();
    void initConnect();
private:
    QMediaPlayer *m_player;
};

#endif // MYPLAYER_H
