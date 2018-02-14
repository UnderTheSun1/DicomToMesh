/****************************************************************************
** Copyright (c) 2017 Adrian Schneider, AOT AG
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
**
*****************************************************************************/


#ifndef WIDGET_H
#define WIDGET_H
 
#include <QWidget>
#include <vtkObject.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
 
namespace Ui {
    class D2MWidget;
}
 
class D2MWidget : public QWidget
{
    Q_OBJECT
 
public:
    explicit D2MWidget(QWidget *parent = 0);
    ~D2MWidget();

    static void progressCallback(vtkObject* caller, long unsigned int eventId, void* clientData, void* callData);

public slots:
    void openDicomBtn();
    void saveBtn();
    void runBtn();

private:
    vtkSmartPointer<vtkPolyData> loadInputData( const std::string& path, const int& threshold, vtkSmartPointer<vtkCallbackCommand> progressCallback, bool& successful );


private:
    Ui::D2MWidget *ui;

    std::string m_dicom_path;
    std::string m_mesh_path;

};

 
#endif // WIDGET_H