#include "personadelegate.h"
#include <QApplication>
#include <QPixmap>
#include <QStyle>
#include"personatablemodel.h"

PersonaDelegate::PersonaDelegate(QObject *parent)
    : QStyledItemDelegate(parent) {}

void PersonaDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->save();

    // Obtener la persona de la celda
    Persona p=((PersonaTableModel*)(index.model()))->getPersona(index.row());

    // Configurar el área de dibujo
    QRect rect = option.rect;
    int iconSize = 20;  // Tamaño del icono

    // Dibuja el nombre a la izquierda + 5 pixeles
    QRect textRect = rect;
    textRect.setX(rect.x() + 5);
    textRect.setWidth(rect.width() - iconSize - 10); // Reserva espacio para el icono
    painter->drawText(textRect, Qt::AlignVCenter, p.apellido() + ", "+p.nombre());

    // Dibuja el icono a la derecha -5 pixeles
    QPixmap avatar(p.avatarPath());
    QRect iconRect = rect;
    iconRect.setX(rect.right() - (iconSize + 5));
    iconRect.setY(rect.y() + 5);
    iconRect.setWidth(iconSize);
    iconRect.setHeight(iconSize);
    painter->drawPixmap(iconRect, avatar);

    painter->restore();
}

QSize PersonaDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index);
    return QSize(option.rect.width(), 30); // Altura fija, ancho automático
}
