/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--Ƥ���봰�ڵ�������
**************************************************/
#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QDialog>
#include "drop_shadow_widget.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class PushButton;
class QLabel;
class QWidgetAction;
class QCheckBox;
class QComboBox;
class QStackedWidget;

class SkinWidget : public DropShadowWidget
{
    Q_OBJECT
public:
    explicit SkinWidget(QWidget *parent = 0);
    ~SkinWidget();
    void translator();

private slots:
    void slotClose();
private:
    void initForm();
    void initWidget();
    void initLayout();
    void initConnect();

private:
    QWidget *m_titleWidget;
    QLabel *m_labelTitle;
    PushButton *m_pbnClose;
    QHBoxLayout *m_titleLayout;

    QPushButton *m_pbnRecoSkin;     //�Ƽ�Ƥ��
    QPushButton *m_pbnMySkin;       //�ҵ�Ƥ��
    QPushButton *m_pbnRecover;      //�ָ�����Ĭ��״̬
    QStackedWidget *m_stackenWidget;

    QStringList m_listSkin;
    QList<QWidget *> list_action;
    QGridLayout *m_center_layout;

    QLabel *m_labelListTransparent; //�б�͸��
    QComboBox *m_cbxTrValue;        //͸��ֵ
    QCheckBox *m_ckxSkinTr;         //Ƥ��͸��
    QComboBox *m_cbxSkValue;        //͸��ֵ
    QPushButton *m_PbnPalette;
    QPushButton *m_pbnCustom;       //�Զ���

    QHBoxLayout *m_bottomLayout;    //�ײ�����

    QVBoxLayout *m_mainLayout;

};

#endif // SKINWIDGET_H
