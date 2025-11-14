#include "tablewindow.h"
#include "tabla/dialogpersona.h"
#include "ui_tablewindow.h"

TableWindow::TableWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    tableModelP = new PersonaTableModel(this);
    ui->tableView->setModel(tableModelP);

    ui->updateButton->setDisabled(true);
    ui->deleteButton->setDisabled(true);

    connect(ui->addButton, &QPushButton::clicked, this, &TableWindow::onAddClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TableWindow::onDeleteClicked);
    connect(ui->updateButton, &QPushButton::clicked, this, &TableWindow::onUpdateClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &TableWindow::onClearAllClicked);

    connect(ui->tableView->selectionModel(),
            &QItemSelectionModel::selectionChanged,
            this,
            &TableWindow::onSelectionChanged);
}

TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::onAddClicked()
{
    ui->tableView->clearSelection();
    DialogPersona *dp = new DialogPersona(this);
    dp->show();
    connect(dp, &DialogPersona::dataAvalaible, this, [=](Persona p) {
        tableModelP->addPersona(p);
    });

}

void TableWindow::onDeleteClicked()
{
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    if (selectedIndex.isValid()) {
        tableModelP->removePersona(selectedIndex.row());
        ui->tableView->clearSelection();
    }
}

void TableWindow::onUpdateClicked()
{
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    if (selectedIndex.isValid()) {
        DialogPersona *dp = new DialogPersona(tableModelP->getPersona(selectedIndex.row()), this);
        dp->show();
        connect(dp, &DialogPersona::dataAvalaible, this, [=](Persona p) {
            tableModelP->updatePersona(selectedIndex.row(), p);
        });
    }
}

void TableWindow::onClearAllClicked()
{
    tableModelP->clear();
}

void TableWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList selectedIndexes = selected.indexes();
    if (!selectedIndexes.isEmpty()) {
        // Activar botón de eliminar y modificar
        ui->deleteButton->setEnabled(true);
        ui->updateButton->setEnabled(true);
    } else {
        ui->deleteButton->setEnabled(false);
        ui->updateButton->setEnabled(false);
    }
}
