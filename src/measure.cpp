#include "measure.h"
#include <QDebug>

Measure::Measure(QGraphicsItem *parent,
                 NoteTypeList &notes,
                 qreal tempo,
                 int noteValuePerBeat,
                 int beatsPerBar)
    :QGraphicsItem(parent),
      tempo_(tempo),
      noteValuePerBeat_(noteValuePerBeat),
      beatsPerBar_(beatsPerBar)
{
    Q_ASSERT(parent != 0);

    canvasRect_ = parent->boundingRect();

    qreal noteUnit = canvasRect_.width() / notes.count();
    for(int i = notes.count() - 1;i >= 0;i--)
    {
        if(notes[i] == Note::Blank)
        {
            continue;
        }

        Note *note = new Note(notes[i],this);
        note->setPos(i * noteUnit,0);
    }
}

QRectF Measure::boundingRect() const
{
    return canvasRect_;
}

void Measure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void Measure::calcPos(int currentElapsed)
{
    qreal offset = tempo_ * currentElapsed * canvasRect_.width() / (noteValuePerBeat_ * beatsPerBar_ * 60000);

    //qDebug() << offset;
    //prepareGeometryChange();
    //canvasRect_.moveLeft(canvasRect_.width() - offset);
    setPos(canvasRect_.width() - offset,0);
}

int Measure::appearElapsed()
{
    return appearElapsed_;
}

void Measure::advance(int step)
{

}
