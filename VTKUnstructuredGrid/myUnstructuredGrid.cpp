#include "myUnstructuredGrid.h"

#include <vtkHexahedron.h>
#include <vtkTetra.h>
#include <vtkPoints.h>
#include <vtkDataSet.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>

myUnstructuredGrid::myUnstructuredGrid(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_pVTKWidget = new QVTKOpenGLNativeWidget();
	this->setCentralWidget(_pVTKWidget);

	vtkNew<vtkRenderer> renderer;
	this->_pVTKWidget->renderWindow()->AddRenderer(renderer);
	this->_pVTKWidget->renderWindow()->Render();

	vtkNew<vtkPoints> hexahedronPoints;
	hexahedronPoints->SetNumberOfPoints(8);
	hexahedronPoints->InsertPoint(0, 0, 0, 0);
	hexahedronPoints->InsertPoint(1, 1, 0, 0);
	hexahedronPoints->InsertPoint(2, 1, 1, 0);
	hexahedronPoints->InsertPoint(3, 0, 1, 0);
	hexahedronPoints->InsertPoint(4, 0, 0, 1);
	hexahedronPoints->InsertPoint(5, 1, 0, 1);
	hexahedronPoints->InsertPoint(6, 1, 1, 1);
	hexahedronPoints->InsertPoint(7, 0, 1, 1);
	vtkNew<vtkHexahedron> hexahedron;
	hexahedron->GetPointIds()->SetId(0, 0);
	hexahedron->GetPointIds()->SetId(1, 1);
	hexahedron->GetPointIds()->SetId(2, 2);
	hexahedron->GetPointIds()->SetId(3, 3);
	hexahedron->GetPointIds()->SetId(4, 4);
	hexahedron->GetPointIds()->SetId(5, 5);
	hexahedron->GetPointIds()->SetId(6, 6);
	hexahedron->GetPointIds()->SetId(7, 7);
	vtkNew<vtkUnstructuredGrid> hexahedronGrid;
	hexahedronGrid->SetPoints(hexahedronPoints);
	hexahedronGrid->InsertNextCell(hexahedron->GetCellType(), hexahedron->GetPointIds());

	vtkNew<vtkPoints> tetraPoints;
	tetraPoints->SetNumberOfPoints(4);
	tetraPoints->InsertPoint(0, 0, 0, 0);
	tetraPoints->InsertPoint(1, 1, 0, 0);
	tetraPoints->InsertPoint(2, 0.5, 1, 0);
	tetraPoints->InsertPoint(3, 0.5, 0.5, 1);
	vtkNew<vtkTetra> tetra;
	tetra->GetPointIds()->SetId(0, 0);
	tetra->GetPointIds()->SetId(1, 1);
	tetra->GetPointIds()->SetId(2, 2);
	tetra->GetPointIds()->SetId(3, 3);
	vtkNew<vtkUnstructuredGrid> tetraGrid;
	tetraGrid->SetPoints(tetraPoints);
	tetraGrid->InsertNextCell(tetra->GetCellType(), tetra->GetPointIds());

	vtkNew<vtkDataSetMapper> hexahedronMapper;
	hexahedronMapper->SetInputData(hexahedronGrid);
	vtkNew<vtkDataSetMapper> tetraMapper;
	tetraMapper->SetInputData(tetraGrid);

	vtkNew<vtkActor> hexahedronActor;
	hexahedronActor->SetMapper(hexahedronMapper);
	vtkNew<vtkActor> tetraActor;
	tetraActor->SetMapper(tetraMapper);
	tetraActor->SetPosition(2, 0, 0);

	renderer->AddActor(hexahedronActor);
	renderer->AddActor(tetraActor);
}

myUnstructuredGrid::~myUnstructuredGrid()
{}
