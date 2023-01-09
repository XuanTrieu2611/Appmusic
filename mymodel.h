#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QDebug>
#include <QTime>
struct Song {
  Song() {}
  Song(QString name, QString image, QString author, int time, int year)
      : _name(name), _image(image), _author(author), _year(year) {
    QTime n(0, 0, 0);
    _time = n.addSecs(time).toString("mm:ss");
  }

  QString _name;
  QString _image;
  QString _author;
  QString _time;
  int _year;
};

class MyModel : public QAbstractListModel {
  Q_OBJECT
public:
  enum Roles {
    _nameRole = Qt::UserRole,
    _imageRole,
    _authorRole,
    _timeRole,
    _yearRole
  };

  Q_INVOKABLE void setCurrentSong(int position);
  Q_INVOKABLE void setCurrentSongNextButton();
  Q_INVOKABLE void setCurrentSongPreviousButton();
  Q_INVOKABLE QString getNameSong(int position);
  Q_INVOKABLE QString getImageSong(int position);
  Q_INVOKABLE QString getAuthorSong(int position);
  Q_INVOKABLE QString getTimeSong(int position);
  explicit MyModel(QObject *parent = nullptr);
  Song getSong(int i);
  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

public slots:

private slots:

private: // members
  QVector<Song> _Song;
  Song _nextSong;
  Song _currentSong;
  Song _previousSong;
  int _position;
};

#endif // MYMODEL_H
