#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include "iconcombobox.h"
#include "personadelegate.h"
#include "personatablemodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // inicializar comboBox
    ui->comboBox->addIconItem(":/images/Lloroso.png");
    ui->comboBox->addIconItem(":/images/Pregunta.png");
    ui->comboBox->addIconItem(":/images/Sonriente.png");
    ui->comboBox->setCurrentIndex(-1);

    listModelP = new PersonaTableModel(this);
    ui->tableView->setModel(listModelP);

    // Aplica PersonaDelegate al QListView
   // PersonaDelegate *personaDelegate = new PersonaDelegate(this);
    //ui->listView->setItemDelegate(personaDelegate);

    // Deshabilitar el botón de eliminar al principio
    ui->deleteButton->setEnabled(false);

    // Conectar señales y slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearAllClicked);
    connect(ui->tableView->selectionModel(),
            &QItemSelectionModel::selectionChanged,
            this,
            &MainWindow::onSelectionChanged);
    connect(listModelP, &QAbstractItemModel::dataChanged, this, [=]() {
        clearFields();
        ui->tableView->clearSelection();
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddClicked()
{
    QString name = ui->nameEdit->text().trimmed();
    QString lastName = ui->lastNameEdit->text().trimmed();

    if (name.isEmpty() || lastName.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Por favor, introduce nombre y apellidos.");
        return;
    }
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    if (selectedIndex.isValid() && (selectedIndex.row() != -1)) {
        // Modificar el elemento seleccionado
        Persona persona = listModelP->getPersona(selectedIndex.row());

        persona.setApellidos(lastName);
        persona.setNombre(name);
        persona.setAvatarPath(ui->comboBox->selectedIconName());
        listModelP->updatePersona(selectedIndex.row(), persona);

    } else {
        // Añadir nuevo elemento
        Persona persona(name, lastName, ui->comboBox->selectedIconName());
        listModelP->addPersona(persona);
    }
    ui->tableView->selectionModel()->clearSelection();
    // Limpiar campos después de añadir o modificar
    clearFields();
}

void MainWindow::onDeleteClicked()
{
    QModelIndex selectedIndex = ui->tableView->currentIndex();
    if (selectedIndex.isValid()) {
        listModelP->removePersona(selectedIndex.row());
        ui->tableView->clearSelection();
        clearFields();
    }
}

void MainWindow::onClearAllClicked()
{
    listModelP->clear();
    clearFields();
}

void MainWindow::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList selectedIndexes = selected.indexes();
    if (!selectedIndexes.isEmpty()) {
        // Activar botón de eliminar
        ui->deleteButton->setEnabled(true);

        // Rellenar los campos con el registro seleccionado
        Persona p = listModelP->getPersona(selectedIndexes.first().row());
        ui->nameEdit->setText(p.nombre());
        ui->lastNameEdit->setText(p.apellido());
        ui->comboBox->setCurrentIcon(p.avatarPath());
    } else {
        ui->deleteButton->setEnabled(false);
    }
}
void MainWindow::clearFields()
{
    ui->nameEdit->clear();
    ui->lastNameEdit->clear();
    ui->comboBox->setCurrentIndex(-1);
}

void MainWindow::acercaDe()
{
    QMessageBox *mensaje = new QMessageBox(this);
    mensaje->setText("Grupo de prácticas IHM");
    mensaje->setModal(true);
    mensaje->show();
}

