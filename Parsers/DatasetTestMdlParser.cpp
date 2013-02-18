#include "DatasetTestMdlParser.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDir>

namespace Parsers{

DatasetTestMdlParser::DatasetTestMdlParser(){}

DatasetTestMdlParser& DatasetTestMdlParser::get(){
	static DatasetTestMdlParser instance;
	return instance;
}

DatasetTestModel* DatasetTestMdlParser::load(QString path) const{
	DatasetTestModel* mdl = new DatasetTestModel();

	QFile file(path);
	bool succ = file.open(QIODevice::ReadOnly);

	if(!succ){
		QMessageBox msgBox;
		msgBox.setWindowTitle("Open dataset test");
		msgBox.setText("Dataset test file can't be opened !!!");
		msgBox.setInformativeText("Check if file exists or program have permission to read it.");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		delete mdl;
		return NULL;
	}

	QXmlStreamReader rd;
	rd.setDevice(&file);

	QString elemName;
	int state = 0;

	//reading
	while (!rd.atEnd()) {
		switch(rd.readNext()){
			case QXmlStreamReader::StartElement:
				elemName = rd.name().toString();
				if(rd.name() == "header"){
					state = 1;
				}
				break;

			case QXmlStreamReader::EndElement:
				elemName = "";
				if(rd.name() == "header"){
					state = 0;
				}
				break;

			case QXmlStreamReader::Characters:
				switch(state){
					case 1:
						if(elemName == "name") mdl->setName(rd.text().toString());
						break;
				}
				break;

			default:
				break;
		}
	}

	//error handling
	if(rd.hasError()){
		QMessageBox msgBox;
		msgBox.setWindowTitle("Open dataset test");
		msgBox.setText("Error parsing dataset test file !!!");
		msgBox.setInformativeText(rd.errorString());
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		file.close();
		delete mdl;
		return NULL;
	}

	file.close();
	return mdl;
}

bool DatasetTestMdlParser::save(DatasetTestModel* mdl) const{
	bool succ = true;

	QDir dir(mdl->projectPath());
	if(!dir.exists(mdl->folder()))
		succ = dir.mkdir(mdl->folder());

	if(!succ){
		QMessageBox msgBox;
		msgBox.setWindowTitle("Save testing scenario");
		msgBox.setText("Testing scenario folder can't be created !!!");
		msgBox.setInformativeText("Check if given path exists or program have permission to read and write.");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		return false;
	}

	QFile file(mdl->projectPath() + "/" + mdl->path());
	succ = file.open(QIODevice::WriteOnly);

	if(!succ){
		QMessageBox msgBox;
		msgBox.setWindowTitle("Save testing scenario");
		msgBox.setText("Testing scenario file can't be created !!!");
		msgBox.setInformativeText("Check if given path exists or program have permission to read and write.");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
		return false;
	}

	QXmlStreamWriter wr(&file);
	wr.setAutoFormatting(true);
	wr.writeStartDocument();
	wr.writeStartElement("datasetTest");

	wr.writeStartElement("header");
	wr.writeTextElement("name", mdl->name());
	wr.writeEndElement();

	wr.writeEndElement();
	file.close();
	return true;
}

}