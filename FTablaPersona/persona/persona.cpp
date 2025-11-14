#include "persona.h"

Persona::Persona(const QString &nombre, const QString &apellido, const QString &avatarPath)
    : m_nombre(nombre), m_apellido(apellido), m_avatarPath(avatarPath) {}

QString Persona::nombre() const {
    return m_nombre;
}

QString Persona::apellido() const {
    return m_apellido;
}

QString Persona::avatarPath() const {
    return m_avatarPath;
}
// Setters
void Persona::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}

void Persona::setApellidos(const QString &apellidos)
{
    m_apellido = apellidos;
}

void Persona::setAvatarPath(const QString &path)
{
    m_avatarPath = path;
}

