#include "mymodel.h"

#include <QByteArray>
#include <QTimer>
#include <cstdlib>

MyModel::MyModel(QObject *parent) : QAbstractListModel(parent) {
  _Song << Song("STAY", "qrc:/Src/Image_Tracklist/unnamed.jpg", "Justen Bieber",
                5, 2016)
        << Song("BABY", "qrc:/Src/Image_Tracklist/unnamed.jpg", "Justen Bieber",
                60, 2022)
        << Song("Love YourSeft", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                "Justen Bieber", 250, 2021)
        << Song("Boyfriend", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                "Justen Bieber", 240, 2017)
        << Song("Yummy", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                "Justen Bieber", 239, 2019)
        << Song("Beaty and A Beat", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                "Justen Bieber", 258, 2010)
        << Song("Sorry", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                "Justen Bieber", 231, 2016)
        << Song("Ice Cave II", "qrc:/Src/Image_Tracklist/image 14.png",
                "Lebanon Hanover", 174, 2009)
        << Song("My Pride", "qrc:/Src/Image_Tracklist/image 15.png",
                "Sydney Valette", 260, 2018)
        << Song("BUTTERFLY EFFECT", "qrc:/Src/Image_Tracklist/image 16.png",
                "Travis Scott", 264, 2018)
        << Song("Milk it", "qrc:/Src/Image_Tracklist/image 17.png", "Nirvana",
                235, 1993)
        << Song("122 Days", "qrc:/Src/Image_Tracklist/image 18.png",
                "$uicideBoy", 275, 2018)
        << Song("Courtship Dating", "qrc:/Src/Image_Tracklist/image 19.png",
                "Crystal Castles", 370, 2018)
        << Song("No Surprises", "qrc:/Src/Image_Tracklist/image 22.png",
                "Radiohead", 230, 1997)
        << Song("Other Slide", "qrc:/Src/Image_Tracklist/image 6.png",
                "Sydney Valette", 204, 2016)
        << Song("Dunkelheit", "qrc:/Src/Image_Tracklist/image 8.png", "Burzum",
                420, 1996)
        << Song("Suffocation", "qrc:/Src/Image_Tracklist/image 9.png",
                "Crystal Castles", 221, 1996)
        << Song("Tony Tone", "qrc:/Src/Image_Tracklist/image 9.png",
                "A$AP Rocky", 275, 2018);
}

Song MyModel::getSong(int i) { return _Song[i]; }
QHash<int, QByteArray> MyModel::roleNames() const {
  static QHash<int, QByteArray> mapping{{_nameRole, "name"},
                                        {_imageRole, "image"},
                                        {_authorRole, "author"},
                                        {_timeRole, "time"},
                                        {_yearRole, "year"}};
  return mapping;
}
int MyModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid())
    return 0;

  return _Song.count();
}

QVariant MyModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  const Song &data = _Song.at(index.row());
  if (role == _nameRole) {
    return data._name;
  } else if (role == _imageRole) {
    return data._image;
  } else if (role == _authorRole) {
    return data._author;
  } else if (role == _timeRole) {
    return data._time;
  } else if (role == _yearRole) {
    return data._year;
  } else
    return QVariant();
}
