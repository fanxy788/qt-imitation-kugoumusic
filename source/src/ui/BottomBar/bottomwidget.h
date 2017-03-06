/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---�ײ����ƽ���
**************************************************/
#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H
#include <QWidget>

class ToolButton;
class QLabel;
class QHBoxLayout;
class SliderWidget;
class Play_Mode_Menu;

class BottomWidget : public QWidget
{
   Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = 0);
    ~BottomWidget();

    void translator();

private:
    void initForm();
    void initWidget();
    void initConnect();

signals:
    void signalPreious();
    void signalPlay();
    void signalNext();

private:
    ToolButton *m_tbnNext;             //��һ��
    ToolButton *m_tbnPlay;             //����/��ͣ
    ToolButton *m_tbnPerious;          //��һ��

    QLabel *m_labelMusicName;          //��������
    QLabel *m_labelMusicTotalTime;     //������ʱ��
    QLabel *m_labelMusicCurTime;       //��ǰ���ŵ�����ʱ��

    SliderWidget *m_sliderWidget;       //���Ž�����

    ToolButton *m_tbnLove;             //�ղ�
    ToolButton *m_tbnDownload;         //����
    ToolButton *m_tbnSimilarMusic;     //���Ƹ���

    ToolButton *m_tbnCircleMode;       //����ģʽ
    Play_Mode_Menu *m_playMode;        //����ģʽ�˵�

    ToolButton *m_tbnVoice;            //����
    ToolButton *m_tbnSoundEffect;      //��Ч
    ToolButton *m_tbnMusicWords;       //���
    ToolButton *m_tbnMusicPlayQueue;   //���Ŷ���(�����ŵĸ�������)
    QLabel *m_label_misic_num;          //�����ŵĸ�������

    QHBoxLayout *m_MusicInfoLayout;     //������Ϣ����
    QHBoxLayout *m_mainLayout;          //�ܲ���
};

#endif // BOTTOMWIDGET_H
