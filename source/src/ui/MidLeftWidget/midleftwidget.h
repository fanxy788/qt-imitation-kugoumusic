/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--�м䴰�岿��--��߸����б����
**************************************************/
#ifndef MIDLEFTWIDGET_H
#define MIDLEFTWIDGET_H

#include <QWidget>
class QVBoxLayout;
class LocalListWidget;
class NetWorkCollectWidget;
class MusicRadioWidget;
class MoreToolWidget;
class QStackedWidget;
class PhoneManageWidget;
class DownloadWidget;

//ö�ٵ�ǰ��������ֵ
enum CurrentWidget{
    LOCAL_LIST,
    NETWORK_COLLECT,
    MUSIC_RADIO,
    PHONE_MANAGE,
    LOCAL_MUSIC,
    MORE_TOOL
};
class MidLeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidLeftWidget(QWidget *parent = 0);

signals:

public slots:
    void slotShowLocalList();               //�����б�
    void slotShowNetCollect();              //�����ղ�
    void slotShowMusicRadio();              //���ֵ�̨
    void slotShowPhoneManage();             //�ֻ�����
    void slotShowLocalMusic();              //��������
    void slotShowMoreTool();                //����
protected:
    void paintEvent(QPaintEvent *);
private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QVBoxLayout *m_mainLayout;

    QStackedWidget *m_stackedWidget;
    LocalListWidget *m_localListWidget;         //�����б�
    NetWorkCollectWidget *m_netWorkWidget;      //�����ղ�
    MusicRadioWidget *m_musicRadioWidget;       //���ֵ�̨
    PhoneManageWidget *m_phonoeManage;          //�ֻ�����
    DownloadWidget *m_download;                 //��������
    MoreToolWidget *m_moreTool;                 //����
};

#endif // MIDLEFTWIDGET_H
