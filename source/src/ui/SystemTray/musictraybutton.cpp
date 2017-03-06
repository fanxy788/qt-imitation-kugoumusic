/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-3-04
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--ϵͳ���̲˵��Զ��尴ťʵ��:
            ʵ����������ʾ��ͼ�����ã���ťͻ�������ʽ
**************************************************/
#include "musictraybutton.h"

MusicTrayButton::MusicTrayButton(QWidget *parent, const QString &icon,
                                 const QString &text)
    :QToolButton(parent),m_icon(icon),m_text(text)
{
    setToolTip(m_text);
    setIcon(QIcon(m_icon));
    setIconSize(QSize(30,30));
    setAutoRaise(true);
    setCursor(Qt::PointingHandCursor);

    initConnect();
}

MusicTrayButton::~MusicTrayButton()
{
}

void MusicTrayButton::initConnect()
{
}

