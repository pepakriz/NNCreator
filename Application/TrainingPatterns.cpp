#include "TrainingPatterns.h"
#include "ui_TrainingPatterns.h"

TrainingPatterns::TrainingPatterns(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TrainingPatterns)
{
	ui->setupUi(this);
}

TrainingPatterns::~TrainingPatterns()
{
	delete ui;
}
