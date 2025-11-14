#include "dialogpersona.h"
#include "ui_dialogpersona.h"
#include <qpushbutton.h>
#include <QFile>

DialogPersona::DialogPersona(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPersona)
{
    ui->setupUi(this);
    // inicializar comboBox
    ui->comboBox->addIconItem(":/images/Lloroso.png");
    ui->comboBox->addIconItem(":/images/Pregunta.png");
    ui->comboBox->addIconItem(":/images/Sonriente.png");
    ui->comboBox->setCurrentIndex(-1);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogPersona::pushButtonClicked);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DialogPersona::reject);

    this->setWindowTitle("Añadir persona");
    aplicarEstilos();
}
DialogPersona::DialogPersona(const Persona &persona, QWidget *parent)
    : DialogPersona(parent) // Delegar al primer constructor
{
    // Después de delegar, inicializar los campos con la persona
    p = new Persona(persona);
    ui->nameEdit->setText(p->nombre());
    ui->lastNameEdit->setText(p->apellido());
    ui->comboBox->setCurrentIcon(p->avatarPath());
    this->setWindowTitle("Modificar persona");
}

DialogPersona::~DialogPersona()
{
    delete ui;
}
void DialogPersona::pushButtonClicked()
{
    if (p == nullptr) {
        p = new Persona("", "", "");
    }
    p->setApellidos(ui->lastNameEdit->text());
    p->setNombre(ui->nameEdit->text());
    p->setAvatarPath(ui->comboBox->selectedIconName());
    emit dataAvalaible(*p);
    accept();
}
void DialogPersona::aplicarEstilos()
{
    QFile file(":/estilos/estilo.qss");  // La ruta del archivo de estilo
    if (file.open(QFile::ReadOnly)) {
        QString estilo = QLatin1String(file.readAll());
        this->setStyleSheet(estilo);  // Aplicar la hoja de estilo al diálogo
        file.close();
    }
}
