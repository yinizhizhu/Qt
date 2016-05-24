#ifndef LEARNQT5_H
#define LEARNQT5_H

#include <QMainWindow>
#include <QtWidgets>

class learnQt5 :public QWidget
{
	Q_OBJECT
public:
	learnQt5();
	void setVisible(bool visible);
protected:
	void closeEvent(QCloseEvent *event);
private slots :
	void setIcon(int index);
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void showMessage();
	void messageClicked();
private:
	void createIconGroupBox();
	void createMessageGroupBox();
	void createActions();
	void createTrayIcon();
	QGroupBox *iconGroupBox;
	QLabel *iconLabel;
	QComboBox *iconComboBox;
	QCheckBox *showIconCheckBox;
	QGroupBox *messageGroupBox;
	QLabel *typeLabel;
	QLabel *durationLabel;
	QLabel *durationWarningLabel;
	QLabel *titleLabel;
	QLabel *bodyLabel;
	QComboBox *typeComboBox;
	QSpinBox *durationSpinBox;
	QLineEdit *titleEdit;
	QTextEdit *bodyEdit;
	QPushButton *showMessageButton;
	QAction *minimizeAction;
	QAction *maximizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QSystemTrayIcon*trayIcon;
	QMenu *trayIconMenu;
};

#endif // LEARNQT5_H
