/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButton_ajouter_maintenance_clicked",
    "",
    "on_pushButton_supprimer_maintenance_clicked",
    "on_pushButton_modifier_maintenance_clicked",
    "on_pushButton_exporter_maintenance_clicked",
    "on_pushButton_recherche_maintenance_clicked",
    "on_comboBox_tri_maintenance_currentTextChanged",
    "priorite",
    "on_pushButton_calendrier_clicked",
    "on_acceuilmaintenance_clicked",
    "on_acceuilmaintenance_2_clicked",
    "on_pushButton_QRC_clicked",
    "on_pushButton_stat2_maintenance_clicked",
    "on_pushButton_stat_maintenance_clicked",
    "chargerMaintenancesDansCalendrier",
    "chargerRappelsDansTableau",
    "ajouterOuModifierRappel",
    "idMaintenance",
    "afficherRappelsPourDate",
    "date",
    "on_pushButton_afficher_arduino_clicked",
    "onReadyRead",
    "on_btnGoToArduino_clicked",
    "on_btnRetourPage15_clicked",
    "chamberExists",
    "roomId",
    "setupAlertTable",
    "loadAlertHistory"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[58];
    char stringdata0[11];
    char stringdata1[42];
    char stringdata2[1];
    char stringdata3[44];
    char stringdata4[43];
    char stringdata5[43];
    char stringdata6[44];
    char stringdata7[47];
    char stringdata8[9];
    char stringdata9[33];
    char stringdata10[30];
    char stringdata11[32];
    char stringdata12[26];
    char stringdata13[40];
    char stringdata14[39];
    char stringdata15[34];
    char stringdata16[26];
    char stringdata17[24];
    char stringdata18[14];
    char stringdata19[24];
    char stringdata20[5];
    char stringdata21[39];
    char stringdata22[12];
    char stringdata23[26];
    char stringdata24[27];
    char stringdata25[14];
    char stringdata26[7];
    char stringdata27[16];
    char stringdata28[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 41),  // "on_pushButton_ajouter_mainten..."
        QT_MOC_LITERAL(53, 0),  // ""
        QT_MOC_LITERAL(54, 43),  // "on_pushButton_supprimer_maint..."
        QT_MOC_LITERAL(98, 42),  // "on_pushButton_modifier_mainte..."
        QT_MOC_LITERAL(141, 42),  // "on_pushButton_exporter_mainte..."
        QT_MOC_LITERAL(184, 43),  // "on_pushButton_recherche_maint..."
        QT_MOC_LITERAL(228, 46),  // "on_comboBox_tri_maintenance_c..."
        QT_MOC_LITERAL(275, 8),  // "priorite"
        QT_MOC_LITERAL(284, 32),  // "on_pushButton_calendrier_clicked"
        QT_MOC_LITERAL(317, 29),  // "on_acceuilmaintenance_clicked"
        QT_MOC_LITERAL(347, 31),  // "on_acceuilmaintenance_2_clicked"
        QT_MOC_LITERAL(379, 25),  // "on_pushButton_QRC_clicked"
        QT_MOC_LITERAL(405, 39),  // "on_pushButton_stat2_maintenan..."
        QT_MOC_LITERAL(445, 38),  // "on_pushButton_stat_maintenanc..."
        QT_MOC_LITERAL(484, 33),  // "chargerMaintenancesDansCalend..."
        QT_MOC_LITERAL(518, 25),  // "chargerRappelsDansTableau"
        QT_MOC_LITERAL(544, 23),  // "ajouterOuModifierRappel"
        QT_MOC_LITERAL(568, 13),  // "idMaintenance"
        QT_MOC_LITERAL(582, 23),  // "afficherRappelsPourDate"
        QT_MOC_LITERAL(606, 4),  // "date"
        QT_MOC_LITERAL(611, 38),  // "on_pushButton_afficher_arduin..."
        QT_MOC_LITERAL(650, 11),  // "onReadyRead"
        QT_MOC_LITERAL(662, 25),  // "on_btnGoToArduino_clicked"
        QT_MOC_LITERAL(688, 26),  // "on_btnRetourPage15_clicked"
        QT_MOC_LITERAL(715, 13),  // "chamberExists"
        QT_MOC_LITERAL(729, 6),  // "roomId"
        QT_MOC_LITERAL(736, 15),  // "setupAlertTable"
        QT_MOC_LITERAL(752, 16)   // "loadAlertHistory"
    },
    "MainWindow",
    "on_pushButton_ajouter_maintenance_clicked",
    "",
    "on_pushButton_supprimer_maintenance_clicked",
    "on_pushButton_modifier_maintenance_clicked",
    "on_pushButton_exporter_maintenance_clicked",
    "on_pushButton_recherche_maintenance_clicked",
    "on_comboBox_tri_maintenance_currentTextChanged",
    "priorite",
    "on_pushButton_calendrier_clicked",
    "on_acceuilmaintenance_clicked",
    "on_acceuilmaintenance_2_clicked",
    "on_pushButton_QRC_clicked",
    "on_pushButton_stat2_maintenance_clicked",
    "on_pushButton_stat_maintenance_clicked",
    "chargerMaintenancesDansCalendrier",
    "chargerRappelsDansTableau",
    "ajouterOuModifierRappel",
    "idMaintenance",
    "afficherRappelsPourDate",
    "date",
    "on_pushButton_afficher_arduino_clicked",
    "onReadyRead",
    "on_btnGoToArduino_clicked",
    "on_btnRetourPage15_clicked",
    "chamberExists",
    "roomId",
    "setupAlertTable",
    "loadAlertHistory"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x08,    1 /* Private */,
       3,    0,  153,    2, 0x08,    2 /* Private */,
       4,    0,  154,    2, 0x08,    3 /* Private */,
       5,    0,  155,    2, 0x08,    4 /* Private */,
       6,    0,  156,    2, 0x08,    5 /* Private */,
       7,    1,  157,    2, 0x08,    6 /* Private */,
       9,    0,  160,    2, 0x08,    8 /* Private */,
      10,    0,  161,    2, 0x08,    9 /* Private */,
      11,    0,  162,    2, 0x08,   10 /* Private */,
      12,    0,  163,    2, 0x08,   11 /* Private */,
      13,    0,  164,    2, 0x08,   12 /* Private */,
      14,    0,  165,    2, 0x08,   13 /* Private */,
      15,    0,  166,    2, 0x08,   14 /* Private */,
      16,    0,  167,    2, 0x08,   15 /* Private */,
      17,    1,  168,    2, 0x08,   16 /* Private */,
      19,    1,  171,    2, 0x08,   18 /* Private */,
      21,    0,  174,    2, 0x08,   20 /* Private */,
      22,    0,  175,    2, 0x08,   21 /* Private */,
      23,    0,  176,    2, 0x08,   22 /* Private */,
      24,    0,  177,    2, 0x08,   23 /* Private */,
      25,    1,  178,    2, 0x08,   24 /* Private */,
      27,    0,  181,    2, 0x08,   26 /* Private */,
      28,    0,  182,    2, 0x08,   27 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QDate,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButton_ajouter_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_modifier_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_exporter_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_recherche_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_tri_maintenance_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_calendrier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_acceuilmaintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_acceuilmaintenance_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_QRC_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_stat2_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_stat_maintenance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chargerMaintenancesDansCalendrier'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chargerRappelsDansTableau'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterOuModifierRappel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'afficherRappelsPourDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>,
        // method 'on_pushButton_afficher_arduino_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGoToArduino_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRetourPage15_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chamberExists'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setupAlertTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadAlertHistory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_maintenance_clicked(); break;
        case 1: _t->on_pushButton_supprimer_maintenance_clicked(); break;
        case 2: _t->on_pushButton_modifier_maintenance_clicked(); break;
        case 3: _t->on_pushButton_exporter_maintenance_clicked(); break;
        case 4: _t->on_pushButton_recherche_maintenance_clicked(); break;
        case 5: _t->on_comboBox_tri_maintenance_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_pushButton_calendrier_clicked(); break;
        case 7: _t->on_acceuilmaintenance_clicked(); break;
        case 8: _t->on_acceuilmaintenance_2_clicked(); break;
        case 9: _t->on_pushButton_QRC_clicked(); break;
        case 10: _t->on_pushButton_stat2_maintenance_clicked(); break;
        case 11: _t->on_pushButton_stat_maintenance_clicked(); break;
        case 12: _t->chargerMaintenancesDansCalendrier(); break;
        case 13: _t->chargerRappelsDansTableau(); break;
        case 14: _t->ajouterOuModifierRappel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->afficherRappelsPourDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 16: _t->on_pushButton_afficher_arduino_clicked(); break;
        case 17: _t->onReadyRead(); break;
        case 18: _t->on_btnGoToArduino_clicked(); break;
        case 19: _t->on_btnRetourPage15_clicked(); break;
        case 20: { bool _r = _t->chamberExists((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->setupAlertTable(); break;
        case 22: _t->loadAlertHistory(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
