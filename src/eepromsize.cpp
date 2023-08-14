#include <QMessageBox>
#include "ui_eepromsize.h"
#include "eepromsize.h"

EepromSize::EepromSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EepromSize)
{
    ui->setupUi(this);
    connect(ui->listWidget, &QListWidget::doubleClicked,  this,   &EepromSize::lw_clicked);
}

EepromSize::~EepromSize()
{
    delete ui;
}

void EepromSize::show()
{
    QWidget::show();

}
void EepromSize::accept()
{
    emit accepted();
    QString chipmodel = ui->listWidget->currentItem()->text();
    emit listWidget_click(chipmodel);
    QDialog::hide();
}

void EepromSize::lw_clicked()
{
    QString chipmodel = ui->listWidget->currentItem()->text();
    QMessageBox::about(this, "EEPROM type:", chipmodel);

    emit listWidget_click(chipmodel);
    QDialog::hide();
}
