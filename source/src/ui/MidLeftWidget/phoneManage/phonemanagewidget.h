#ifndef PHONEMANAGEWIDGET_H
#define PHONEMANAGEWIDGET_H

#include <QWidget>
class QPushButton;
class QStackedWidget;
class QVBoxLayout;
class QLabel;
class PushButton;

class PhoneManageWidget : public QWidget
{
    enum Widget{
        HomeWidget,
        WiredWidget,
        WirelessWidget
    };
    Q_OBJECT
public:
    explicit PhoneManageWidget(QWidget *parent = 0);

signals:

private slots:
    void slotShowHomeWidget();
    void slotShowWiredWidget();            //��ʾ�������ӽ���
    void slotShowWirelessWidget();         //��ʾ�������ӽ���
private:
    void initForm();
    void initWidget();
    void initWiredWidget();
    void initWirelessWidget();
    void initConnect();
private:
    QPushButton *m_pbnReturn;              //���ذ�ť
    QLabel *m_labelConnectWay;             //���ӷ�ʽ

    QWidget *m_homeWidget;

    QPushButton *m_pbnWiredConnect;        //��������
    QWidget *m_wireWidget;

    QPushButton *m_pbnWirelessConnect;     //��������
    QWidget *m_wirelessWidget;

    QStackedWidget *m_stackedWidget;
    QVBoxLayout *m_mainLayout;
};

#endif // PHONEMANAGEWIDGET_H
