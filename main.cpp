#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include "mediator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QMainWindow mainWindow; // окно программы
  Mediator field; // игровое поле
  QMenuBar *menuBar; // меню

  mainWindow.setCentralWidget(&field);
  menuBar = mainWindow.menuBar();

  QAction *newAct = new QAction(QObject::tr("&New game"), &mainWindow);
  QObject::connect(newAct, SIGNAL(triggered()), &field, SLOT(on_gameReset()));
  menuBar->addAction(newAct);

  mainWindow.show();

  return a.exec();
}
