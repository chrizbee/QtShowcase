#ifndef STYLER_H
#define STYLER_H

#include <QFont>
#include <QPalette>
#include <QStringList>

class QtStyler : public QObject
{
	Q_OBJECT

public:
	QtStyler(QObject *parent = nullptr);
	void setStyle(const QString &style);
	QStringList availableStyles() const;
	QString currentStyle() const;

signals:
	void styleChanged(const QString &style);

private:
	QFont font_;
	QString currentStyle_;
	QPalette darkPalette_;
	QString fusionLight_;
	QString fusionDark_;
};

#endif // STYLER_H
