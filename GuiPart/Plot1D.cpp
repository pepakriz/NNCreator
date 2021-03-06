/*
 * This file is part of Neural network Creator, backpropagation
 * simulator and multilayer neural network IDE.
 * Copyright (C) 2013  Petr Kačer <kacerpetr@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Plot1D.h"
#include <QDebug>
#include "GL/glu.h"
#include <QMenu>
#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QTextStream>
#include <QSignalMapper>
#include <QColor>
#include <QLabel>
#include <QWidgetAction>

namespace Application{

/**
 * Class constructor.
 */
Plot1D::Plot1D(QWidget *parent) :
	QGLWidget(parent),
    autorange(true),
    xrMin(-1),
    xrMax(1),
    orMin(-1),
    orMax(1),
    xMin(1E99),
    xMax(-1E99),
    oMin(1E99),
	oMax(-10000),
	leftSpace(75),
    rightSpace(25),
    topSpace(20),
    bottomSpace(45),
    xLbl(tr("X axis")),
    yLbl(tr("Y axis")),
    mdl(NULL)
{
	font.setFamily("Monospace");
	font.setBold(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu()));
    point.append(QList<Point1D>());
}

/**
 * Class constructor from string.
 */
Plot1D::Plot1D(QString data, QWidget *parent) :
    QGLWidget(parent),
    xMax(-10000),
    oMax(-10000),
    leftSpace(75),
    rightSpace(25),
    topSpace(20),
    bottomSpace(45),
    xLbl(tr("X axis")),
    yLbl(tr("Y axis"))
{
    font.setFamily("Monospace");
    font.setBold(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu()));
    fromString(data);
    point.append(QList<Point1D>());
}

/**
 * Class destructor.
 */
Plot1D::~Plot1D(){}

/**
 * Sets learning config model (optional for adding other learning plots).
 */
void Plot1D::setModel(ProjectData::LearningConfigModel* model){
    mdl = model;
}

/**
 * Creates and shows context menu.
 */
void Plot1D::contextMenu(){
    QMenu* menu = new QMenu();
    menu->addAction(tr("Clear graph") , this , SLOT(clearGraph()));
    menu->addAction(tr("Save as .csv") , this , SLOT(saveGraphCsv()));
    menu->addAction(tr("Save as .png") , this , SLOT(saveGraphPng()));

    QMenu* subm = new QMenu(menu);
    subm->setDisabled(true);
    subm->setTitle(tr("Add plot"));
    menu->addMenu(subm);

    if(mdl != NULL){
        QStringList list = mdl->otherPlot();
        for(int i = 0; i < list.length(); i++){
            if(list[i] == mdl->name() || additional.contains(list[i])) continue;
            QAction* action = new QAction(subm);
            QSignalMapper* mapper = new QSignalMapper(action);
            action->setText(list[i]);
            connect(action, SIGNAL(triggered()), mapper, SLOT(map()));
            mapper->setMapping(action, list[i]);
            connect(mapper, SIGNAL(mapped(QString)), mdl, SLOT(addPlot(QString)));
            subm->addAction(action);
        }
        if(!subm->isEmpty()) subm->setEnabled(true);
    }

    subm = new QMenu(menu);
    subm->setDisabled(true);
    subm->setTitle(tr("Remove plot"));
    menu->addMenu(subm);

    if(additional.length() > 0){
            for(int i = 0; i < additional.length(); i++){
            QAction* action = new QAction(subm);
            QSignalMapper* mapper = new QSignalMapper(action);
            action->setText(additional[i]);
            connect(action, SIGNAL(triggered()), mapper, SLOT(map()));
            mapper->setMapping(action, additional[i]);
            connect(mapper, SIGNAL(mapped(QString)), this, SLOT(removePlot(QString)));
            subm->addAction(action);
        }
        if(!subm->isEmpty()) subm->setEnabled(true);
    }

    menu->popup(QCursor::pos());
    menu->exec();
    delete menu;
}

/**
 * Adds other plot to this plot.
 */
void Plot1D::addPlot(Plot1D* plot){
    point.append(plot->point[0]);
    if(mdl != NULL) additional.append(plot->mdl->name());

    if(plot->point[0].length() > 1){
        if(plot->xMin < xMin) xMin = plot->xMin;
        if(plot->xMax > xMax) xMax = plot->xMax;
        if(plot->oMin < oMin) oMin = plot->oMin;
        if(plot->oMax > oMax) oMax = plot->oMax;
    }

    repaint();
}

/**
 * Removes other plot from this plot.
 */
void Plot1D::removePlot(QString name){
    if(additional.contains(name)){
        point.removeAt(additional.indexOf(name)+1);
        additional.removeAll(name);

        xMin = 10E99;
        xMax = -10E99;
        oMin = 10E99;
        oMax = -10E99;

        for(int i = 0; i < point.length(); i++){
            for(int j = 0; j < point[i].length(); j++){
                if(point[i][j].x < xMin) xMin = point[i][j].x;
                if(point[i][j].x > xMax) xMax = point[i][j].x;
                if(point[i][j].o < oMin) oMin = point[i][j].o;
                if(point[i][j].o > oMax) oMax = point[i][j].o;
            }
        }
    }

    repaint();
}

/**
 * Adds point to plot.
 */
void Plot1D::addPoint(double x, double o){
    if(x < xMin) xMin = x;
    if(x > xMax) xMax = x;
    if(o < oMin) oMin = o;
	if(o > oMax) oMax = o;

	Point1D pt;
	pt.x = x;
	pt.o = o;

    point[0].append(pt);
}

/**
 * Clears plot (data and axis ranges).
 */
void Plot1D::clearGraph(){
    additional.clear();
    point[0].clear();
    int len = point.length()-1;
    for(int i = 0; i < len; i++)
        point.removeLast();
    xMin = 10E99;
    xMax = -10E99;
    oMin = 10E99;
    oMax = -10E99;
	repaint();
}

/**
 * Saves plot as csv file.
 */
void Plot1D::saveGraphCsv(){
    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Save plot as .csv"),
        QDir::homePath(),
        tr("Csv files (*.csv)")
    );

    if(!filename.isNull()){
        QFile file(filename);

        if(!file.open(QFile::WriteOnly)){
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Save plot as .csv"));
            msgBox.setText(tr("Error"));
            msgBox.setInformativeText(tr("Unable to write file"));
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
            return;
        }

        QTextStream stream;
        stream.setDevice(&file);
        stream << toString();
        file.close();
    }
}

/**
 * Saves plot as png image.
 */
void Plot1D::saveGraphPng(){
    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Save plot as .png"),
        QDir::homePath(),
        tr("Png images (*.png)")
    );

    if(!filename.isNull()){
        QImageWriter writer(filename, "png");
        writer.write(grabFrameBuffer());

        if(writer.error() != QImageWriter::UnknownError){
            QMessageBox msgBox;
            msgBox.setWindowTitle(tr("Save plot as .png"));
            msgBox.setText(tr("Error"));
            msgBox.setInformativeText(writer.errorString());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        }
    }
}

/**
 * Converts plot to string.
 */
QString Plot1D::toString(){
    QString text;

    for(int i = 0; i < point[0].length(); i++){
        text += QString::number(point[0][i].x);
        text += "; ";
        text += QString::number(point[0][i].o);
        text += "\n ";
    }

    /*int maxlen = 0;
    for(int i = 0; i < point.length(); i++){
        if(point[i].length() > maxlen) maxlen = point[i].length();
        text += "x" + QString::number(i) + ";";
        text += "y" + QString::number(i);
        if(i < point.length()-1) text += "; ";
    }
    text += "\n";

    for(int i = 0; i < maxlen; i++){
        for(int j = 0; j < point.length(); j++){
            if(i < point[j].length()){
                text += QString::number(point[j][i].x);
                text += ";";
                text += QString::number(point[j][i].o);
                text += ";";
            }else{
                text += "; ";
                if(j < point.length()-1) text += "; ";
            }
        }
        text += "\n";
    }*/

    return text;
}

/**
 * Fills plot with data from given string.
 */
void Plot1D::fromString(QString data){
    clearGraph();

    double xVal = 0;
    double yVal = 0;
    QString subText;
    int state = 0;

    for(int i = 0; i < data.length(); i++){
        switch(state){
            case 0:
                if(data[i] == ';'){
                    xVal = subText.toDouble();
                    subText = "";
                    state = 1;
                    break;
                }
                subText += data[i];
                break;

            case 1:
                if(data[i] == '\n'){
                    yVal = subText.toDouble();
                    subText = "";
                    addPoint(xVal, yVal);
                    state = 0;
                    break;
                }
                subText += data[i];
                break;

            default:
                break;
        }
    }

    repaint();
}

/**
 * Enables and disables automatic range calculation.
 */
void Plot1D::setAutorange(bool enabled){
    autorange = enabled;
}

/**
 * Sets minimal value of Y axis range.
 */
void Plot1D::setMinAutorangeO(double val){
    oMin = val;
}

/**
 * Sets custom range of Y axis (used when autorange is disabled).
 */
void Plot1D::setRange(double min, double max){
    orMin = min;
    orMax = max;
}

/**
 * Sets custom range of X axis (used when autorange is disabled).
 */
void Plot1D::setRangeX(double min, double max){
    xrMin = min;
    xrMax = max;
}

/**
 * Returns maximal X value in plot.
 */
double Plot1D::maxX(){
    if(point.length() == 1 && point[0].length() < 2) return 0;
    return xMax;
}

/**
 * Returns maximal Y value in plot.
 */
double Plot1D::maxO(){
    if(point.length() == 1 && point[0].length() < 2) return 0;
    return oMax;
}

/**
 * Sets X axis label.
 */
void Plot1D::setLabelX(QString label){
    xLbl = label;
}

/**
 * Sets Y axis label.
 */
void Plot1D::setLabelY(QString label){
    yLbl = label;
}

/**
 * OpenGL initialization.
 */
void Plot1D::initializeGL(){
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glEnable(GL_POLYGON_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(1.0, 1.0, 1.0, 0);
}

/**
 * PaintGL method.
 */
void Plot1D::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawXGrid();
	drawYGrid();
	drawXAxis();
	drawYAxis();
	drawXLabel();
	drawYLabel();
	drawGraph();
}

/**
 * ResizeGL method.
 */
void Plot1D::resizeGL(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h); // set origin to bottom left corner
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
 * Draws plot data.
 */
void Plot1D::drawGraph(){
    double sx = 1;
    double sy = 1;
    double mo = 0;
    double mx = 0;

    if(autorange){
        sx = graphWidth() / (xMax-xMin);
        sy = graphHeight() / (oMax-oMin);
        mo = oMin;
        mx = xMin;
    }else{
        sx = graphWidth() / (xrMax-xrMin);
        sy = graphHeight() / (orMax-orMin);
        mo = orMin;
        mx = xrMin;
    }

	glLoadIdentity();
	glLineWidth(2);

    for(int p = point.length()-1; p >= 0 ; p--){
        if(point[p].length() < 2) continue;
        QColor clr = color(p);
        glColor3f(clr.red(), clr.green(), clr.blue());
        glBegin(GL_LINES);
        for(int i = 1; i < point[p].length(); i++){
            glVertex2f(leftSpace+sx*(point[p][i-1].x-mx), bottomSpace+sy*(point[p][i-1].o-mo));
            glVertex2f(leftSpace+sx*(point[p][i].x-mx), bottomSpace+sy*(point[p][i].o-mo));
        }
        glEnd();
    }
}

/**
 * Draws X axis.
 */
void Plot1D::drawXAxis(){
	glLoadIdentity();
	glColor3f(0,0,0);
	glLineWidth(2);

	glBegin(GL_LINES);
		//axis
		glVertex2f(leftSpace, bottomSpace);
		glVertex2f(width()-rightSpace, bottomSpace);
		//arrow
		glVertex2f(width()-rightSpace-15, bottomSpace-4);
		glVertex2f(width()-rightSpace, bottomSpace);
		//arrow
		glVertex2f(width()-rightSpace-15, bottomSpace+4);
		glVertex2f(width()-rightSpace, bottomSpace);
	glEnd();
}

/**
 * Draws X axis grid.
 */
void Plot1D::drawXGrid(){
	glLoadIdentity();
	glColor3f(0.7f, 0.7f, 0.7f);
	glLineWidth(1);

	glBegin(GL_LINES);
    for(int i = 1; i <= 10; i++){
        glVertex2f(i * graphWidth()/10.0 + leftSpace, bottomSpace);
        glVertex2f(i * graphWidth()/10.0 + leftSpace, height()-topSpace);
	}
	glEnd();
}

/**
 * Draws X axis label.
 */
void Plot1D::drawXLabel(){
    double xm = autorange ? (xMax-xMin) : (xrMax-xrMin);
    if(point.length() == 1 && point[0].length() < 2) xm = 1;

	glLoadIdentity();
	glColor3f(0.0f, 0.0f, 0.0f);
    for(int i = 0; i <= 10; i++){
        double val = 0.0;
        if(point.length() == 1 && point[0].length() < 2) val = 0.1 * i;
        else val = i * (xm / 10) + (autorange?xMin:xrMin);
        rendText(i * graphWidth()/10.0 + leftSpace, bottomSpace-10, QString::number(val));
	}

    rendText(width()/2.0, 15, xLbl);
}

/**
 * Draws Y axis.
 */
void Plot1D::drawYAxis(){
	glLoadIdentity();
	glColor3f(0,0,0);
	glLineWidth(2);

	glBegin(GL_LINES);
		//axis
		glVertex2f(leftSpace, bottomSpace);
		glVertex2f(leftSpace, height()-topSpace);
		//arrow
		glVertex2f(leftSpace, height()-topSpace);
		glVertex2f(leftSpace+4, height()-topSpace-15);
		//arrow
		glVertex2f(leftSpace, height()-topSpace);
		glVertex2f(leftSpace-4, height()-topSpace-15);
	glEnd();
}

/**
 * Draws Y axis grid.
 */
void Plot1D::drawYGrid(){
	glLoadIdentity();
	glColor3f(0.7f, 0.7f, 0.7f);
	glLineWidth(1);

	glBegin(GL_LINES);
    for(int i = 1; i <= 10; i++){
        glVertex2f(leftSpace, i * graphHeight()/10.0 + bottomSpace);
        glVertex2f(width()-rightSpace, i * graphHeight()/10.0 + bottomSpace);
	}
	glEnd();
}

/**
 * Draws Y axis label.
 */
void Plot1D::drawYLabel(){
    double om = autorange ? (oMax-oMin) : (orMax-orMin);
    if(point.empty()) om = 1;

    for(int i = 0; i <= 10; i++){
        double val = 0.0;
        if(point.length() == 1 && point[0].length() < 2) val = 0.1 * i;
        else val = i * (om / 10) + (autorange?oMin:orMin);
        rendText(leftSpace-23, i * graphHeight()/10.0 + bottomSpace, QString::number(val, 'g', 3));
	}

    rendTextV(15, height()/2, yLbl);
}

/**
 * Draws given text at given position.
 */
void Plot1D::rendText(float x, float y, QString text){
	glLoadIdentity();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(x - (text.length() * 7.7f)/2.0f, y - 5.0f, 0.0);
	renderText(0.0f, 0.0f, 0.0f, text, font);
}

/**
 * Draws given text verticaly at given position.
 */
void Plot1D::rendTextV(float x, float y, QString text){
	y += text.length()*6.0f;
	for(int i = text.length()-1; i >=0 ; i--){
		rendText(x, y-12.0*i, QString(text[i]));
	}
}

/**
 * Returns width of plot (edge space not included).
 */
double Plot1D::graphWidth(){
    return width() - (leftSpace+rightSpace);
}

/**
 * Returns height of plot (edge space not included).
 */
double Plot1D::graphHeight(){
    return height() - (bottomSpace+topSpace);
}

}
