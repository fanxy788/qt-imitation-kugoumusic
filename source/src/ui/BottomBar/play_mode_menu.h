/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-02-15
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:���ֲ�����--����ģʽ�˵���ʵ��
**************************************************/
#ifndef PLAY_MODE_MENU_H
#define PLAY_MODE_MENU_H
#include "Common/menu.h"

class Play_Mode_Menu : public Menu
{
    Q_OBJECT
public:
    explicit Play_Mode_Menu(QWidget *parent = 0);
    ~Play_Mode_Menu();
    void translator();
private:
    void initForm();
    void initMenu();
    void initConnect();

private:
    QAction *m_actionSinglePlay;            //��������
    QAction *m_actionSingleCirculate;       //����ѭ��
    QAction *m_actionOrderPlay;             //˳�򲥷�
    QAction *m_actionListCirculate;         //�б�ѭ��
    QAction *m_actionRandomPlay;            //�������
    QAction *m_actionAutoSwitchList;        //�Զ��л��б�
};

#endif // PLAY_MODE_MENU_H
