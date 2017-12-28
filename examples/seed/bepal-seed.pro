TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
DEFINES+= QT_PROJECT
INCLUDEPATH += $$PWD/../../src/

SOURCES += main.cpp \
    $$PWD/../../src/crypto/mnemoniccode.cpp \
    $$PWD/../../src/crypto/pbkdf2sha512.cpp \
    $$PWD/../../src/crypto/hmac_sha512.cpp \
    $$PWD/../../src/crypto/sha512.cpp

HEADERS += \
    $$PWD/../../src/crypto/mnemoniccode.h \
    $$PWD/../../src/crypto/pbkdf2sha512.h \
    $$PWD/../../src/crypto/common.h \
    $$PWD/../../src/crypto/hmac_sha512.h \
    $$PWD/../../src/crypto/sha512.h \
    $$PWD/../../src/compat/byteswap.h \
    $$PWD/../../src/compat/endian.h
