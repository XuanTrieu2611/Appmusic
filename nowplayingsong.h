#ifndef NOWPLAYINGSONG_H
#define NOWPLAYINGSONG_H
#include "mymodel.h"
#include <QObject>
#include <QtCore>
struct CurrentSong {
  CurrentSong() {}
  CurrentSong(QString name, QString image, QString author, int time)
      : _name(name), _image(image), _author(author) {
    QTime n(0, 0, 0);
    _time = n.addSecs(time).toString("mm:ss");
  }
  CurrentSong(QString name, QString image, QString author, QString time)
      : _name(name), _image(image), _author(author), _time(time), _duration(0),
        _timeInt(0) {}
  QString _name;
  QString _image;
  QString _author;
  QString _time;
  QString _durationQString;
  int _timeInt;
  int _duration;
};

class NowPlayingSong : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString imageNowPlayingSong READ imageNowPlayingSong WRITE
                 setImageNowPlayingSong NOTIFY imageNowPlayingSongChanged)
  Q_PROPERTY(QString nameNowPlayingSong READ nameNowPlayingSong WRITE
                 setNameNowPlayingSong NOTIFY nameNowPlayingSongChanged)
  Q_PROPERTY(QString authorNowPlayingSong READ authorNowPlayingSong WRITE
                 setAuthorNowPlayingSong NOTIFY authorNowPlayingSongChanged)
  Q_PROPERTY(QString timeNowPlayingSong READ timeNowPlayingSong WRITE
                 setTimeNowPlayingSong NOTIFY timeNowPlayingSongChanged)
  Q_PROPERTY(int durationNowPlayingSong READ durationNowPlayingSong WRITE
                 setDurationNowPlayingSong NOTIFY durationNowPlayingSongChanged)
  Q_PROPERTY(int timeIntNowPlayingSong READ timeIntNowPlayingSong NOTIFY
                 timeNowPlayingSongChanged)
  Q_PROPERTY(
      QString durantionQStringNowPlayingSong READ durantionQStringNowPlayingSong
          NOTIFY durationNowPlayingSongChanged)
  Q_PROPERTY(
      bool playStateNowPlayingSong READ playStateNowPlayingSong WRITE
          setPlayStateNowPlayingSong NOTIFY playStateNowPlayingSongChanged)
public:
  explicit NowPlayingSong(QObject *parent = nullptr);

  QString imageNowPlayingSong();
  QString nameNowPlayingSong();
  QString authorNowPlayingSong();
  QString timeNowPlayingSong();
  int durationNowPlayingSong();
  int timeIntNowPlayingSong();
  QString durantionQStringNowPlayingSong();
  bool playStateNowPlayingSong();
  Q_INVOKABLE void play();
  void start();
signals:
  void imageNowPlayingSongChanged();
  void nameNowPlayingSongChanged();
  void authorNowPlayingSongChanged();
  void timeNowPlayingSongChanged();
  // void playNowPlayingSongChanged();
  void durationNowPlayingSongChanged();
  void playStateNowPlayingSongChanged();

public slots:
  void setImageNowPlayingSong(QString other);
  void setNameNowPlayingSong(QString other);
  void setAuthorNowPlayingSong(QString other);
  void setTimeNowPlayingSong(QString other);
  void setPlayStateNowPlayingSong(bool other);
  void setDurationNowPlayingSong(int other);
private slots:
  void wTimeout();

private:
  CurrentSong _currentSong;
  bool _Play;
  QTimer *m_Timer;
};

#endif // NOWPLAYINGSONG_H
