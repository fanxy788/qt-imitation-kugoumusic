/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-09
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ������������ʵ��
**************************************************/
#include "musicwidget.h"
#include "TitleBar/titlewidget.h"
#include "BottomBar/bottomwidget.h"
#include "midwidget.h"
#include "MidLeftWidget/lefttoolbar.h"
#include "myplayer.h"
#include "controlvalues.h"
#include "SkinWidget/skinwidget.h"         //Ƥ������
#include "SystemTray/kugousystemtray.h"    //ϵͳ����

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QBitmap>
#include <QPainter>

//ȫ�ֱ������洰�ڵ�ǰ��״̬
bool g_WidgetIsMin = false;

//��������ģʽ
MusicWidget *MusicWidget::m_pInstance = NULL;

MusicWidget::MusicWidget(QWidget *parent)
    :QFrame(parent)
{
    this->initForm();
    this->initWidget();
    this->initConnect();
    this->translator();
}

MusicWidget::~MusicWidget()
{
}

//��ʼ����ʽ
void MusicWidget::initForm()
{
    //���ô��ڴ�С
    this->setMinimumSize(WIDGET_WIDTH,WIDGET_HEIGHT);
    //���ر�����
    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinMaxButtonsHint);

    this->setWindowTitle(QString::fromLocal8Bit("�ṷ����"));
    this->setObjectName("MainFrame");
    setStyleSheet(QString("#MainFrame {background-image:url(:/image/skin/%1);"
                          "border:1px solid black;}").arg(DEFAULT_SKIN));

    m_location = this->geometry();
    m_isMax = false;
    m_isPressed = false;
}

//��ʼ������
void MusicWidget::initWidget()
{
    m_title = new TitleWidget(this);        //������
    m_title->installEventFilter(this);      //��������װ�¼�������,ʶ������˫��

    m_midWidget = new MidWidget(this);      //�м�����
    m_bottom = new BottomWidget(this);      //�ײ�������
    m_leftToolBar = new LeftToolBar(this);  //��߹��߰�ť

    m_midLayout = new QHBoxLayout();
    m_midLayout->addWidget(m_leftToolBar);
    m_midLayout->addWidget(m_midWidget);
    m_midLayout->setContentsMargins(2,0,0,0);

    m_maintLayout = new QVBoxLayout(this);
    m_maintLayout->addWidget(m_title);
    m_maintLayout->addLayout(m_midLayout);
    m_maintLayout->addWidget(m_bottom);
    m_maintLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_maintLayout);

    m_player = new MyPlayer();
    m_skinWidget = new SkinWidget;

    m_tray = new KugouSystemTray(this);
    m_tray->show();
}

//��ʼ���źźͲ۵�����
void MusicWidget::initConnect()
{
    /******************���������ư�ť�źŹ���********************/
    connect(m_title,SIGNAL(signalHideWidget()),
            this,SLOT(slotHide()));
    connect(m_title,SIGNAL(signalClose()),
            this,SLOT(slotClose()));
    connect(m_title,SIGNAL(signalMax()),
            this,SLOT(slotShowMax()));
    connect(this,SIGNAL(signalMax(int)),
            m_title,SLOT(slotChangeBtnStatus(int)));
    connect(m_title,SIGNAL(signalMix()),
            this,SLOT(slotShowMin()));
    connect(m_title,SIGNAL(signalShowSkin()),
            this,SLOT(slotShowSkinWidget()));
    //ң����
    connect(m_title,SIGNAL(signalShowOrHideWidget(int)),
            this,SLOT(slotShowOrHideWidget(int)));

    /*******************�ײ����ֲ��ſ����źźͲ۹���***************/
    connect(m_bottom,SIGNAL(signalPlay()),
            m_player,SLOT(slotPlayMusic()));

    /********************��߹������źŹ���**********************/
    connect(m_leftToolBar,SIGNAL(signalLocalList()),
            m_midWidget,SIGNAL(signalLocalList()));
    connect(m_leftToolBar,SIGNAL(signalNetCollect()),
            m_midWidget,SIGNAL(signalNetCollect()));
    connect(m_leftToolBar,SIGNAL(signalMusicRadio()),
            m_midWidget,SIGNAL(signalMusicRadio()));
    connect(m_leftToolBar,SIGNAL(signalPhoneManage()),
            m_midWidget,SIGNAL(signalPhoneManage()));
    connect(m_leftToolBar,SIGNAL(signalLocalMusic()),
            m_midWidget,SIGNAL(signalLocalMusic()));
    connect(m_leftToolBar,SIGNAL(signalMoreTool()),
            m_midWidget,SIGNAL(signalMoreTool()));

    /*********************ϵͳ�����źŹ���*********************/
    connect(m_tray,SIGNAL(signalClose()),
            this,SLOT(slotClose()));
    connect(m_tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
}

//���ط����ļ�
void MusicWidget::translator()
{
    m_title->Translator();
    m_leftToolBar->traanslator();
    m_midWidget->translator();
    m_bottom->translator();
}

void MusicWidget::slotHide()
{
    //    m_tray->showMessage(QString::fromLocal8Bit("��ӭ��"),
    //                        QString::fromLocal8Bit("��ӭʹ�ÿṷ����"));
    g_WidgetIsMin = true;
    this->hide();
}

void MusicWidget::slotClose()
{
    qApp->exit();
}

void MusicWidget::slotShowMax()
{
    if (m_isMax)
    {
        this->setGeometry(m_location);
        emit signalMax(BtnMax);
    }else
    {
        m_location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        emit signalMax(BtnMin);
    }

    g_WidgetIsMin = false;
    m_isMax = !m_isMax;
}

void MusicWidget::slotShowMin()
{
    g_WidgetIsMin = true;
    this->showMinimized();
}

void MusicWidget::slotShowSkinWidget()
{
    m_skinWidget->exec();
}

void MusicWidget::slotShowOrHideWidget(int status)
{
    if (SHOW_MAIN_WIDGET == status)
    {
        this->show();

    }else if (HIDE_MAIN_WIDGET == status)
    {
        this->slotHide();
    }
}

//����ģʽ��ʵ��
MusicWidget *MusicWidget::Instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new MusicWidget();
    }
    return m_pInstance;
}

void MusicWidget::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        this->show();
        g_WidgetIsMin = true;
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        g_WidgetIsMin = true;
        break;
    default:
        break;
    }
}

bool MusicWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        this->slotShowMax();
        return true;
    }
    return QObject::eventFilter(obj,event);
}

void MusicWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed && event->buttons() && Qt::LeftButton && !m_isMax)
    {
        this->move(event->globalPos() - m_point);
        event->accept();
    }
}

void MusicWidget::mousePressEvent(QMouseEvent *event)
{
    if  (event->button() == Qt::LeftButton)
    {
        m_point = event->globalPos() - this->pos();
        m_isPressed = true;
        event->accept();
    }
}

void MusicWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isPressed = false;
    }
}

void MusicWidget::paintEvent(QPaintEvent *)
{
    //����һ��λͼ
    QBitmap objBitmap(size());
    //QPainter������λͼ�ϻ滭
    QPainter painter(&objBitmap);
    //���λͼ���ο�(�ð�ɫ���)
    painter.fillRect(rect(),Qt::white);
    painter.setBrush(QColor(0,0,0));
    //��λͼ�ϻ�Բ�Ǿ���(�ú�ɫ���)
    painter.drawRoundedRect(this->rect(),6,6);
    //ʹ��setmask���˼���
    setMask(objBitmap);
}
