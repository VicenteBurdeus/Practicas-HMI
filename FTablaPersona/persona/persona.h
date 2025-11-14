#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QPixmap>

class Persona {
public:
    Persona(const QString &nombre, const QString &apellido, const QString &avatarPath);
    QString nombre() const;
    QString apellido() const;
    QString avatarPath() const;  // Nuevo método para obtener el path del avatar
    // Métodos Setter
    void setNombre(const QString &nombre);
    void setApellidos(const QString &apellidos);
    void setAvatarPath(const QString &path);


private:
    QString m_nombre;
    QString m_apellido;
    QString m_avatarPath;
};

#endif // PERSONA_H
