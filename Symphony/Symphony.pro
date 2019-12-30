QT       += core gui webengine webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcontroller.cpp \
    Box2D/Collision/Shapes/b2ChainShape.cpp \
    Box2D/Collision/Shapes/b2CircleShape.cpp \
    Box2D/Collision/Shapes/b2EdgeShape.cpp \
    Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Box2D/Collision/b2BroadPhase.cpp \
    Box2D/Collision/b2CollideCircle.cpp \
    Box2D/Collision/b2CollideEdge.cpp \
    Box2D/Collision/b2CollidePolygon.cpp \
    Box2D/Collision/b2Collision.cpp \
    Box2D/Collision/b2Distance.cpp \
    Box2D/Collision/b2DynamicTree.cpp \
    Box2D/Collision/b2TimeOfImpact.cpp \
    Box2D/Common/b2BlockAllocator.cpp \
    Box2D/Common/b2Draw.cpp \
    Box2D/Common/b2Math.cpp \
    Box2D/Common/b2Settings.cpp \
    Box2D/Common/b2StackAllocator.cpp \
    Box2D/Common/b2Timer.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Box2D/Dynamics/Contacts/b2Contact.cpp \
    Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Box2D/Dynamics/Joints/b2Joint.cpp \
    Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    Box2D/Dynamics/b2Body.cpp \
    Box2D/Dynamics/b2ContactManager.cpp \
    Box2D/Dynamics/b2Fixture.cpp \
    Box2D/Dynamics/b2Island.cpp \
    Box2D/Dynamics/b2World.cpp \
    Box2D/Dynamics/b2WorldCallbacks.cpp \
    Box2D/Rope/b2Rope.cpp \
    irrklang/plugins/ikpMP3/CIrrKlangAudioStreamLoaderMP3.cpp \
    irrklang/plugins/ikpMP3/CIrrKlangAudioStreamMP3.cpp \
    irrklang/plugins/ikpMP3/decoder/bits.c \
    irrklang/plugins/ikpMP3/decoder/mpaudec.c \
    irrklang/plugins/ikpMP3/ikpMP3.cpp \
    main.cpp \
    mainwindow.cpp \
    staffwidget.cpp

HEADERS += \
    appcontroller.h \
    irrklang/include/ik_ESoundEngineOptions.h \
    irrklang/include/ik_ESoundOutputDrivers.h \
    irrklang/include/ik_EStreamModes.h \
    irrklang/include/ik_IAudioRecorder.h \
    irrklang/include/ik_IAudioStream.h \
    irrklang/include/ik_IAudioStreamLoader.h \
    irrklang/include/ik_IFileFactory.h \
    irrklang/include/ik_IFileReader.h \
    irrklang/include/ik_IRefCounted.h \
    irrklang/include/ik_ISound.h \
    irrklang/include/ik_ISoundDeviceList.h \
    irrklang/include/ik_ISoundEffectControl.h \
    irrklang/include/ik_ISoundEngine.h \
    irrklang/include/ik_ISoundMixedOutputReceiver.h \
    irrklang/include/ik_ISoundSource.h \
    irrklang/include/ik_ISoundStopEventReceiver.h \
    irrklang/include/ik_IVirtualRefCounted.h \
    irrklang/include/ik_SAudioStreamFormat.h \
    irrklang/include/ik_irrKlangTypes.h \
    irrklang/include/ik_vec3d.h \
    irrklang/include/irrKlang.h \
    irrklang/plugins/ikpMP3/CIrrKlangAudioStreamLoaderMP3.h \
    irrklang/plugins/ikpMP3/CIrrKlangAudioStreamMP3.h \
    irrklang/plugins/ikpMP3/decoder/internal.h \
    irrklang/plugins/ikpMP3/decoder/mpaudec.h \
    irrklang/plugins/ikpMP3/decoder/mpaudectab.h \
    irrklang/plugins/ikpMP3/decoder/mpegaudio.h \
    mainwindow.h \
    notes.h \
    Box2D/Box2D.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Timer.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2MotorJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Rope/b2Rope.h \
    staffwidget.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    irrklang/bin/dotnet-4-64/ikpFlac.dll \
    irrklang/bin/dotnet-4-64/ikpMP3.dll \
    irrklang/bin/dotnet-4-64/irrKlang.NET4.dll \
    irrklang/bin/linux-gcc-64/ikpFlac.so \
    irrklang/bin/linux-gcc-64/ikpMP3.so \
    irrklang/bin/linux-gcc-64/libIrrKlang.so \
    irrklang/bin/macosx-gcc/MusicPlayer \
    irrklang/bin/macosx-gcc/ikpFLAC.dylib \
    irrklang/bin/macosx-gcc/ikpMP3.dylib \
    irrklang/bin/macosx-gcc/libirrklang.dylib \
    irrklang/bin/macosx-gcc/run_MusicPlayer.command \
    irrklang/bin/winx64-visualStudio/ikpFlac.dll \
    irrklang/bin/winx64-visualStudio/ikpMP3.dll \
    irrklang/bin/winx64-visualStudio/irrKlang.dll \
    irrklang/lib/Winx64-visualStudio/irrKlang.exp \
    irrklang/lib/Winx64-visualStudio/irrKlang.lib \
    irrklang/plugins/ikpMP3/license.txt \
    irrklang/plugins/ikpMP3/readme.txt \
    res/PianoKeys/A3.wav \
    res/PianoKeys/A4.wav \
    res/PianoKeys/A5.wav \
    res/PianoKeys/A6.wav \
    res/PianoKeys/Ab3.wav \
    res/PianoKeys/Ab4.wav \
    res/PianoKeys/Ab5.wav \
    res/PianoKeys/Ab6.wav \
    res/PianoKeys/Ash3.wav \
    res/PianoKeys/Ash4.wav \
    res/PianoKeys/Ash5.wav \
    res/PianoKeys/B3.wav \
    res/PianoKeys/B4.wav \
    res/PianoKeys/B5.wav \
    res/PianoKeys/B6.wav \
    res/PianoKeys/Bb3.wav \
    res/PianoKeys/Bb4.wav \
    res/PianoKeys/Bb5.wav \
    res/PianoKeys/Bb6.wav \
    res/PianoKeys/C3.wav \
    res/PianoKeys/C4.wav \
    res/PianoKeys/C5.wav \
    res/PianoKeys/C6.wav \
    res/PianoKeys/Csh3.wav \
    res/PianoKeys/Csh4.wav \
    res/PianoKeys/Csh5.wav \
    res/PianoKeys/D3.wav \
    res/PianoKeys/D4.wav \
    res/PianoKeys/D5.wav \
    res/PianoKeys/D6.wav \
    res/PianoKeys/Db3.wav \
    res/PianoKeys/Db4.wav \
    res/PianoKeys/Db5.wav \
    res/PianoKeys/Db6.wav \
    res/PianoKeys/Dsh3.wav \
    res/PianoKeys/Dsh4.wav \
    res/PianoKeys/Dsh5.wav \
    res/PianoKeys/E3.wav \
    res/PianoKeys/E4.wav \
    res/PianoKeys/E5.wav \
    res/PianoKeys/E6.wav \
    res/PianoKeys/Eb3.wav \
    res/PianoKeys/Eb4.wav \
    res/PianoKeys/Eb5.wav \
    res/PianoKeys/Eb6.wav \
    res/PianoKeys/F3.wav \
    res/PianoKeys/F4.wav \
    res/PianoKeys/F5.wav \
    res/PianoKeys/F6.wav \
    res/PianoKeys/Fsh3.wav \
    res/PianoKeys/Fsh4.wav \
    res/PianoKeys/Fsh5.wav \
    res/PianoKeys/G3.wav \
    res/PianoKeys/G4.wav \
    res/PianoKeys/G5.wav \
    res/PianoKeys/G6.wav \
    res/PianoKeys/Gb3.wav \
    res/PianoKeys/Gb4.wav \
    res/PianoKeys/Gb5.wav \
    res/PianoKeys/Gb6.wav \
    res/PianoKeys/Gsh3.wav \
    res/PianoKeys/Gsh4.wav \
    res/PianoKeys/Gsh5.wav \
    res/bell.wav \
    res/explosion.wav \
    res/getout.ogg \
    res/license.txt \
    res/musicxml/A9_Symphony_Demo.musicxml \
    res/musicxml/A_Major_Scale.musicxml \
    res/musicxml/A_Minor_Scale.musicxml \
    res/musicxml/Ab_Minor_Scale.musicxml \
    res/musicxml/B_Major_Scale.musicxml \
    res/musicxml/B_Minor_Scale.musicxml \
    res/musicxml/Bb_Major_Scale.musicxml \
    res/musicxml/Bb_Minor_Scale.musicxml \
    res/musicxml/C_Major_Scale.musicxml \
    res/musicxml/C_Major_Warmup.musicxml \
    res/musicxml/C_Minor_Scale.musicxml \
    res/musicxml/D_Major_Scale.musicxml \
    res/musicxml/D_Minor_Scale.musicxml \
    res/musicxml/Db_Major_Scale.musicxml \
    res/musicxml/Db_Minor_Scale.musicxml \
    res/musicxml/E_Major_Scale.musicxml \
    res/musicxml/E_Minor_Scale.musicxml \
    res/musicxml/Eb_Major_Scale.musicxml \
    res/musicxml/Eb_Minor_Scale.musicxml \
    res/musicxml/F_Major_Scale .musicxml \
    res/musicxml/F_Minor_Scale.musicxml \
    res/musicxml/G_Major_Scale.musicxml \
    res/musicxml/G_Major_Warmup.musicxml \
    res/musicxml/G_Minor_Scale.musicxml \
    res/musicxml/Gb_Major_Scale.musicxml \
    res/musicxml/Gb_Minor_Scale.musicxml \
    res/musicxml/Learn_Notes_II.musicxml \
    res/musicxml/Learn_Note_Values.musicxml \
    res/musicxml/Learn_Notes_I.musicxml \
    res/musicxml/amazingGrace.musicxml \
    res/musicxml/jingleBellRock.musicxml \
    res/musicxml/merryChristmas.musicxml \
    res/ophelia.mp3

# Recompile web assets
qml_scenes.depends = $$PWD/web/
qml_scenes.commands =
QMAKE_EXTRA_TARGETS += qml_scenes

# Copy non-QRC resource files to build path
QMAKE_POST_LINK += $$quote($(COPY_DIR) $$shell_path($$PWD/res) $$shell_path($$OUT_PWD/res)) $$escape_expand(\n\t)

# Platform-specific linking of irrklang
unix:!macx {
    LIBS += -L$$PWD/irrklang/bin/linux-gcc-64/ -lIrrKlang
}

macx {
    LIBS += -L$$PWD/irrklang/bin/macosx-gcc/ -lirrklang
    OTHER_FILES += \
        $$PWD/res

    APP_QML_FILES.files = $$OTHER_FILES
    APP_QML_FILES.path = Contents/MacOS
    QMAKE_BUNDLE_DATA += APP_QML_FILES
}

win32 {
    LIBS += -L$$PWD/irrklang/lib/Winx64-visualStudio/ -lirrKlang
    QMAKE_POST_LINK += $$quote($(COPY_DIR) $$shell_path($$PWD/irrklang/bin/winx64-visualStudio) $$shell_path($$OUT_PWD)) $$escape_expand(\n\t)
}

INCLUDEPATH += $$PWD/irrklang/include
DEPENDPATH += $$PWD/irrklang/include
