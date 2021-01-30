#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtStyler/qtstyler.h>
#include <QDesktopServices>
#include <QFileDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui_(new Ui::MainWindow),
	styler_(new QtStyler(this))
{
	// Initialize UI
	ui_->setupUi(this);
	ui_->toolbar->setHidden(true);
	ui_->statusbar->showMessage("Hello from the status bar o/");

	// Connect some demo logic
	connect(ui_->actionOpen, &QAction::triggered, [this]() { QFileDialog::getOpenFileName(this, tr("Open File")); });
	connect(ui_->actionSave, &QAction::triggered, [this]() { QFileDialog::getSaveFileName(this, tr("Save File")); });
	connect(ui_->actionIcons8, &QAction::triggered, []() { QDesktopServices::openUrl(QUrl("https://icons8.com")); });
	connect(ui_->actionShowcase, &QAction::triggered, []() { QDesktopServices::openUrl(QUrl("https://github.com/chrizbee/QtShowcase")); });
	connect(ui_->actionStatusbar, &QAction::toggled, ui_->statusbar, &QStatusBar::setVisible);
	connect(ui_->actionToolbar, &QAction::toggled, ui_->toolbar, &QToolBar::setVisible);
	connect(ui_->chDisable, &QCheckBox::clicked, ui_->mainWidget, &QWidget::setDisabled);
	QTimer::singleShot(1, [this] { setGeometry(x(), y(), width(), minimumHeight()); });

	// Setup styler
	ui_->cbStyle->addItems(styler_->availableStyles());
	ui_->cbStyle->setCurrentText(styler_->currentStyle());
	connect(ui_->cbStyle, &QComboBox::currentTextChanged, styler_, &QtStyler::setStyle);
	connect(styler_, &QtStyler::styleChanged, ui_->cbStyle, &QComboBox::setCurrentText);
}

MainWindow::~MainWindow()
{
	// Cleanup
	delete ui_;
}
