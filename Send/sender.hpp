#ifndef SENDER_HPP
#define SENDER_HPP

#include <QWidget>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QPushButton;
class QTimer;
class QUdpSpcket;
QT_END_NAMESPACE

class Sender : public QWidget
{
    Q_OBJECT

public:
    Sender(QWidget *parent = 0);
    ~Sender();
private slots:
    void startBroadcasting();
    void broadcastDatagram();
private:
    QLabel *statusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QUdpSocket *udpSocket;
    QTimer *timer;
    int messageNo;
};

#endif // SENDER_HPP
