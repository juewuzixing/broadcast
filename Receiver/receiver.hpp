#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;
QT_END_NAMESPACE

class Receiver : public QWidget
{
    Q_OBJECT

public:
    Receiver(QWidget *parent = 0);
    ~Receiver();
private slots:
    void processPendingDatagrams();
private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QUdpSocket *udpSocket;
};

#endif // RECEIVER_HPP
