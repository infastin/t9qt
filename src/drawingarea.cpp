#include "drawingarea.hpp"

#include <iostream>
#include <cmath>

void DrawingArea::setPen(const QPen &pen)
{
	this->pen = pen;
	update();
}

void DrawingArea::setBrush(const QBrush &brush)
{
	this->brush = brush;
	update();
}

void DrawingArea::setShape(Shape shape)
{
	this->shape = shape;
	update();
}

void DrawingArea::setSize(const QSizeF &size)
{
	this->size = size;
	update();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setPen(pen);
	painter.setBrush(brush);

	qreal halfWidth = ((qreal) width()) / 2;
	qreal halfHeight = ((qreal) height()) / 2;

	qreal halfSizeWidth = size.width() / 2;
	qreal halfSizeHeight = size.height() / 2;

	switch (shape)
	{
		case Circle:
		{
			QPointF center = {
				halfWidth,
				halfHeight,
			};

			painter.drawEllipse(center, halfSizeWidth, halfSizeHeight);
		}
		break;
		case Rectangle:
		{
			QRectF rect = {
				halfWidth - halfSizeWidth,
				halfHeight - halfSizeHeight,
				size.width(),
				size.height(),
			};

			painter.drawRect(rect);
		}
		break;
		case Triangle:
		{
			QPointF triangle[3] = {
				QPointF(halfWidth - halfSizeWidth, halfHeight + halfSizeHeight),
				QPointF(halfWidth, halfHeight - halfSizeHeight),
				QPointF(halfWidth + halfSizeWidth, halfHeight + halfSizeHeight),
			};

			painter.drawPolygon(triangle, 3);
		}
		break;
		case Hexagon:
		{
			qreal w = halfSizeWidth - (halfSizeHeight * tan(M_PI/6));

			QPointF hexagon[6] = {
				QPointF(halfWidth - halfSizeWidth, halfHeight),
				QPointF(halfWidth - w, halfHeight - halfSizeHeight),
				QPointF(halfWidth + w, halfHeight - halfSizeHeight),
				QPointF(halfWidth + halfSizeWidth, halfHeight),
				QPointF(halfWidth + w, halfHeight + halfSizeHeight),
				QPointF(halfWidth - w, halfHeight + halfSizeHeight),
			};

			painter.drawPolygon(hexagon, 6);
		}
		break;
		case Pentagon:
		{
			qreal w = halfSizeWidth - (halfSizeHeight * tan(M_PI/10));

			QPointF pentagon[5] = {
				QPointF(halfWidth - halfSizeWidth, halfHeight),
				QPointF(halfWidth, halfHeight - halfSizeHeight),
				QPointF(halfWidth + halfSizeWidth, halfHeight),
				QPointF(halfWidth + w, halfHeight + halfSizeHeight),
				QPointF(halfWidth - w, halfHeight + halfSizeHeight),
			};

			painter.drawPolygon(pentagon, 5);
		}
		break;
		default:
			return;
	}
}
