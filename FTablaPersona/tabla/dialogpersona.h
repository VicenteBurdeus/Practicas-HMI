#ifndef DIALOGPERSONA_H
#define DIALOGPERSONA_H

#include <QDialog>
#include "Persona.h"

namespace Ui {
class DialogPersona;
}

class DialogPersona : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPersona(QWidget *parent = nullptr);
    // Constructor para modificar una persona existente
    explicit DialogPersona(const Persona &persona, QWidget *parent = nullptr);
    ~DialogPersona();

private:
    Ui::DialogPersona *ui;
    Persona *p;

    void aplicarEstilos();

signals:
    void dataAvalaible(const Persona &p);

private slots:
    void pushButtonClicked();
};

#endif // DIALOGPERSONA_H
