#ifndef COLORTABLEWIDGET_H
#define COLORTABLEWIDGET_H

#include <QTableWidget>

class ColorTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit ColorTableWidget(QWidget *parent = 0);

protected:
    void dropEvent(QDropEvent *event);

signals:

public slots:

};

#endif // COLORTABLEWIDGET_H
