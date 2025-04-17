#include "modelphotoemploye.h"
#include <QPixmap>
#include <QPainter>

ModelPhotoEmploye::ModelPhotoEmploye(QObject *parent) : QStyledItemDelegate(parent) {}

void ModelPhotoEmploye::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 7) { // Colonne PHOTO (ajustez selon votre modèle)
        QByteArray imageData = index.data(Qt::DisplayRole).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        if (!pixmap.isNull()) {
            // Style amélioré avec bordure
            painter->save();
            painter->setRenderHint(QPainter::SmoothPixmapTransform, true);

            // Dessine un cadre arrondi
            QRect adjustedRect = option.rect.adjusted(2, 2, -2, -2);
            painter->setPen(Qt::lightGray);
            painter->setBrush(Qt::white);
            painter->drawRoundedRect(adjustedRect, 5, 5);

            // Dessine l'image centrée
            QPixmap scaled = pixmap.scaled(adjustedRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            QPoint center = adjustedRect.center() - scaled.rect().center();
            painter->drawPixmap(center, scaled);

            painter->restore();
        } else {
            QStyledItemDelegate::paint(painter, option, index);
        }
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize ModelPhotoEmploye::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 7) {
        return QSize(80, 80); // Taille optimisée pour les photos
    }
    return QStyledItemDelegate::sizeHint(option, index);
}
