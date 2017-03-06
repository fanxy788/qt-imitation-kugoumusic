/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-2-29
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����---����������Ҽ��˵���ʵ��
**************************************************/
#ifndef RIGHTMENU_H
#define RIGHTMENU_H
#include "Common/menu.h"

class RightMenu : public Menu
{
    Q_OBJECT
public:
    explicit RightMenu(QWidget *parent = 0);
    ~RightMenu();
    void translator();

signals:
    void signalClip();
    void signalCopy();
    void signalPaste();
    void signalDelete();
    void signalSelectAll();
private:
    void initForm();
    void initConnect();
private:
    QAction *m_clip;                //����
    QAction *m_copy;                //����
    QAction *m_paste;               //ճ��
    QAction *m_delete;              //ɾ��
    QAction *m_selectAll;           //ȫѡ
};

#endif // RIGHTMENU_H
