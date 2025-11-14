#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include "persona/personatablemodel.h"

namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr);
    ~TableWindow();

private:
    Ui::TableWindow *ui;
    PersonaTableModel *tableModelP;

private slots:
    void onAddClicked();
    void onDeleteClicked();
    void onUpdateClicked();
    void onClearAllClicked();
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // TABLEWINDOW_H
