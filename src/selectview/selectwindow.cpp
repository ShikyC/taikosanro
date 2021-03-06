#include <QDebug>
#include <QKeyEvent>
#include <QResizeEvent>
#include "selectwindow.h"
#include "ui_selectwindow.h"

SelectWindow::SelectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWindow)
{
    ui->setupUi(this);

    //ui->graphicsView->installEventFilter(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    canvas_ = new SelectCanvas;
    scene->addItem(canvas_);
    canvas_->grabKeyboard();

    canvas_->load();
}

SelectWindow::~SelectWindow()
{
    delete ui;
}

void SelectWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

}

void SelectWindow::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
}

void SelectWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    QRectF rect = ui->graphicsView->rect().adjusted(0,0,-10,-10);
    ui->graphicsView->setSceneRect(rect);
    canvas_->setRect(rect);
    canvas_->move(0);
}

bool SelectWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        this->keyPressEvent(dynamic_cast<QKeyEvent*>(event));
        return true;
    }
    else
    {
        return QWidget::eventFilter(obj,event);
    }
}
