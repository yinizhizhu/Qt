#include "learnqt5.h"

learnQt5::learnQt5(QWidget *parent)
	: QMainWindow(parent)
{
	setupFileMenu();
	setupHelpMenu();
	setupEditor();
	setCentralWidget(editor);
	setWindowTitle(tr("Syntax Highlighter"));
}
void learnQt5::about()
{
	QMessageBox::about(this, tr("About Syntax Highlighter"),
		tr("<p>The <b>Syntax Highlighter</b> example shows how " \
		"to perform simple syntax highlighting by subclassing " \
		"the QSyntaxHighlighter class and describing " \
		"highlighting rules using regular expressions.</p>"));
}
void learnQt5::newFile()
{
	editor->clear();
}
void learnQt5::openFile(const QString &path)
{
	QString fileName = path;

	if (fileName.isNull())
		fileName = QFileDialog::getOpenFileName(this,
		tr("Open File"), "", "C++ Files (*.cpp *.h)");
	if (!fileName.isEmpty()) {
		QFile file(fileName);
		if (file.open(QFile::ReadOnly | QFile::Text))
			editor->setPlainText(file.readAll());
	}
}
void learnQt5::setupEditor()
{
	QFont font;
	font.setFamily("Courier");
	font.setFixedPitch(true);
	font.setPointSize(10);
	editor = new QTextEdit;
	editor->setFont(font);
	highlighter = new Highlighter(editor->document());
	QFile file("mainwindow.h");
	if (file.open(QFile::ReadOnly | QFile::Text))
		editor->setPlainText(file.readAll());
}
void learnQt5::setupFileMenu()
{
	QMenu *fileMenu = new QMenu(tr("&File"), this);
	menuBar()->addMenu(fileMenu);
	fileMenu->addAction(tr("&New"), this, SLOT(newFile()),
		QKeySequence(tr("Ctrl+N", "File|New")));
	fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()),
		QKeySequence(tr("Ctrl+O", "File|Open")));
	fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()),
		QKeySequence(tr("Ctrl+Q", "File|Exit")));
}
void learnQt5::setupHelpMenu()
{
	QMenu *helpMenu = new QMenu(tr("&Help"), this);
	menuBar()->addMenu(helpMenu);

	helpMenu->addAction(tr("&About"), this, SLOT(about()));
	helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
}