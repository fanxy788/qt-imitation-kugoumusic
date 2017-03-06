#include "musicabstractremotebutton.h"

MusicAbstractRemoteButton::MusicAbstractRemoteButton(QWidget *parent,
                                                     const QString &icon_name,
                                                     const QString &tooltip)
    :QToolButton(parent)
{
    setFixedSize(30,30);            //��ť�趨Ϊ�̶���С
    setIconSize(QSize(28,28));
    setAutoRaise(true);
    setIcon(QIcon(icon_name));
    setToolTip(QString("%1").arg(tooltip));
    setCursor(Qt::PointingHandCursor);

    setStyleSheet("QToolButton{border:none;}");
}

MusicAbstractRemoteButton::~MusicAbstractRemoteButton()
{

}
