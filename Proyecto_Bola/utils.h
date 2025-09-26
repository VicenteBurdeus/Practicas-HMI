#ifndef UTILS_H
#define UTILS_H

#include <QPainter>
#include <QRect>
#include <QSize>
#include <QtMath>

namespace Utils {

// Asegura ratio en [0,1]
inline qreal clamp01(qreal v) { return v < 0 ? 0 : (v > 1 ? 1 : v); }

// Tamaño de celda (entero)
inline QSize cellSize(const QRect &area, const QSize &gridSize) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    return (cols > 0 && rows > 0)
               ? QSize(area.width() / cols, area.height() / rows)
               : QSize(0, 0);
}

// Rect de una celda (coordenadas de ventana)
inline QRect cellRect(const QRect &area, const QSize &gridSize, int row, int col) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) return QRect();

    const int cw = area.width()  / cols;
    const int ch = area.height() / rows;

    const int x = area.left() + col * cw;
    const int y = area.top()  + row * ch;
    return QRect(x, y, cw, ch);
}

// Dibuja la cuadrícula en coordenadas de ventana
inline void drawGrid(const QRect &area, const QSize &gridSize, QPainter &painter) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) return;

    const int cw = area.width()  / cols;
    const int ch = area.height() / rows;

    painter.save();
    painter.setRenderHint(QPainter::Antialiasing, false); // líneas nítidas

    // Para un pen de 1px, alinear a la malla de píxel puede ayudar:
    // (Descomenta si ves líneas borrosas)
    // const qreal offset = (painter.pen().width() % 2) ? 0.5 : 0.0;

    // Verticales
    for (int c = 0; c <= cols; ++c) {
        const int x = area.left() + c * cw;
        painter.drawLine(x, area.top(), x, area.top() + rows * ch);
        // painter.drawLine(x + offset, area.top(), x + offset, area.top() + rows * ch);
    }
    // Horizontales
    for (int r = 0; r <= rows; ++r) {
        const int y = area.top() + r * ch;
        painter.drawLine(area.left(), y, area.left() + cols * cw, y);
        // painter.drawLine(area.left(), y + offset, area.left() + cols * cw, y + offset);
    }

    painter.restore();
}

// Dibuja un círculo centrado en la celda (row,col)
inline void drawCircleCell(const QRect &area,
                           const QSize &gridSize,
                           QPainter &painter,
                           const QPoint &cellRC,      // y=row, x=col
                           qreal diameterRatio) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) return;

    const int cw = area.width()  / cols;
    const int ch = area.height() / rows;

    diameterRatio = clamp01(diameterRatio);
    const int diameter = qMin(cw, ch) * diameterRatio;

    const int row = cellRC.y();
    const int col = cellRC.x();

    QRect rc = cellRect(area, gridSize, row, col);
    const int x = rc.x() + (rc.width()  - diameter) / 2;
    const int y = rc.y() + (rc.height() - diameter) / 2;

    painter.drawEllipse(x, y, diameter, diameter);
}

// Dibuja un círculo centrado en una posición de ventana
inline void drawCircle(const QRect & /*area*/,
                       const QSize &gridSize,
                       QPainter &painter,
                       const QPoint &posWindow,  // coordenadas de ventana
                       qreal diameterRatio) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) return;

    // Aproximamos el tamaño de celda medio para el diámetro
    // (si necesitas exactitud por celda, usa drawCircleCell)
    const int cw = 1; // neutral (no se usa para posicionar)
    Q_UNUSED(cw);
    Q_UNUSED(cols); Q_UNUSED(rows);

    // Este diámetro se decide fuera si quieres independizarte del grid;
    // si quieres basarte en celdas, pásalo por parámetro o calcula sobre cellRect(...)
    // Aquí asumimos que el que llama ya configuró pen/brush.
    Q_UNUSED(gridSize);

    // Para esta utilidad simple calculamos diámetro con el menor lado
    // del área total dividido por  min(cols,rows). Si prefieres, elimina y
    // delega el diámetro al llamador.
    diameterRatio = clamp01(diameterRatio);

    painter.drawEllipse(QPoint(posWindow.x(), posWindow.y()),
                        int(painter.pen().widthF() + 0), int(painter.pen().widthF() + 0));
    // Nota: normalmente preferirás drawCircleCell para la práctica con celdas.
}

// Actualiza posición (row,col) con envoltura
inline void updatePosition(const QSize &gridSize, QPoint &cellRC, int dRow, int dCol) {
    const int rows = gridSize.height();
    const int cols = gridSize.width();
    if (cols <= 0 || rows <= 0) return;

    cellRC.setY((cellRC.y() + dRow + rows) % rows);
    cellRC.setX((cellRC.x() + dCol + cols) % cols);
}

// ¿Está un punto de ventana dentro del círculo de la celda (row,col)?
inline bool isPosInsideCircle(const QPoint &posWindow,
                              const QRect &area,
                              const QSize &gridSize,
                              const QPoint &cellRC,
                              qreal diameterRatio) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) return false;

    const int cw = area.width()  / cols;
    const int ch = area.height() / rows;

    diameterRatio = clamp01(diameterRatio);
    const qreal diameter = qreal(qMin(cw, ch)) * diameterRatio;

    // Centro del círculo en coords de ventana
    QRect rc = cellRect(area, gridSize, cellRC.y(), cellRC.x());
    const qreal cx = rc.center().x();
    const qreal cy = rc.center().y();

    const qreal dx = posWindow.x() - cx;
    const qreal dy = posWindow.y() - cy;
    const qreal dist2 = dx*dx + dy*dy;
    const qreal r = diameter / 2.0;

    return dist2 <= r*r;
}

// Obtiene (row,col) desde un punto en coords de ventana
inline bool getCellFromPosition(const QPoint &posWindow,
                                const QRect &area,
                                const QSize &gridSize,
                                int &row, int &col) {
    const int cols = gridSize.width();
    const int rows = gridSize.height();
    if (cols <= 0 || rows <= 0) { row = col = -1; return false; }

    if (!area.contains(posWindow)) { row = col = -1; return false; }

    const int cw = area.width()  / cols;
    const int ch = area.height() / rows;

    const int localX = posWindow.x() - area.x();
    const int localY = posWindow.y() - area.y();

    row = localY / ch;
    col = localX / cw;

    // Clamp por si el punto cae en el borde derecho/inferior
    if (row >= rows) row = rows - 1;
    if (col >= cols) col = cols - 1;
    return true;
}

} // namespace Utils
#endif // UTILS_H
