/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-06
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---ң�������ܵ�ʵ��
2016-3-9 15:35:52:�����޸��˽��沼�֣��滻��֮ǰ������ť
**************************************************/
#include "remotewidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QSlider>
#include <QPainter>
#include "controlvalues.h"
#include "core/musicabstractremotebutton.h"
#include "playmusicwidget.h"
#include "nextmusicwidget.h"
#include "previousmusicwidget.h"
#include "desktopphotowidget.h"
#include "openkugouwidget.h"
#include "rightremotemenu.h"

RemoteWidget::RemoteWidget(QWidget *parent)
    : MusicAbstractRemoteWidget(parent)
{
    initForm();
    initLayout();
    initStyle();
    initConnect();
}

RemoteWidget::~RemoteWidget()
{
    delete m_tbnPlayOrPause;
    delete m_nextWidget;
    delete m_previousWidget;
    delete m_desktopWidget;
    delete m_kugouWidget;
}

void RemoteWidget::slotShowMenu(const QPoint &pos)
{
    Q_UNUSED(pos);

    m_rightRemoteMenu->exec(QCursor::pos());
}

void RemoteWidget::slotAlwayOnTop()
{
}

void RemoteWidget::slotShowOrHidMainWidget()
{
    if (m_isShowMainWidget)
    {
        m_isShowMainWidget = false;
        emit signalShowOrHidMainWidget(SHOW_MAIN_WIDGET);
    }else
    {
        m_isShowMainWidget = true;
        emit signalShowOrHidMainWidget(HIDE_MAIN_WIDGET);
    }
}

//��ʾ����ң����
void RemoteWidget::slotShowRectangleRemote()
{
}

//��ʾħ��ң����
void RemoteWidget::slotShowMagicRemote()
{
}

void RemoteWidget::initForm()
{
    //�Զ�������Ҽ��˵�
    setContextMenuPolicy(Qt::CustomContextMenu);
    //������ʾλ��
    QDesktopWidget *pDesk = QApplication::desktop();
    move(pDesk->width()*5/6,pDesk->height()/4);

    m_midWidget = new PlayMusicWidget(this);
    m_nextWidget = new NextMusicWidget(this);
    m_previousWidget = new PreviousMusicWidget(this);
    m_kugouWidget = new OpenKugouWidget(this);
    m_desktopWidget = new DesktopPhotoWidget(this);

    m_rightRemoteMenu = new RightRwmoteMenu(this);

    //��ȡ��ǰ���ڵĵ�״̬����ʾ��������
    if (g_WidgetIsMin)
    {
        m_isShowMainWidget = true;      //Ĭ�Ͽ�����ʾ������(���Ե��acton)
    }else
    {
        m_isShowMainWidget = false;
    }
}

void RemoteWidget::initLayout()
{
    m_gridLayout = new QGridLayout(this);
    m_gridLayout->addWidget(m_kugouWidget,0,1,1,1,Qt::AlignCenter);
    m_gridLayout->addWidget(m_previousWidget,1,0,1,1,Qt::AlignCenter);
    m_gridLayout->addWidget(m_midWidget,1,1,1,1,Qt::AlignCenter);
    m_gridLayout->addWidget(m_nextWidget,1,2,Qt::AlignCenter);
    m_gridLayout->addWidget(m_desktopWidget,2,1,1,1,Qt::AlignCenter);
    m_gridLayout->setContentsMargins(0,0,0,0);
    setLayout(m_gridLayout);
}

void RemoteWidget::initStyle()
{
}

void RemoteWidget::initConnect()
{
    //ң��������Ҽ�����
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),
            this,SLOT(slotShowMenu(QPoint)));
    //�����Ҽ��˵���
    connect(m_rightRemoteMenu,SIGNAL(signalAlwayOnTop()),
            this,SLOT(slotAlwayOnTop()));
    connect(m_rightRemoteMenu,SIGNAL(signalShowMainWidget()),
            this,SLOT(slotShowOrHidMainWidget()));
    connect(m_rightRemoteMenu,SIGNAL(signalRectangleRemote()),
            this,SLOT(slotShowRectangleRemote()));
    connect(m_rightRemoteMenu,SIGNAL(signalMagicRemote()),
            this,SLOT(slotShowMagicRemote()));
    connect(m_rightRemoteMenu,SIGNAL(signalHideRemote()),
            this,SIGNAL(signalHideRemote()));
    //�����źţ��ı�״̬
    connect(this,SIGNAL(signalShowOrHidMainWidget(int)),
            m_rightRemoteMenu,SLOT(slotChangeShowMainWidgetStatus(int)));
}



