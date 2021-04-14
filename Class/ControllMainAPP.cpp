#include "ControllMainAPP.h"
#include <QDebug>
ControllMainAPP* ControllMainAPP::m_instance = nullptr;
void ControllMainAPP::initControlMainApp()
{
    m_uiBridge = new UIBridge(this);
    m_qmlEngine.rootContext()->setContextProperty("UIBridge", m_uiBridge);

    m_qmlEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

ControllMainAPP *ControllMainAPP::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new ControllMainAPP();
    }
    return m_instance;
}

ControllMainAPP::ControllMainAPP()
{

}

ControllMainAPP::handleHMIEvent(QString a, QString b)
{
    qDebug() << a << b;
}

ControllMainAPP::handleChangePositionEvent(int x, int y, QString currentIMGObjName)
{
    qDebug() << "Control Main " << x << "-" << y << "OBJ" << currentIMGObjName;
    rootObject = m_qmlEngine.rootObjects().first();
    qmlObject = rootObject->findChild<QObject*>(currentIMGObjName);
    if (currentIMGObjName == "") {
        qDebug() << "Don't Handle";
    } else {
        if (qmlObject) {
            qDebug() << "it is ok";
            int imgX = qmlObject->property("x").toInt();
            int imgY = qmlObject->property("y").toInt();
            int imgWidth = qmlObject->property("width").toInt();
            int imgHeight = qmlObject->property("height").toInt();

            int newX = imgX + x - imgWidth/2;
            int newY = imgY + y - imgHeight/2;
            qmlObject->setProperty("x", newX);
            qmlObject->setProperty("y", newY);
        } else {
            qDebug() << "Not found qml object";
        }
    }
}

ControllMainAPP::handleList(QStringList mList)
{
    for (int i = 0; i < mList.length(); i++) {
        qDebug() << "Information of objectname: " << mList.at(i);
    }
}
