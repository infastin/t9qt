#pragma once

#include <QtWidgets>

#include "drawingarea.hpp"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	DrawingArea *area;
};
