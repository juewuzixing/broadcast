#include <QPushButton>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QLabel>

#include "receiver.hpp"

Receiver::Receiver(QWidget *parent)
    : QWidget(parent) {
    statusLabel = new QLabel(tr("Listening for broadcasted messages"));
    statusLabel->setWordWrap(true);

    quitButton = new QPushButton(tr("&Quit"));

    udpSocket = new QUdpSocket(this);
    // 绑定端口,共享地址模式
    udpSocket->bind(45454,QUdpSocket::ShareAddress);

    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));

    // 以控件为Layout命名
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->stretch(1);

    // 最外层的布局mainLayout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Broadcast Receiver"));
}

void Receiver::processPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        statusLabel->setText(tr("Received datagram: \"%1\"").arg(datagram.data()));
    }

}

Receiver::~Receiver() {

}
