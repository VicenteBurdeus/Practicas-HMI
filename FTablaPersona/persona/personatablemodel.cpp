// PersonaTableModel.cpp
#include "personatablemodel.h"
#include <QPixmap>
#include <QIcon>

PersonaTableModel::PersonaTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

int PersonaTableModel::rowCount(const QModelIndex & /*parent*/) const
{
    return static_cast<int>(m_personas.size());
}

int PersonaTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return ColumnCount;
}

QVariant PersonaTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= static_cast<int>(m_personas.size()))
        return QVariant();

    const Persona &persona = m_personas.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case Nombre:
            return persona.nombre();
        case Apellidos:
            return persona.apellido();
        case Avatar:
            return QVariant(); // No mostrar texto para el avatar
        default:
            return QVariant();
        }
    } else if (role == Qt::DecorationRole && index.column() == Avatar) {
        QPixmap pixmap(persona.avatarPath());
        if (!pixmap.isNull()) {
            return QIcon(pixmap);
        }
    }

    return QVariant();
}

QVariant PersonaTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case Nombre:
            return QString("Nombre");
        case Apellidos:
            return QString("Apellido");
        case Avatar:
            return QString("Avatar");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void PersonaTableModel::addPersona(const Persona &persona)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_personas.push_back(persona);
    endInsertRows();
}

void PersonaTableModel::updatePersona(int row, const Persona &persona)
{
    if (row < 0 || row >= static_cast<int>(m_personas.size())) {
        return; // Índice no válido
    }

    m_personas[row] = persona;
    emit dataChanged(index(row, 0),
                     index(row, columnCount() - 1),
                     {Qt::DisplayRole, Qt::DecorationRole});
}

void PersonaTableModel::removePersona(int row)
{
    if (row < 0 || row >= static_cast<int>(m_personas.size())) {
        return; // Índice no válido
    }

    beginRemoveRows(QModelIndex(), row, row);
    m_personas.erase(m_personas.begin() + row);
    endRemoveRows();
}

void PersonaTableModel::clear()
{
    if (!m_personas.empty()) {
        beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
        m_personas.clear();
        endRemoveRows();
    }
}

Persona PersonaTableModel::getPersona(int row) const
{
    Q_ASSERT(row >= 0 && row < static_cast<int>(m_personas.size()));
    return m_personas.at(row);
}

//Método necesarios para la edición sobre la celda
Qt::ItemFlags PersonaTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    Qt::ItemFlags flags = Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    // Permitir edición solo en columnas específicas
    if (index.column() == Nombre || index.column() == Apellidos)
        flags |= Qt::ItemIsEditable;

    return flags;
}

bool PersonaTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Persona &persona = m_personas[index.row()];
    switch (index.column()) {
    case Nombre:
        persona.setNombre(value.toString());
        break;
    case Apellidos:
        persona.setApellidos(value.toString());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

