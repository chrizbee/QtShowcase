#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QtStyler;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui_;
	QtStyler *styler_;
};
#endif // MAINWINDOW_H
