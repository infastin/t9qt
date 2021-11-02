#pragma once

#include <QtWidgets>

class DrawingArea : public QWidget
{
	Q_OBJECT

public:
	enum Shape
	{
		Circle,
		Rectangle,
		Triangle,
		Hexagon,
		Pentagon,
	};

	DrawingArea(QWidget *parent = nullptr)
		: QWidget(parent)
	{}
	DrawingArea(const QBrush &_brush, const QPen &_pen, const QSizeF &_size, Shape _shape = Circle, QWidget *parent = nullptr)
		: QWidget(parent)
		, shape(_shape)
		, brush(_brush)
		, pen(_pen)
		, size(_size)
	{}

public slots:
	void setPen(const QPen &pen);
	void setBrush(const QBrush &brush);
	void setShape(Shape shape);
	void setSize(const QSizeF &size);

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	Shape shape;
	QBrush brush;
	QPen pen;
	QSizeF size;
};
