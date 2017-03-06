#ifndef HELPER_H
#define HELPER_H

#include <QObject>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = 0);

signals:

public slots:

public:
    //�����־��Ϣ���ļ���
    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context,
                                const QString &msg);
    //���������ַ�
    static void setChinese(const QString &file_path);
    //������ʽ��
    static void setStyleSheet(const QString &styleName);
};

#endif // HELPER_H
