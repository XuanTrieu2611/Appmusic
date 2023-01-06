#ifndef TOPCHARTMODEL_H
#define TOPCHARTMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QDebug>
#include <QTime>
struct Album {
  Album() {}
  Album(QString name, QString image, QString author, int year)
      : _name(name), _image(image), _author(author), _year(year) {}
  QString _name;
  QString _image;
  QString _author;
  int _year;
};
class TopChartModel : public QAbstractListModel {
  Q_OBJECT

public:
  enum Roles { _nameRole = Qt::UserRole, _imageRole, _authorRole, _yearRole };

  explicit TopChartModel(QObject *parent = nullptr);

  int rowCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;
public slots:

private slots:

private: // members
  QVector<Album> _Album;
};

#endif // TOPCHARTMODEL_H
