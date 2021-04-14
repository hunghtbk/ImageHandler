#ifndef CONTROLLMAINAPP_H
#define CONTROLLMAINAPP_H
#include <QQmlApplicationEngine>
#include <Class/UIBridge.h>
#include <QQmlContext>

class ControllMainAPP : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void initControlMainApp();
    static ControllMainAPP* getInstance();
private:
    ControllMainAPP();
    static ControllMainAPP *m_instance;
    QQmlApplicationEngine m_qmlEngine;
    QObject* m_mainWindow = nullptr;

    QObject *rootObject;
    QObject *qmlObject;

    UIBridge* m_uiBridge = nullptr;
public slots:
    handleHMIEvent(QString a,QString b);
    handleChangePositionEvent(int x, int y, QString currentIMGObjName);
};

#endif // CONTROLLMAINAPP_H
