/****************************************************************************
** Meta object code from reading C++ file 'paneldibujo.h'
**
** Created: Tue Oct 25 19:15:28 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Programada4/paneldibujo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paneldibujo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PanelDibujo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      34,   32,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PanelDibujo[] = {
    "PanelDibujo\0\0s\0changeSides(int)\0r\0"
    "changeRadius(double)\0"
};

const QMetaObject PanelDibujo::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_PanelDibujo,
      qt_meta_data_PanelDibujo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PanelDibujo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PanelDibujo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PanelDibujo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PanelDibujo))
        return static_cast<void*>(const_cast< PanelDibujo*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int PanelDibujo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeSides((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: changeRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
