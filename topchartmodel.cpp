#include "topchartmodel.h"
#include <QByteArray>
#include <QTimer>
#include <cstdlib>
TopChartModel::TopChartModel(QObject *parent) : QAbstractListModel(parent) {
  _Album << Album("STAY", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2016)
         << Album("BABY", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2022)
         << Album("Love YourSeft", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2021)
         << Album("Boyfriend", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2017)
         << Album("Yummy", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2019)
         << Album("Beaty and A Beat", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2010)
         << Album("Sorry", "qrc:/Src/Image_Tracklist/unnamed.jpg",
                  "Justen Bieber", 2016)
         << Album("Ice Cave II", "qrc:/Src/Image_Tracklist/image 14.png",
                  "Lebanon Hanover", 2009)
         << Album("My Pride", "qrc:/Src/Image_Tracklist/image 15.png",
                  "Sydney Valette", 2018)
         << Album("BUTTERFLY EFFECT", "qrc:/Src/Image_Tracklist/image 16.png",
                  "Travis Scott", 2018)
         << Album("Milk it", "qrc:/Src/Image_Tracklist/image 17.png", "Nirvana",
                  1993)
         << Album("122 Days", "qrc:/Src/Image_Tracklist/image 18.png",
                  "$uicideBoy", 2018)
         << Album("Courtship Dating", "qrc:/Src/Image_Tracklist/image 19.png",
                  "Crystal Castles", 2018)
         << Album("No Surprises", "qrc:/Src/Image_Tracklist/image 22.png",
                  "Radiohead", 1997)
         << Album("Other Slide", "qrc:/Src/Image_Tracklist/image 6.png",
                  "Sydney Valette", 2016)
         << Album("Dunkelheit", "qrc:/Src/Image_Tracklist/image 8.png",
                  "Burzum", 1996)
         << Album("Suffocation", "qrc:/Src/Image_Tracklist/image 9.png",
                  "Crystal Castles", 1996)
         << Album("Tony Tone", "qrc:/Src/Image_Tracklist/image 9.png",
                  "A$AP Rocky", 2018);
}
QHash<int, QByteArray> TopChartModel::roleNames() const {
  static QHash<int, QByteArray> mapping{{_nameRole, "name"},
                                        {_imageRole, "image"},
                                        {_authorRole, "author"},
                                        {_yearRole, "year"}};
  return mapping;
}
int TopChartModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid())
    return 0;

  return _Album.count();
}

QVariant TopChartModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();

  const Album &data = _Album.at(index.row());
  if (role == _nameRole) {
    return data._name;
  } else if (role == _imageRole) {
    return data._image;
  } else if (role == _authorRole) {
    return data._author;
  } else if (role == _yearRole) {
    return data._year;
  } else
    return QVariant();
}
