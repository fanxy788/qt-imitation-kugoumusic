/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-10
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--�м䴰�岿��--��߸����б����
**************************************************/
#include "midleftwidget.h"
#include "localList/locallistwidget.h"              //�����б�
#include "networkCollect/networkcollectwidget.h"    //�����ղ�
#include "musicRadio/musicradiowidget.h"            //���ֵ�̨
#include "phoneManage/phonemanagewidget.h"          //�ֻ�����
#include "download/downloadwidget.h"                //��������
#include "moreTools/moretoolwidget.h"               //���๦�ܽ���

#include <QPainter>
#include <QPen>
#include <QVBoxLayout>
#include <QStackedWidget>

MidLeftWidget::MidLeftWidget(QWidget *parent) : QWidget(parent)
{
    this->initWidget();
    this->initForm();
    this->initConnect();
}

void MidLeftWidget::slotShowLocalList()
{
    m_stackedWidget->setCurrentIndex(LOCAL_LIST);
}

void MidLeftWidget::slotShowNetCollect()
{
    m_stackedWidget->setCurrentIndex(NETWORK_COLLECT);
}

void MidLeftWidget::slotShowMusicRadio()
{
    m_stackedWidget->setCurrentIndex(MUSIC_RADIO);
}

void MidLeftWidget::slotShowPhoneManage()
{
    m_stackedWidget->setCurrentIndex(PHONE_MANAGE);
}

void MidLeftWidget::slotShowLocalMusic()
{
    m_stackedWidget->setCurrentIndex(LOCAL_MUSIC);
}

void MidLeftWidget::slotShowMoreTool()
{
    m_stackedWidget->setCurrentIndex(MORE_TOOL);
}

void MidLeftWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen objPen(Qt::transparent);
    painter.setPen(objPen);
    QBrush objBrush(QColor(255,255,255,180));
    painter.setBrush(objBrush);
    painter.drawRect(this->rect());
}

void MidLeftWidget::initForm()
{
    this->setFixedWidth(310);
}

void MidLeftWidget::initWidget()
{
    m_stackedWidget = new QStackedWidget(this);

    m_localListWidget = new LocalListWidget();
    m_netWorkWidget = new NetWorkCollectWidget();
    m_musicRadioWidget = new MusicRadioWidget();
    m_localListWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_phonoeManage = new PhoneManageWidget();
    m_download = new DownloadWidget();
    m_moreTool = new MoreToolWidget();

    m_stackedWidget->addWidget(m_localListWidget);  //�����б�
    m_stackedWidget->addWidget(m_netWorkWidget);    //�����ղ�
    m_stackedWidget->addWidget(m_musicRadioWidget); //���ֵ�̨
    m_stackedWidget->addWidget(m_phonoeManage);     //�ֻ�����
    m_stackedWidget->addWidget(m_download);         //��������
    m_stackedWidget->addWidget(m_moreTool);         //����

    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_stackedWidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_mainLayout);
}

void MidLeftWidget::initConnect()
{
}

