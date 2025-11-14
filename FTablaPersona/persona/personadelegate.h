#ifndef PERSONADELEGATE_H
#define PERSONADELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class PersonaDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit PersonaDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // PERSONADELEGATE_H
