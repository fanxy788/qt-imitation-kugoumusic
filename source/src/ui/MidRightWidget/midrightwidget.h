/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--�м䴰�岿��--�ұ߲���
**************************************************/
#ifndef MIDRIGHTWIDGET_H
#define MIDRIGHTWIDGET_H

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QToolButton;
class QStackedWidget;

class RadioWidget;
class MusicLyricWidget;
class MvWidget;

class MidRightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidRightWidget(QWidget *parent = 0);

    void translator();

protected:
    void paintEvent(QPaintEvent *);
    virtual bool event(QEvent *);
private:
    void initForm();
    void initWidget();
    void initConnect();

signals:
    void signalShowSplitter(bool);
private Q_SLOTS:
    void slotShowRadioWidget();         //��ʾ��̨����
    void slotShowLyric();               //��ʾ���
    void slotShowMV();                  //��ʾMV����

private:

    QWidget *m_toolWidget;
    QToolButton *m_tbnReturn;           //����
    QToolButton *m_tbnRefresh;          //ˢ��

    QToolButton *m_tbnMusicLibrary;     //�ֿ�
    QToolButton *m_tbnRadio;            //��̨
    QToolButton *m_tbnMusicList;        //�赥
    QToolButton *m_tbnMV;               //MV
    QToolButton *m_tbnTelecase;         //ֱ��
    QToolButton *m_tbnMusicWord;        //���

    QVector<QToolButton *>m_vecTbn;

    RadioWidget *m_radioWidget;         //��̨����
    MvWidget *m_mvWidget;               //MV����
    MusicLyricWidget *m_lyricWidget;    //��ʽ���

    QHBoxLayout *m_tabLayout;           //����������
    QVBoxLayout *m_mainLayout;          //������

    QStackedWidget *m_stackedWidget;
};

#endif // MIDRIGHTWIDGET_H
