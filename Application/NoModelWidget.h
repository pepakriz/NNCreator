#ifndef NOMODELWIDGET_H
#define NOMODELWIDGET_H

#include <QWidget>

namespace Ui {
	class NoModelWidget;
}

class NoModelWidget : public QWidget{
	Q_OBJECT
		
	public:
		explicit NoModelWidget(QWidget *parent = 0);
		~NoModelWidget();
		
	private:
		Ui::NoModelWidget *ui;
};

#endif // NOMODELWIDGET_H
