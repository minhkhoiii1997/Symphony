#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <Box2D/Box2D.h>
#include <QTimer>
#include "notes.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);
    b2World* world;
    std::vector<b2Body*> bodies;
    b2Body* groundBody;
    b2Body* ceilingBody;
    b2BodyDef groundBodyDef;
    b2BodyDef ceilingBodyDef;
    void applyForce(const b2Vec2&, int);

private:
    b2Body* defineBody(int);

signals:
    void newHeight(int, int);

public slots:
    void updateWorld();
    void visualizerUpdate(Note);
};

#endif // APPCONTROLLER_H
