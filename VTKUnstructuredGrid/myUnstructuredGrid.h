#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VTKUnstructuredGrid.h"

#include <QVTKOpenGLNativeWidget.h>

class myUnstructuredGrid : public QMainWindow
{
	Q_OBJECT

public:
	myUnstructuredGrid(QWidget* parent = nullptr);
	~myUnstructuredGrid();

private:
	Ui::VTKUnstructuredGridClass ui;

	QVTKOpenGLNativeWidget* _pVTKWidget = nullptr;
};
