#ifndef SELECTCANVAS_H
#define SELECTCANVAS_H

#include <QGraphicsObject>
#include <QList>
#include "selectitem.h"

class SelectCanvas : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit SelectCanvas(QGraphicsItem *parent = 0);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);

    void setRect(const QRectF &rect){rect_ = rect;}

    SelectItem *addItem();
    SelectItem *itemAt(int index);

    void move(int step);
    void expand();
    void collapse();

signals:

public slots:
    void moveFinished();
private:
    QRectF rect_;
    QList<SelectItem*> items_;
    int current_;
};

#endif // SELECTCANVAS_H
