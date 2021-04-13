#include "UIBridge.h"
#include <QDebug>

UIBridge::UIBridge(QObject* appWindows) : QObject(appWindows) {
    connect(this, SIGNAL(hmiEvent(QString,QString)), appWindows, SLOT(handleHMIEvent(QString,QString)));
}
void UIBridge::log(QString message) {
    emit hmiEvent(message, "hunght signal");
}
