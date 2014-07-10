#include "colortablewidget.h"

ColorTableWidget::ColorTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
}

void ColorTableWidget::dropEvent(QDropEvent *event)
{
    if (!event->source()) {
#ifdef QT_DEBUG
        std::cout<< "WARN: attempted to drop from outside colorTable" << std::endl;
#endif
        event->ignore();
    }
/*    if (!event->mimeData()->hasFormat("text/x-color-argb")) {
#ifdef QT_DEBUG
        std::cout<< "WARN: attempted to drop non-color data into table." << std::endl;
#endif
        event->ignore();
    }*/

    QModelIndex srcField = selectedIndexes().first();
    QModelIndex destField = indexAt(event->pos());

#ifdef QT_DEBUG
    std::cout<<srcField.row()<<"\t"<<destField.row()<<std::endl;
#endif

    event->accept();
}
