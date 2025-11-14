// PersonaTableModel.h
#ifndef PERSONATABLEMODEL_H
#define PERSONATABLEMODEL_H

#include <QAbstractTableModel>
#include "Persona.h"
#include <vector>

class PersonaTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PersonaTableModel(QObject *parent = nullptr);

    // Métodos sobrescritos de QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    //Métodos que permiten la edición sobre la celda
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    // Métodos para manipular los datos
    void addPersona(const Persona &persona);
    void updatePersona(int row, const Persona &persona);
    void removePersona(int row);
    void clear();
    // Método adicional para obtener una persona específica
    Persona getPersona(int row) const;

private:
    std::vector<Persona> m_personas;

    enum Column {
        Nombre = 0,
        Apellidos,
        Avatar,
        ColumnCount // Número total de columnas
    };
};

#endif // PERSONATABLEMODEL_H
