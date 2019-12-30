#include "appcontroller.h"
#include <QTimer>

AppController::AppController(QObject *parent) : QObject(parent) {
    b2Vec2 gravity(0.0f, -10.0f);

    world = new b2World(gravity);

    groundBodyDef.position.Set(0.0f, -3.0f);

    ceilingBodyDef.position.Set(0.0f, 8.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    groundBody = world->CreateBody(&groundBodyDef);

    ceilingBody = world->CreateBody(&ceilingBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;
    b2PolygonShape ceilingBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(150.0f, 1.1f);
    ceilingBox.SetAsBox(150.0f, 3.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    ceilingBody->CreateFixture(&ceilingBox, 0.0f);
    for(int i = 0; i < 6;i++) {
        bodies.push_back(defineBody(i));
    }
}

b2Body* AppController::defineBody(int n) {
    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(n * 20.0f, 0.0f);
    b2Body* body = world->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 20.0f;

    // Override the default friction.
    fixtureDef.friction = 0.8f;

    fixtureDef.restitution = 0.2f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    return body;
}

void AppController::updateWorld() {
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 8;
    int32 positionIterations = 3;

    world->Step(timeStep, velocityIterations, positionIterations);
    for (int i = 0; i < 6; i++) {
        b2Vec2 position = bodies.at(i)->GetPosition();
        emit newHeight(position.y*100, i);
    }

    QTimer::singleShot(60, this, &AppController::updateWorld);
}

void AppController::applyForce(const b2Vec2 &impulse, int n) {
    bodies.at(n)->ApplyLinearImpulseToCenter(impulse, true);
}

void AppController::visualizerUpdate(Note note) {
    b2Vec2 smallForce = b2Vec2(0, 450.0f);
    b2Vec2 bigForce = b2Vec2(0, 1000.0f);
    switch(note) {
        case CNatural:
        case CSharp:
            applyForce(bigForce, 0);
            applyForce(smallForce, 1);
            break;
        case DNatural:
        case DSharp:
            applyForce(smallForce, 0);
            applyForce(bigForce, 1);
            applyForce(smallForce, 2);
            break;
        case ENatural:
        case FNatural:
            applyForce(smallForce, 1);
            applyForce(bigForce, 2);
            applyForce(smallForce, 3);
            break;
        case FSharp:
        case GNatural:
            applyForce(smallForce, 2);
            applyForce(bigForce, 3);
            applyForce(smallForce, 4);
            break;
        case GSharp:
        case ANatural:
            applyForce(smallForce, 3);
            applyForce(bigForce, 4);
            applyForce(smallForce, 5);
            break;
        case ASharp:
        case BNatural:
            applyForce(smallForce, 4);
            applyForce(bigForce, 5);
            break;
    }
}
