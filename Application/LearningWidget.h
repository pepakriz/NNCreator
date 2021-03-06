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

#ifndef LEARNINGWIDGET_H
#define LEARNINGWIDGET_H

#include <QWidget>
#include "Project/LearningConfigModel.h"
#include "GuiPart/NetParamWidget.h"
#include "GuiPart/Plot1D.h"
#include "Application/MainWindow.h"

using namespace ProjectData;
namespace Ui{class LearningWidget;}

/**
 * Contains main application graphical user interface classes.
 */
namespace Application{

//main window forward declaration
class MainWindow;

/**
 * The LearningWidget class.
 */
class LearningWidget : public QWidget{
	Q_OBJECT
		
	public:
        LearningWidget(MainWindow* mainWin = NULL);
		~LearningWidget();
		void setModel(LearningConfigModel* model);
		bool hasModel();

	private slots:
		void modelChanged(ChangeType type);
		void closeBtnPressed();
		void startLearning();
		void stopLearning();
        void learningStoped();
		void updateLearning(int iteration, long time, double error);
		void datasetSelected(QString name);
		void networkSelected(QString name);
		void lrnCoefChanged(double value);
		void maxIterChanged(int value);
		void maxErrChanged(double value);
		void maxTimeChanged(int value);
        void resetLearning();
        void graphBtnPressed();
        void tableBtnPressed();

	private:
        void genNetworkList();
        void setPlot(Plot1D* plot);
        void fillTable();

	signals:
        /** Emmited when close button is pressed. */
		void closePressed(BaseModel*);

	private:
        /** Autogenerated stuff, user interface class pointer. */
		Ui::LearningWidget *ui;
        /** Current model pointer. */
		LearningConfigModel* model;
        /** Net param widget pointer. */
		NetParamWidget* npw;
        /** MainWindow pointer, because of connecting model opened by network selection. */
        MainWindow* mainWin;
};

}

#endif // LEARNINGWIDGET_H
