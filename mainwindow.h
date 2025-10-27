#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetPixmap(QLabel *label_pix, const QString& path);

    void resizeEvent(QResizeEvent* event) override;
    void UpdateSizeLabel();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
