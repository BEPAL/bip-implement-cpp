TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../../src/

win32::INCLUDEPATH += $$PWD/../../depends/include/
win32::LIBS += -L$$PWD/../../depends/lib/openssl/ -llibeay32


SOURCES += \
    $$PWD/main.cpp \
    $$PWD/keytreeutil.cpp \
    $$PWD/../../src/keynode/keynode.cpp \
    $$PWD/../../src/keynode/logger.cpp \
    $$PWD/../../src/keynode/CoinClasses/hdkeys.cpp

HEADERS += \
    $$PWD/keytreeutil.h \
    $$PWD/../../src/keynode/keynode.h \
    $$PWD/../../src/keynode/logger.h \
    $$PWD/../../src/keynode/stringutils.h \
    $$PWD/../../src/keynode/CoinClasses/Base58Check.h \
    $$PWD/../../src/keynode/CoinClasses/BigInt.h \
    $$PWD/../../src/keynode/CoinClasses/encodings.h \
    $$PWD/../../src/keynode/CoinClasses/hash.h \
    $$PWD/../../src/keynode/CoinClasses/hdkeys.h \
    $$PWD/../../src/keynode/CoinClasses/secp256k1.h \
    $$PWD/../../src/keynode/CoinClasses/typedefs.h \
    $$PWD/../../src/keynode/CoinClasses/uchar_vector.h
