/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--���ڿṷ
**************************************************/
#include "aboutkugoudialog.h"
#include "Common/pushbutton.h"
#include "Common/toolbutton.h"
#include "controlvalues.h"
#include "iconhelper.h"
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

AboutKugouDialog::AboutKugouDialog(QDialog *parent)
    :DropShadowWidget(parent)
{
    this->initWidget();
    this->initLayout();
    this->initForm();
    this->initConnect();
}

AboutKugouDialog::~AboutKugouDialog()
{
}

void AboutKugouDialog::translator()
{
    m_labelTitle->setText(tr("about_kugou"));
    m_tbnClose->setToolTip(tr("tbn_close"));

    m_tbnOk->setText(tr("tbn_ok"));
}

void AboutKugouDialog::slotClose()
{
    this->close();
}

void AboutKugouDialog::initForm()
{
    this->setFixedSize(420,325);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //IconHelper::Instance()->SetIcon(m_tbnClose,QChar(0xf00d),12);

    m_tbnClose->setObjectName("pbnClose");
    m_tbnClose->setCursor(Qt::PointingHandCursor);
    m_tbnOk->setCursor(Qt::PointingHandCursor);
    m_tbnOk->setFixedSize(80,28);
    m_tbnOk->setObjectName("tbnOk");

    m_titleWidget->setFixedHeight(30);
    m_titleWidget->setStyleSheet(QString("background-image:url(:/image/skin/%1);"
                          "border:1px").arg(DEFAULT_SKIN));

    m_labelMidIcon->setFixedHeight(100);
    m_labelMidIcon->setStyleSheet("border-image:url(:/image/aboutKugou/aboutKugou.png)");
    m_labelMidContent->setText(QString::fromLocal8Bit("KuGou  Version:8024\n"
                                                      "���ݿṷ������Ƽ����޹�˾ ��Ȩ����\n"
                                                      "Copyright(C) 2004-1016 KuGou-Inc.All Rights Reserved"));
    m_labelWebsite->setText("<a href=\"http://www.kugou.com\">http://www.kugou.com</a>");
    //m_textIntruction->setEnabled(false);
    m_textIntruction->setFont(QFont("Times", 10, QFont::Normal));
    m_textIntruction->setText(QString::fromLocal8Bit("     �ṷ���־߱����ֲ��š�������"
                                                     "���ء�����ͺ��ѷ���ȹ��ܣ���һ������׿Խ�������С�����滪��������"
                                                     "�򵥵�ȫ�����������;\n     �����׼�Ӧ������֪ʶ��Ȩ������ָ�Ƽ���,"
                                                     "ӵ�������з������棬���ݲ���MP3/MP3pro,AAC/AAC+��MP4/MP4R��WMA��"
                                                     "WAV��APE,OGG��FLA��FLAC����Ƶ���,֧�����и�ʽ��MP3/WAV�ļ��ĸ�ʽ"
                                                     "��ת�����ֻ���������;"));
}

void AboutKugouDialog::initWidget()
{
    m_titleWidget = new QWidget(this);
    m_labelTitle = new QLabel(m_titleWidget);
    m_labelTitle->setObjectName("whitelabel");
    m_tbnClose = new PushButton(m_titleWidget);

    m_labelMidIcon = new QLabel(this);
    m_labelMidContent = new QLabel(this);
    m_labelWebsite = new QLabel(this);
    m_textIntruction = new QTextEdit(this);
    m_tbnOk = new ToolButton(this);
}

void AboutKugouDialog::initLayout()
{
    //����������
    m_titleLayout = new QHBoxLayout(m_titleWidget);
    m_titleLayout->addSpacing(5);
    m_titleLayout->addWidget(m_labelTitle);
    m_titleLayout->addStretch();
    m_titleLayout->addWidget(m_tbnClose);
    m_titleLayout->setContentsMargins(0,0,0,0);
    //m_titleWidget->setContentsMargins(0,0,0,0);

    //�м�ͼ�겼��(�����Զͻ������)
    QVBoxLayout *iconLayout = new QVBoxLayout();
    iconLayout->addWidget(m_labelMidIcon);
    iconLayout->setContentsMargins(0,0,0,0);

    //�м����ݲ���
    m_midLayout = new QVBoxLayout();
    m_midLayout->addWidget(m_labelMidContent);
    m_midLayout->addWidget(m_labelWebsite);
    m_midLayout->addWidget(m_textIntruction);
    m_midLayout->setContentsMargins(20,0,20,0);

    //�ײ�����
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addStretch();
    layout->addWidget(m_tbnOk);
    layout->addSpacing(10);
    layout->setContentsMargins(0,0,0,0);

    //���岼��
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_titleWidget);
    m_mainLayout->addLayout(iconLayout);
    //m_mainLayout->addWidget(m_labelMidIcon);
    m_mainLayout->addLayout(m_midLayout);
    m_mainLayout->addLayout(layout);
    m_mainLayout->addSpacing(10);
    m_mainLayout->setContentsMargins(9,8,9,5);
    setLayout(m_mainLayout);
}

void AboutKugouDialog::initConnect()
{
    connect(m_tbnClose,SIGNAL(clicked(bool)),
            this,SLOT(slotClose()));
    connect(m_tbnOk,SIGNAL(clicked(bool)),
            this,SLOT(slotClose()));
}

