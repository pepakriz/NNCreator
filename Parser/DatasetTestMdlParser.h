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

#ifndef DATASETTESTMDLPARSER_H
#define DATASETTESTMDLPARSER_H

#include <QXmlStreamReader>
#include "Project/DatasetTestModel.h"
#include <QObject>
using namespace ProjectData;

/**
 * Contains classes to load and save project data to xml files.
 */
namespace Parser{

/**
 * Dataset test model parser class.
 */
class DatasetTestMdlParser : public QObject{
    Q_OBJECT

	public:
		static DatasetTestMdlParser& get();
		DatasetTestModel* load(QString path) const;
		bool save(DatasetTestModel* mdl) const;

	private:
        /** Makes imposible to call class constructor by making it private. */
		DatasetTestMdlParser();
        /** Makes imposible to call copy constructor by making it private. */
		DatasetTestMdlParser(DatasetTestMdlParser const&);
        /** Makes imposible to call operator= by making it private. */
		void operator=(DatasetTestMdlParser const&);
};

}

#endif // DATASETTESTMDLPARSER_H
