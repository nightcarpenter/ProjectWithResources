#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path_img = ":/images/images/i-love-qt.png";
    SetPixmap(ui->lbl_pixmap, path_img);

    UpdateSizeLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetPixmap(QLabel *label_pix, const QString& path) {
    QPixmap pix{path};
    Q_ASSERT(!pix.isNull());

    QSize label_size = label_pix->size();
    pix = pix.scaled(label_size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label_pix->setPixmap(pix);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    UpdateSizeLabel();
}

void MainWindow::UpdateSizeLabel() {
    auto text = std::to_string(width()) + "x" + std::to_string(height());
    ui->lbl_size->setText(QString::fromStdString(text));


}
