/****************************************************************************
** Meta object code from reading C++ file 'ClientApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/ClientApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientApp_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientApp_t qt_meta_stringdata_ClientApp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ClientApp"
QT_MOC_LITERAL(1, 10, 15), // "connectToServer"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "bindUdpSocket"
QT_MOC_LITERAL(4, 41, 4), // "port"
QT_MOC_LITERAL(5, 46, 15), // "retryUdpBinding"
QT_MOC_LITERAL(6, 62, 2), // "ip"
QT_MOC_LITERAL(7, 65, 11), // "sendMessage"
QT_MOC_LITERAL(8, 77, 11), // "readMessage"
QT_MOC_LITERAL(9, 89, 14), // "onDisconnected"
QT_MOC_LITERAL(10, 104, 18), // "sendPrivateMessage"
QT_MOC_LITERAL(11, 123, 21) // "receivePrivateMessage"

    },
    "ClientApp\0connectToServer\0\0bindUdpSocket\0"
    "port\0retryUdpBinding\0ip\0sendMessage\0"
    "readMessage\0onDisconnected\0"
    "sendPrivateMessage\0receivePrivateMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    2,   58,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    6,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientApp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectToServer(); break;
        case 1: { bool _r = _t->bindUdpSocket((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->retryUdpBinding((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sendMessage(); break;
        case 4: _t->readMessage(); break;
        case 5: _t->onDisconnected(); break;
        case 6: _t->sendPrivateMessage(); break;
        case 7: _t->receivePrivateMessage(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ClientApp.data,
    qt_meta_data_ClientApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientApp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
