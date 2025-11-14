#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "iconcombobox.h"
#include "personatablemodel.h"

#include <QItemSelection>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onDeleteClicked();
    void onClearAllClicked();
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void acercaDe();

private:
    Ui::MainWindow *ui;
    PersonaTableModel *listModelP;

    void clearFields();
};
#endif // MAINWINDOW_H
