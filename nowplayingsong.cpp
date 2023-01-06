#include "nowplayingsong.h"

NowPlayingSong::NowPlayingSong(QObject *parent) : QObject{parent} {
  _Play = 0;
  CurrentSong("", "", "", "");
  m_Timer = new QTimer(this);
  connect(m_Timer, &QTimer::timeout, this, &NowPlayingSong::wTimeout);
}

QString NowPlayingSong::imageNowPlayingSong() { return _currentSong._image; }

QString NowPlayingSong::nameNowPlayingSong() { return _currentSong._name; }

QString NowPlayingSong::authorNowPlayingSong() { return _currentSong._author; }

QString NowPlayingSong::timeNowPlayingSong() { return _currentSong._time; }

int NowPlayingSong::durationNowPlayingSong() {
  // qDebug() << _currentSong._duration;
  return _currentSong._duration;
}
int NowPlayingSong::timeIntNowPlayingSong() { return _currentSong._timeInt; }
QString NowPlayingSong::durantionQStringNowPlayingSong() {
  return _currentSong._durationQString;
}
bool NowPlayingSong::playStateNowPlayingSong() {
  qDebug() << _Play;
  return _Play;
}
void NowPlayingSong::play() {
  start();
  // qDebug() << _currentSong._duration;
}

void NowPlayingSong::next(QString name, QString image, QString author,
                          QString time, int duration) {
  _currentSong._name = name;
  _currentSong._author = author;
  _currentSong._image = image;
  _currentSong._time = time;
  _currentSong._duration = duration;
}
void NowPlayingSong::previous() {}
void NowPlayingSong::start() {
  // qDebug() << _currentSong._duration;
  m_Timer->start(1000);
}
void NowPlayingSong::wTimeout() {
  qDebug() << _currentSong._duration;
  if (_Play == true) {
    if (_currentSong._duration > 0) {
      _currentSong._duration--;
      QTime n(0, 0, 0);
      _currentSong._durationQString =
          n.addSecs(_currentSong._timeInt - _currentSong._duration)
              .toString("mm:ss");
      emit durationNowPlayingSongChanged();
    } else if (_currentSong._duration == 0) {
    }
  }
}
void NowPlayingSong::setImageNowPlayingSong(QString other) {
  if (other != _currentSong._image) {
    _currentSong._image = other;
    emit imageNowPlayingSongChanged();
  }
  qDebug() << "Image: " << _currentSong._image;
}
void NowPlayingSong::setNameNowPlayingSong(QString other) {
  if (other != _currentSong._name) {
    _currentSong._name = other;
    emit nameNowPlayingSongChanged();
  }
  qDebug() << "Name: " << _currentSong._name;
}
void NowPlayingSong::setAuthorNowPlayingSong(QString other) {
  if (other != _currentSong._author) {
    _currentSong._author = other;
    emit authorNowPlayingSongChanged();
  }
  qDebug() << "Author: " << _currentSong._author;
}
void NowPlayingSong::setTimeNowPlayingSong(QString other) {
  if (other != _currentSong._time) {
    _currentSong._time = other;
    QTime time = QTime::fromString(other, "mm:ss");
    _currentSong._duration = time.minute() * 60 + time.second();
    _currentSong._timeInt = time.minute() * 60 + time.second();
    emit timeNowPlayingSongChanged();
  }
  qDebug() << "Time: " << _currentSong._time;
}
void NowPlayingSong::setPlayStateNowPlayingSong(bool other) {
  if (other != _Play) {
    _Play = other;
    emit playStateNowPlayingSongChanged();
  }
}

void NowPlayingSong::setDurationNowPlayingSong(int other) {
  _currentSong._duration = _currentSong._timeInt - other;
  // emit durationNowPlayingSongChanged();
}
