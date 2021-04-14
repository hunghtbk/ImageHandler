#include "UIBridge.h"
#include <QDebug>

UIBridge::UIBridge(QObject* appWindows) : QObject(appWindows) {
    connect(this, SIGNAL(hmiEvent(QString,QString)), appWindows, SLOT(handleHMIEvent(QString,QString)));
    connect(this, SIGNAL(changePositionEvent(int, int, QString)), appWindows, SLOT(handleChangePositionEvent(int, int, QString)));
    connect(this, SIGNAL(sendListToControllApp(QStringList)), appWindows, SLOT(handleList(QStringList)));
}
void UIBridge::log(QString message) {
    emit hmiEvent(message, "hunght signal");
}

void UIBridge::setCurrentObjectName(QString message)
{
    currentImageObjName = message;
    qDebug() << "Current OBJ Name " << currentImageObjName;
}

void UIBridge::mainQMLCallChangePosition(int x, int y)
{
    qDebug() << "Change position x = " << x << " - y = " << y;
    emit changePositionEvent(x, y, currentImageObjName);
}

void UIBridge::importObjectNametToList(QString obj)
{
    objNameList.append(obj);
}

void UIBridge::genInfo()
{
    emit sendListToControllApp(objNameList);
}
