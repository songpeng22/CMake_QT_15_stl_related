#include "main.h"
#include <QApplication>
#include <QGuiApplication>
//For Debug
#include <QDebug>
//For Qml loading Method 1
#include <QQmlApplicationEngine>
//For Qml loading Method 2
#include <QQuickView>
#include <QQmlContext>
//For Qml loading Method 3
#include <QQuickWidget>
//For Qml loading Method 4
#include <QQmlComponent>
//For Qml loading Method 5
#include "EngineReloaderWrapper.h"
//For Debugging
#include <QQmlDebuggingEnabler>
//
#include <QQuickWindow>
#include <QQuickItem>

#include "Widget.h"
#include <QStringList>
#include <QRegExp>

//For static link
#ifdef QT_STATIC
    //Qt
    #include <QtCore/QtPlugin>
    //QWindowsIntegrationPlugin "platforms/qwindows.dll" //Qt5Gui_QWindowsIntegrationPlugin.cmake
    Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
    //Install Qml plugins
#include <QtQml/QQmlExtensionPlugin>
    //${QQMLDIR}QtQuick.2/qtquick2plugind.lib
    Q_IMPORT_PLUGIN(QtQuick2Plugin)
    //${QQMLDIR}QtQuick/Window.2/windowplugind.lib
    Q_IMPORT_PLUGIN(QtQuick2WindowPlugin)
    //${QQMLDIR}QtQuick/Controls.2/qtquickcontrols2plugind.lib
    //${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugind.lib
    //${QLIBDIR}Qt5QuickTemplates2d.lib
    Q_IMPORT_PLUGIN(QtQuickControls2Plugin)
    //${QQMLDIR}QtQuick/Templates.2/qtquicktemplates2plugind.lib
    //${QLIBDIR}Qt5QuickTemplates2d.lib
    Q_IMPORT_PLUGIN(QtQuickTemplates2Plugin)
    //${QQMLDIR}QtQuick/Layouts/qquicklayoutsplugind.lib
    Q_IMPORT_PLUGIN(QtQuickLayoutsPlugin)
    //${QQMLDIR}QtQuick/Controls.2/Fusion/qtquickcontrols2fusionstyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Imagine/qtquickcontrols2imaginestyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Material/qtquickcontrols2materialstyleplugin.lib
    //${QQMLDIR}QtQuick/Controls.2/Universal/qtquickcontrols2universalstyleplugin.lib
    Q_IMPORT_PLUGIN(QtQuickControls2FusionStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2ImagineStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2MaterialStylePlugin)
    Q_IMPORT_PLUGIN(QtQuickControls2UniversalStylePlugin)
    //${QQMLDIR}QtQuick/Dialogs/dialogplugind.lib
    //QtQuick/Dialogs/Private/dialogsprivateplugind.lib
    Q_IMPORT_PLUGIN(QtQuick2DialogsPlugin)
    Q_IMPORT_PLUGIN(QtQuick2DialogsPrivatePlugin)
    //${QQMLDIR}Qt/labs/folderlistmodel/qmlfolderlistmodelplugind.lib
    Q_IMPORT_PLUGIN(QmlFolderListModelPlugin)
    //${QQMLDIR}Qt/labs/settings/qmlsettingsplugin.lib
    Q_IMPORT_PLUGIN(QmlSettingsPlugin)
    //${QQMLDIR}QtGraphicalEffects/qtgraphicaleffectsplugin.lib
    Q_IMPORT_PLUGIN(QtGraphicalEffectsPlugin)
    //${QQMLDIR}QtGraphicalEffects/private/qtgraphicaleffectsprivate.lib
    Q_IMPORT_PLUGIN(QtGraphicalEffectsPrivatePlugin)
    //${QQMLDIR}QtQml/Models.2/modelsplugin.lib
    Q_IMPORT_PLUGIN(QtQmlModelsPlugin)
    //${QQMLDIR}QtQuick/Extras/qtquickextrasplugin.lib
    Q_IMPORT_PLUGIN(QtQuickExtrasPlugin)
    //${QQMLDIR}QtQuick/PrivateWidgets/widgetsplugin.lib
    Q_IMPORT_PLUGIN(QtQuick2PrivateWidgetsPlugin)
    //QtQuick\Controls/qtquickcontrolsplugind.lib
    Q_IMPORT_PLUGIN(QtQuickControls1Plugin)

#endif

#if 1
/*
 * QT
 */
int main(int argc, char *argv[])
{
    int i = 0;
    /*
     * QStringList
     */
    QStringList strList;
    strList.append("111");
    strList << "222";
    strList << "333" << "444" << "555";
    qDebug() << "strList contains: " << strList.contains("111");
    qDebug() << "strList get index: " << strList.indexOf("333");

    /*
     * QString
     */
    QString strMain("rev requested from dialog6");
    qDebug() << strMain;
    if (strMain.contains("request"))
        qDebug() << "contains request";
    else
        qDebug() << "do not contains request";
    if (strMain.contains("hello"))
        qDebug() << "contains hello";
    else
        qDebug() << "do not contains hello";
    strMain = QString("  lots\t of\nwhitespace\r\n ");
    strMain.remove(QRegExp("[ \\t\\f\\n\\r]"));
    qDebug() << "strMain" << strMain;
#if defined(CODE_OFF)
    QApplication a(argc, argv);
    Widget w;
    w.resize(960,640);
    w.show();
#endif
    /*
     * QChar
     */
    QString strChar("this is qchar string");
    QChar qchar('a');
    qDebug() << qchar;
    strChar.append(qchar);
    qDebug() << strChar;
    /*
     * QChar Array
     */
    QChar qchArr[10];
    qchArr[0] = 'a';
    qchArr[1] = 'b';
    qchArr[2] = 'c';
    QString qchArrStr("123");
    for (i = 0; i < 10; i++)
        if (qchArr[i].isNull())
            break;
    qchArrStr.append(qchArr, i);
    qDebug() << "QChar Array test:" << sizeof(QChar) << " " << qchArrStr;
    /*
     * QLatin1String
     */
    QLatin1String strLatin("this is latin string.");
    qDebug() << strLatin;

//    return a.exec();
}

#elif 0

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //Settings
    QCoreApplication::setOrganizationName("Bizerba");
    QCoreApplication::setApplicationName("QmlLoader");
    QCoreApplication::setOrganizationDomain("Bizerba.com");
    //Engine
    EngineReloaderWrapper engine;
    QUrl url = QUrl(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}

#elif 0

/*
* Call QML : Method 4
*
*/
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QQmlEngine *engine = new QQmlEngine;
    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:///method2.qml")));
//    QQmlComponent component(engine, QUrl::fromLocalFile("method2.qml "));

    if(component.isReady()){
        QObject *myObject = component.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(myObject);
        int width = item->width();  // width = 200
        qDebug()<<width;
    }
    return app.exec();
}

#elif 0

/*
* Call QML : Method 3
* QQuickWidget是继承于 QWidget 控件，这种方式主要是用于在 QWidget 界面上加载 QML 界面。
*/
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QQuickWidget *view = new QQuickWidget;
    view->setSource(QUrl::fromLocalFile("method2.qml"));
    view->show();

    return app.exec();
}

#elif 0

/*
* Call QML : Method 2
* 使用 QQuickView 显示 QML 文件，对窗口的控制权（标题、窗口尺寸）是在 C++代码中，QML 文件是以 Item （及 以Item为根的组件）作为根对象。
*/
int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl(QStringLiteral("qrc:/method2.qml")));
    view->show();

    return app.exec();
}

#elif 1
/*
* Call QML : Method 1
* 这种方式是加载以 Window为跟对象的 QML 文件，QML 拥有窗口的完整控制权，可以直接设置标题、窗口尺寸等属性。
*/

/*
* Find Sub Object by Function
* Param : objectName
* Method : From QObject
*/
QObject * FindSubObjectByObjectName(QObject * objParent,QString qstr){
    QObject * objSub = objParent->findChild<QObject*>(qstr);
    if(objSub)
        qDebug() << "PName:" << objParent->objectName() << "SName:" << objSub->objectName() << endl;
    return objSub;
}

int main(int argc, char *argv[]) {
    //For Debugging
    QQmlDebuggingEnabler enabler;
    //
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    if (engine.rootObjects().isEmpty()) return -1;
    QQuickWindow * rootWindow = (QQuickWindow *)engine.rootObjects().first();
    if (rootWindow) {
        rootWindow->setProperty("width", 1024);
        rootWindow->setProperty("height", 768);
    }
    QObject * qmlObjectParent = Q_NULLPTR;
    QObject * qmlObjectSub = Q_NULLPTR;
    //Find Root
    QObject* rootObject = engine.rootObjects().first();
    //Find Sub1
    qmlObjectSub = FindSubObjectByObjectName(rootObject, "objRect1");
    if (Q_NULLPTR == qmlObjectSub)
        return -1;
    //Find Sub2
    qmlObjectParent = qmlObjectSub;
    qmlObjectSub = FindSubObjectByObjectName(qmlObjectParent, "objButton1");
    if (Q_NULLPTR == qmlObjectSub)
        return -1;
/*
    QPushButton * btn = (QPushButton *) qmlObjectSub;
    if (btn)
        btn->setProperty("text", "textNew3");
*/
    return app.exec();
}

#elif 0
/*
* Find Sub Object(Button) by objectName
* Method : From QQuickWindow
*/
int main(int argc, char *argv[]){
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    if (engine.rootObjects().isEmpty()) return -1;
    QQuickWindow * rootWindow = (QQuickWindow *)engine.rootObjects().first();
    if (rootWindow) {
        rootWindow->setProperty("width", 1024);
        rootWindow->setProperty("height", 768);
    }
    QObject * btn = Q_NULLPTR;
    auto list = rootWindow->contentItem()->childItems();
    for (QQuickItem *item : list) {
        qDebug() << item->objectName() << endl;
        if (item->objectName() == "objButton1") {
            qDebug() << "Found the button";
            btn = item;
        }
        if (btn) break;
    }
    if(btn)
        btn->setProperty("text", "textNew1");

    return app.exec();
}

#elif 0
/*
* Find Sub Object by objectName
* Method : From QObject
*/
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    QObject* rootObject = engine.rootObjects().first();
    QObject * btn = rootObject->findChild<QObject*>("objButton1");

    btn->setProperty( "text", "textNew2" );

    return app.exec();
}

#elif 1

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}

#endif


