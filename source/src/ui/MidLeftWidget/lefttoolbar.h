/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---��߹��߰�ť��ʵ��
**************************************************/
#ifndef LEFTTOOLBAR_H
#define LEFTTOOLBAR_H

#include <QWidget>

class QVBoxLayout;
class ToolButton;

class LeftToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit LeftToolBar(QWidget *parent = 0);

    void traanslator();
Q_SIGNALS:
    void signalNetCollect();
    void signalPhoneManage();
    void signalMusicRadio();
    void signalLocalMusic();
    void signalLocalList();
    void signalMoreTool();

public Q_SLOTS:
private:
    void initForm();
    void initWidget();
    void initConnect();
    void setButtonStyle(ToolButton *);

private:
    ToolButton *m_tbnLocalList;        //�����б�
    ToolButton *m_tbnNetworkCollect;   //�����ղ�
    ToolButton *m_tbnMusicRadio;       //���ֵ�̨
    ToolButton *m_tbnPhoneManage;      //�ֻ�����
    ToolButton *m_tbnLocalMusic;       //��������
    ToolButton *m_tbnMore;             //����

    QVBoxLayout *m_mainLayout;

    QVector<ToolButton *>m_vecTbn;
};

#endif // LEFTTOOLBAR_H
