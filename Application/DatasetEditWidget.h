#ifndef DATASETEDITWIDGET_H
#define DATASETEDITWIDGET_H

#include <QMenu>
#include <QWidget>
#include "Project/DatasetEditModel.h"

using namespace ProjectData;
namespace Ui{class DatasetEditWidget;}

/**
 * Contains main application graphical user interface classes.
 */
namespace Application{

/**
 * The DatasetEditWidget class.
 */
class DatasetEditWidget : public QWidget{
	Q_OBJECT
		
	public:
        DatasetEditWidget(QWidget *parent = 0);
		~DatasetEditWidget();
		void setModel(DatasetEditModel* model);
		bool hasModel();

	private slots:
		void modelChanged(ChangeType type);
		void closeBtnPressed();
		void showContextMenu();
		void changePatternCount(int value);
		void changeInputCount(int value);
		void changeOutputCount(int value);
		void copyCell();
		void cutCell();
		void pasteCell();
		void deleteCell();

	signals:
        /** Emmited when close button is pressed. */
		void closePressed(BaseModel*);

	private:
        /** Autogenerated stuff, user interface class pointer. */
        Ui::DatasetEditWidget *ui;
        /** Tells if value obtained by copy or cut is valid. */
		bool editValOk;
        /** Value obtained by copy or cut is valid. */
		double editVal;
        /** Current model pointer. */
		ProjectData::DatasetEditModel* model;
        /** Context menu pointer. */
		QMenu* contextMenu;
};

}

#endif // DATASETEDITWIDGET_H
