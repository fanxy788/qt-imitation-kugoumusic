/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:�ṷ���ֲ�����---ң��������Ҽ��˵�ʵ��
**************************************************/
#include "rightremotemenu.h"
#include <QAction>
#include <QPainter>
#include "controlvalues.h"

RightRwmoteMenu::RightRwmoteMenu(QWidget *parent)
    :Menu(parent)
{
    initForm();
    initAction();
    initConnect();
}

RightRwmoteMenu::~RightRwmoteMenu()
{
    delete m_alwayOnTop;
    delete m_showMainWidget;
    delete m_RectangleRemote;
    delete m_magicCubeRemote;
    delete m_hideRemote;
}

void RightRwmoteMenu::slotChangeShowMainWidgetStatus(int status)
{
    if (SHOW_MAIN_WIDGET == status)
    {
        m_showMainWidget->setText(QString::fromLocal8Bit("����������"));
    }else if (HIDE_MAIN_WIDGET == status)
    {
        m_showMainWidget->setText(QString::fromLocal8Bit("��ʾ������"));
    }
}

void RightRwmoteMenu::initForm()
{
    setWindowOpacity(0.5);
    //setStyleSheet("padding:5px;background:white;border:1px solid gray;");
    setObjectName("remote_rightMenu");
}

void RightRwmoteMenu::initAction()
{
    m_alwayOnTop = new QAction(QString::fromLocal8Bit("������ǰ"),this);
    m_showMainWidget = new QAction(QString::fromLocal8Bit("��ʾ������"),this);
    m_RectangleRemote = new QAction(QString::fromLocal8Bit("����ң����"),this);
    m_magicCubeRemote = new QAction(QString::fromLocal8Bit("ħ��ң����"),this);
    m_hideRemote = new QAction(QString::fromLocal8Bit("����ң����"),this);

    addAction(m_alwayOnTop);
    addAction(m_showMainWidget);
    addSeparator();
    addAction(m_RectangleRemote);
    addAction(m_magicCubeRemote);
    addAction(m_hideRemote);

    //����ȫ�ֱ���ֵȷ�������浱ǰ״̬
    if (g_WidgetIsMin)
    {
        m_showMainWidget->setText(QString::fromLocal8Bit("��ʾ������"));
    }else
    {
        m_showMainWidget->setText(QString::fromLocal8Bit("����������"));
    }
}

void RightRwmoteMenu::initConnect()
{
    connect(m_alwayOnTop,SIGNAL(triggered(bool)),
            this,SIGNAL(signalAlwayOnTop()));
    connect(m_showMainWidget,SIGNAL(triggered(bool)),
            this,SIGNAL(signalShowMainWidget()));
    connect(m_RectangleRemote,SIGNAL(triggered(bool)),
            this,SIGNAL(signalRectangleRemote()));
    connect(m_magicCubeRemote,SIGNAL(triggered(bool)),
            this,SIGNAL(signalMagicRemote()));
    connect(m_hideRemote,SIGNAL(triggered(bool)),
            this,SIGNAL(signalHideRemote()));
}
