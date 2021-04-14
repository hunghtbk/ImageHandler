#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QObject>

class UIBridge: public QObject
{
    Q_OBJECT
public:
    explicit UIBridge(QObject *appWindows = nullptr);
    Q_INVOKABLE void log(QString message);
    Q_INVOKABLE void setCurrentObjectName(QString message);
    Q_INVOKABLE void mainQMLCallChangePosition(int x, int y);
signals:
    hmiEvent(QString, QString);
    changePositionEvent(int x, int y, QString currentIMGObjName);
private:
    QString currentImageObjName;
};

#endif // UIBRIDGE_H
