#include "widget.h"
#include "ui_widget.h"
#include <iostream>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{

	ui->setupUi(this);
	//like event listener
	ui->pushButton->installEventFilter(this);
	ui->pushButton_2->installEventFilter(this);
	
	connect(ui->comboBox,
		SIGNAL(currentIndexChanged(int)),
		this,
		SLOT(example()));
}

Widget::~Widget()
{
	delete ui;
}
//custom slot
void Widget::example() {
	ui->label->setNum(ui->comboBox->currentIndex() + 1);
}
//setting label text
void Widget::setName(const QString &name)
{
	ui->label->setText(name);
}
//getting text from lineedit 1
QString Widget::name() const
{
	return ui->lineEdit->text();
}
//event listener
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QString qs;
		qs = obj->objectName();

		ui->label->setText(qs);
		sayi1 = ui->lineEdit->text().toInt();
		sayi2 = ui->lineEdit_2->text().toInt();
		ui->label_2->setNum(sayi1+sayi2);
	}
	return false;
}
