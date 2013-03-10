#include "DatasetTestWidget.h"
#include "ui_DatasetTestWidget.h"
#include <QDebug>

namespace Application{

DatasetTestWidget::DatasetTestWidget(QWidget *parent) : QWidget(parent), ui(new Ui::DatasetTestWidget), model(NULL){
	ui->setupUi(this);
	connect(ui->closeButton, SIGNAL(pressed()), this, SLOT(closeBtnPressed()));
	connect(ui->startTestBtn, SIGNAL(pressed()), this, SLOT(startTest()));
	connect(ui->datasetBox, SIGNAL(activated(QString)), this, SLOT(datasetSelected(QString)));
	connect(ui->networkBox, SIGNAL(activated(QString)), this, SLOT(networkSelected(QString)));
	emptyModel = new DatasetEditModel();
	emptyModel->setPatternCount(0);
	ui->datasetView->setModel(emptyModel->viewModel());
	ui->startTestBtn->setEnabled(false);
}

DatasetTestWidget::~DatasetTestWidget(){
	delete ui;
	delete emptyModel;
}

void DatasetTestWidget::setModel(DatasetTestModel* model){
	this->model = model;
	ui->startTestBtn->setEnabled(false);

	ui->datasetView->setModel(emptyModel->viewModel());

	if(model == NULL){
		ui->itemName->setText(QString());
	}else{
		ui->itemName->setText(model->name());
		genSelectedLists();
		connect(model, SIGNAL(changed(ChangeType)), this, SLOT(modelchanged(ChangeType)), Qt::UniqueConnection);
	}
}

void DatasetTestWidget::startTest(){
	long time = 0;
	double err = 0;
	QList<QList<double > > errs = model->runTest(time, err);

	ui->ffTimeEdit->setText(QString::number(time));
	ui->totalErrorEdit->setText(QString::number(err));

	if(errs.isEmpty()) return;

	int tptCnt = errs.length();
	int outCnt = errs[0].length();

	ui->errorTable->setRowCount(tptCnt);
	ui->errorTable->setColumnCount(outCnt);

	QStringList hList;
	for(int i = 0; i < outCnt; i++){
		if(i == 0)
			hList.append("Pt err");
		else{
			hList.append("Out " + QString::number(i));
			hList.append("Out " + QString::number(i) + " err");
		}
	}

	QStringList vList;
	for(int i = 0; i < tptCnt; i++){
		vList.append("Pt" + QString::number(i+1) + " errs");
	}

	ui->errorTable->setHorizontalHeaderLabels(hList);
	ui->errorTable->setVerticalHeaderLabels(vList);

	for(int i = 0; i < tptCnt; i++){
		for(int j = 0; j < outCnt; j++){
			QTableWidgetItem* item = new QTableWidgetItem();
			item->setText(QString::number(errs[i][j]));
			ui->errorTable->setItem(i, j, item);
		}
	}
}

void DatasetTestWidget::genSelectedLists(){
	ui->networkBox->clear();
	ui->networkBox->addItem(QString("<Choose neural network>"));

	QStringList nets = model->networkList();
	if(!nets.isEmpty()) ui->networkBox->addItems(nets);

	int index = ui->networkBox->findText(model->selectedNetworkName());
	if(index > 0){
		ui->networkBox->setCurrentIndex(index);
		networkSelected(model->selectedNetworkName());
	}
	else{
		ui->datasetBox->clear();
		ui->datasetBox->addItem(QString("<No network selected>"));
	}
}

void DatasetTestWidget::networkSelected(QString name){
	if(ui->networkBox->currentIndex() < 1){
		model->selectNetwork(QString());
		ui->startTestBtn->setEnabled(false);
		return;
	}

	ui->datasetBox->clear();
	QStringList list = model->datasetList(name);

	if(list.isEmpty()){
		ui->datasetBox->addItem(QString("<No dataset available for this network>"));
	}else{
		ui->datasetBox->addItem(QString("<Select training dataset>"));
		ui->datasetBox->addItems(list);
		if(!model->selectedDatasetName().isEmpty()){
			int index = ui->datasetBox->findText(model->selectedDatasetName());
			if(index > 0){
				ui->datasetBox->setCurrentIndex(index);
				datasetSelected(model->selectedDatasetName());
			}
			ui->startTestBtn->setEnabled(true);
		}
	}

	model->selectNetwork(name);
}

void DatasetTestWidget::datasetSelected(QString name){
	if(ui->datasetBox->currentIndex() < 1){
		model->selectDataset(QString());
		ui->datasetView->setModel(emptyModel->viewModel());
		ui->startTestBtn->setEnabled(false);
		return;
	}

	model->selectDataset(name);
	BaseModel* dataset = model->selectedDataset();
	Q_ASSERT(dataset != NULL);
	ui->datasetView->setModel(((DatasetEditModel*)dataset)->viewModel());
	ui->startTestBtn->setEnabled(true);
}


bool DatasetTestWidget::hasModel(){
	return model != NULL;
}

void DatasetTestWidget::closeBtnPressed(){
	emit closePressed(model);
}

void DatasetTestWidget::modelchanged(ChangeType type){
	if(type == ModelRenamed)
		ui->itemName->setText(model->name());
	else if(type == SelectedNetworkRenamed)
		genSelectedLists();
	else if(type == SelectedDatasetRenamed)
		genSelectedLists();
	else if(type == SelectedNetworkDeleted)
		genSelectedLists();
	else if(type == SelectedDatasetDeleted)
		genSelectedLists();
}

}
