#include "mayyoulikemodel.h"
#include "mymodel.h"
#include "nowplayingsong.h"
#include "topchartmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView>
#include <QStringListModel>
int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);
  MyModel playnextmodel;
  TopChartModel topchartmodel;
  MayYouLikeModel mayyoulikemodel;
  NowPlayingSong nowplay;

  QQmlApplicationEngine engine;
  QQmlContext *context = engine.rootContext();
  context->setContextProperty("playnextmodel", &playnextmodel);
  context->setContextProperty("topchartmodel", &topchartmodel);
  context->setContextProperty("mayyoulikemodel", &mayyoulikemodel);
  context->setContextProperty("nowplay", &nowplay);
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);
  return app.exec();
}
