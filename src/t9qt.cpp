#include "t9qt.hpp"

#include "drawingarea.hpp"

#include <QSizePolicy>

MainWindow::MainWindow()
{
	setObjectName("MainWindow");
	setWindowTitle("T9QT");

	QWidget *win = new QWidget();

	QPushButton *circleBtn = new QPushButton("Circle");
	QPushButton *rectBtn = new QPushButton("Rectangle");
	QPushButton *triangleBtn = new QPushButton("Triangle");
	QPushButton *hexagonBtn = new QPushButton("Hexagon");
	QPushButton *pentagonBtn = new QPushButton("Pentagon");
	
	QSlider *slider = new QSlider(Qt::Vertical);
	slider->setValue(150);
	slider->setMinimum(50);
	slider->setMaximum(250);
	slider->setTickInterval(10);

	QBrush brush(Qt::red, Qt::SolidPattern);
	QPen pen(brush, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
	QSizeF size(150, 150);

	DrawingArea *area = new DrawingArea(brush, pen, size, DrawingArea::Hexagon);
	area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	this->area = area;

	QHBoxLayout *layout = new QHBoxLayout();

	QVBoxLayout *buttonsLayout = new QVBoxLayout();
	buttonsLayout->addWidget(circleBtn);
	buttonsLayout->addWidget(rectBtn);
	buttonsLayout->addWidget(triangleBtn);
	buttonsLayout->addWidget(hexagonBtn);
	buttonsLayout->addWidget(pentagonBtn);

	QHBoxLayout *sidebarLayout = new QHBoxLayout();
	sidebarLayout->addWidget(slider);
	sidebarLayout->addLayout(buttonsLayout);

	connect(slider, &QAbstractSlider::valueChanged, this, [=](int value) {
		area->setSize(QSizeF(value, value));
	});

	connect(circleBtn, &QPushButton::clicked, this, [=]() {
		area->setShape(DrawingArea::Circle);
	});

	connect(rectBtn, &QPushButton::clicked, this, [=]() {
		area->setShape(DrawingArea::Rectangle);
	});
	connect(triangleBtn, &QPushButton::clicked, this, [=]() {
		area->setShape(DrawingArea::Triangle);
	});
	connect(hexagonBtn, &QPushButton::clicked, this, [=]() {
		area->setShape(DrawingArea::Hexagon);
	});
	connect(pentagonBtn, &QPushButton::clicked, this, [=]() {
		area->setShape(DrawingArea::Pentagon);
	});

	layout->addWidget(area);
	layout->addLayout(sidebarLayout);

	win->setLayout(layout);

	setCentralWidget(win);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow mwin;
	mwin.show();

	return app.exec();
}
