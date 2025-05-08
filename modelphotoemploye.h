#ifndef MODELPHOTOEMPLOYE_H
#define MODELPHOTOEMPLOYE_H

#include <QStyledItemDelegate>

class ModelPhotoEmploye : public QStyledItemDelegate
{
public:
    ModelPhotoEmploye(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // MODELPHOTOEMPLOYE_H
