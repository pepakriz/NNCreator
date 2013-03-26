#include "Project.h"
#include "Parser/ProjectParser.h"
#include "Parser/DatasetMdlParser.h"
#include "Parser/TopologyMdlParser.h"
#include "Parser/LrnConfMdlParser.h"
#include "Parser/DatasetTestMdlParser.h"
#include "Parser/GraphTestMdlParser.h"
#include <QDebug>
#include <QMessageBox>
using namespace Parser;

namespace ProjectData{

Project::Project() : pathVal(QString()), name(QString()){}

Project::Project(QString path, QString name) : pathVal(path), name(name){}

Project::~Project(){
	for(int i = 0; i < model.length(); i++) delete model[i];
}

QString Project::getName() const{
	return name;
}

QString Project::path() const{
	return pathVal;
}

void Project::setName(QString name){
	this->name = name;
}

void Project::setPath(QString path){
	this->pathVal = path;
}

BaseModel* Project::getModel(int index){
	return model[index];
}

BaseModel* Project::getModel(int index, const ModelType type){
	int count = 0;
	for(int i = 0; i < model.length(); i++){
		if(model[i]->type() == type){
			if(index == count){
				return model[i];
			}
			count++;
		}
	}
	return NULL;
}

BaseModel* Project::getModel(QString name, const ModelType type){
	int count = 0;
	for(int i = 0; i < model.length(); i++){
		if(model[i]->type() == type){
			if(name == model[i]->name()){
				return model[i];
			}
			count++;
		}
	}
	return NULL;
}

QList<BaseModel*> Project::getRelatedDataset(QString networkName){
	BaseModel* netBase = getModel(networkName, TopologyEdit);
	TopologyEditModel* net = (TopologyEditModel*)netBase;

	QList<BaseModel*> list;
	if(net == NULL) return list;

	for(int i = 0; i < count(DatasetEdit); i++){
		BaseModel* setBase = getModel(i, DatasetEdit);
		DatasetEditModel* set = (DatasetEditModel*)setBase;

		if(net->inputCount() == set->minInputCount() && net->outputCount() == set->minOutputCount()){
			list.append(set);
		}
	}

	return list;
}

BaseModel* Project::lastModel(){
	return model.last();
}

void Project::createModel(QString name, ModelType type){
	BaseModel* mdl = NULL;

	switch(type){
		case DatasetEdit:{
			mdl = new DatasetEditModel();
			break;
		}
		case TopologyEdit:{
			mdl = new TopologyEditModel();
			break;
		}
		case LearningConfig:{
			mdl = new LearningConfigModel();
			break;
		}
		case DatasetTest:{
			mdl = new DatasetTestModel();
			break;
		}
		case GraphTest:{
			mdl = new GraphTestModel();
			break;
		}
	}

	mdl->setName(name);
	mdl->setProject(this);

    BaseModel* mod = getModel(name, type);
    if(mod != NULL){
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Create new item"));
        msgBox.setText(tr("Project item can't be created."));
        msgBox.setInformativeText(tr("Name '") + name + tr("' already exists in project."));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }

	model.append(mdl);
	mdl->save();
	save();
}

int Project::count(const ModelType type) const{
	int count = 0;
	for(int i = 0; i < model.length(); i++){
		if(model[i]->type() == type) count++;
	}
	return count;
}

int Project::count() const{
	return model.length();
}

QString Project::getModelName(int index, const ModelType type) const{
	Q_ASSERT(index >= 0 && index < model.length());
	int count = 0;
	for(int i = 0; i < model.length(); i++){
		if(model[i]->type() == type){
			if(index == count) return model[i]->name();
			count++;
		}
	}
	return QString();
}

QList<BaseModel*> Project::getOpenedItems(){
	QList<BaseModel*> res;
	for(int i = 0; i < model.length(); i++){
		if(model[i]->isOpened()) res.append(model[i]);
	}
	return res;
}

QList<BaseModel*> Project::unsavedItems(){
	QList<BaseModel*> res;
	for(int i = 0; i < model.length(); i++){
		if(!model[i]->isSaved()) res.append(model[i]);
	}
	return res;
}

void Project::openModel(QString path, ModelType type){
	BaseModel* mdl = NULL;

	QString fullPath = this->pathVal + "/" + this->name +"/"+ path;

	switch(type){
		case DatasetEdit:{
			DatasetMdlParser& parser = DatasetMdlParser::get();
			mdl = parser.load(fullPath);
			break;
		}
		case TopologyEdit:{
			TopologyMdlParser& parser = TopologyMdlParser::get();
			mdl = parser.load(fullPath);
			break;
		}
		case LearningConfig:{
			LrnConfMdlParser& parser = LrnConfMdlParser::get();
			mdl = parser.load(fullPath);
			break;
		}
		case DatasetTest:{
			DatasetTestMdlParser& parser = DatasetTestMdlParser::get();
			mdl = parser.load(fullPath);
			break;
		}
		case GraphTest:{
			GraphTestMdlParser& parser = GraphTestMdlParser::get();
			mdl = parser.load(fullPath);
			break;
		}
	}

	if(mdl != NULL){
		mdl->setProject(this);
		model.append(mdl);
		mdl->setSaved(true);
	}
}

bool Project::save(){
	ProjectParser& pp = ProjectParser::get();
	return pp.save(this);
}

void Project::emitModelRenamed(QString newName, QString oldName, ModelType type){
	emit modelRenamed(newName, oldName, type);
}

void Project::removeModel(BaseModel* mdl){
	Q_ASSERT(mdl != NULL);
	model.removeOne(mdl);
	emit modelDeleted(mdl->name(), mdl->type());
	save();
}

void Project::reloadModel(BaseModel* mdl){
	Q_ASSERT(mdl != NULL);
	QString path = mdl->relPathName();
	ModelType type = mdl->type();
	model.removeOne(mdl);
	delete mdl;
	openModel(path, type);
}

}
