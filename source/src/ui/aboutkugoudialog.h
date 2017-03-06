/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--���ڿṷ
**************************************************/
#ifndef ABOUTKUGOUDIALOG_H
#define ABOUTKUGOUDIALOG_H

#include "drop_shadow_widget.h"
#include <QDialog>
class PushButton;
class ToolButton;
class QLabel;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;

class AboutKugouDialog : public DropShadowWidget
{
    Q_OBJECT
public:
    explicit AboutKugouDialog(QDialog *parent = 0);
    ~AboutKugouDialog();

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
    QLabel *m_labelTitle;               //����
    PushButton *m_tbnClose;             //�ر�

    QLabel *m_labelMidIcon;             //�м���ڿṷͼ��
    QLabel *m_labelMidContent;          //�м�����
    QLabel *m_labelWebsite;             //����
    QTextEdit *m_textIntruction;        //���

    ToolButton *m_tbnOk;
    QHBoxLayout *m_titleLayout;         //����������
    QVBoxLayout *m_midLayout;           //�м����ݲ���
    QVBoxLayout *m_mainLayout;          //������
};

#endif // ABOUTKUGOUDIALOG_H
