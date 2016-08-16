#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string>


namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT
//methods
public:
	explicit Widget(QWidget *parent = 0);
	~Widget();
	void setName(const QString &name);
	QString name() const;
	bool Widget::eventFilter(QObject *obj, QEvent *event);

//custom slot	
public slots:
	void example();
	//variables
private:
	Ui::Widget *ui;
	int sayi1,sayi2;
};

#endif // WIDGET_H
