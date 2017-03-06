/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:�ṷ���ֲ�����---ң��������Ҽ��˵�ʵ��
**************************************************/
#ifndef RIGHTREMOTEMENU_H
#define RIGHTREMOTEMENU_H
#include "Common/menu.h"

class QAction;

class RightRwmoteMenu : public Menu
{
    Q_OBJECT
public:
    explicit RightRwmoteMenu(QWidget *parent);
    ~RightRwmoteMenu();
Q_SIGNALS:
    void signalAlwayOnTop();        //������ǰ
    void signalShowMainWidget();    //��ʾ������
    void signalRectangleRemote();   //����ң����
    void signalMagicRemote();       //ħ��ң����
    void signalHideRemote();        //����ң����

private Q_SLOTS:
public Q_SLOTS:
    void slotChangeShowMainWidgetStatus(int status);

protected:
    //virtual void paintEvent(QPaintEvent *);

private:
    void initForm();
    void initAction();
    void initConnect();

private:
    QAction *m_alwayOnTop;          //������ǰ
    QAction *m_showMainWidget;      //��ʾ������
    QAction *m_RectangleRemote;     //����ң����
    QAction *m_magicCubeRemote;     //ħ��ң����
    QAction *m_hideRemote;          //����ң����

};

#endif // RIGHTMENU_H
