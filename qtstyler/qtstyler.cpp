#include "qtstyler.h"
#include <QFile>
#include <QStyle>
#include <QApplication>
#include <QStyleFactory>

QtStyler::QtStyler(QObject *parent) :
	QObject(parent),
	font_(qApp->font())
{
	// Colors for all roles
	darkPalette_.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette_.setColor(QPalette::WindowText, Qt::white);
	darkPalette_.setColor(QPalette::Base, QColor(42, 42, 42));
	darkPalette_.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
	darkPalette_.setColor(QPalette::ToolTipBase, Qt::white); // No use 4 Windows
	darkPalette_.setColor(QPalette::ToolTipText, Qt::white); // No use 4 Windows
	darkPalette_.setColor(QPalette::PlaceholderText, Qt::darkGray);
	darkPalette_.setColor(QPalette::BrightText, Qt::red);
	darkPalette_.setColor(QPalette::Text, Qt::white);
	darkPalette_.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette_.setColor(QPalette::ButtonText, Qt::white);
	darkPalette_.setColor(QPalette::Dark, QColor(35, 35, 35));
	darkPalette_.setColor(QPalette::Shadow, QColor(20, 20, 20));
	darkPalette_.setColor(QPalette::Link, QColor(42, 130, 218));
	darkPalette_.setColor(QPalette::LinkVisited, QColor(42, 130, 218));
	darkPalette_.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette_.setColor(QPalette::HighlightedText, Qt::white);

	// Colors for disabled role
	darkPalette_.setColor(QPalette::Disabled, QPalette::Window, QColor(58, 58, 58));
	darkPalette_.setColor(QPalette::Disabled, QPalette::WindowText, Qt::darkGray);
	darkPalette_.setColor(QPalette::Disabled, QPalette::Base, QColor(48, 48, 48));
	darkPalette_.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor(68, 68, 68));
	darkPalette_.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
	darkPalette_.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);
	darkPalette_.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
	darkPalette_.setColor(QPalette::Disabled, QPalette::HighlightedText, Qt::darkGray);

	// Load stylesheet
	QFile darkFile("://fusiondark.qss");
	QFile lightFile("://fusionlight.qss");
	if (darkFile.open(QFile::ReadOnly))
		fusionDark_ = darkFile.readAll();
	if (lightFile.open(QFile::ReadOnly))
		fusionLight_ = lightFile.readAll();

	// Set current style
	currentStyle_ = qApp->style()->objectName() + " Light";
	currentStyle_[0] = currentStyle_[0].toUpper();
}

void QtStyler::setStyle(const QString &style)
{
	// Check if it exists
	if (availableStyles().contains(style)) {
		currentStyle_ = style;

		// Remove 'Light' and 'Dark'
		QString s = style;
		s.remove(" Light").remove(" Dark");

		// Set style
		qApp->setStyle(s);
		if (style.contains(" Dark")) {
			qApp->setPalette(darkPalette_);
			qApp->setStyleSheet(s.contains("Fusion") ? fusionDark_ : "");
		} else {
			qApp->setPalette(qApp->style()->standardPalette());
			qApp->setStyleSheet(s.contains("Fusion") ? fusionLight_ : "");
		}

		// Reset to saved font and emit signal
		qApp->setFont(font_);
		emit styleChanged(style);
	}
}

QStringList QtStyler::availableStyles() const
{
	// List available styles
	QStringList styles = QStyleFactory::keys();

	// Append 'Light' and 'Dark'
	QStringList allStyles;
	for (QString &style : styles) {
		if (!style.isEmpty())
			style[0] = style[0].toUpper();
		allStyles.insert(0, style + " Dark");
		allStyles.insert(0, style + " Light");
	}
	return allStyles;
}

QString QtStyler::currentStyle() const
{
	// Return current style
	return currentStyle_;
}
