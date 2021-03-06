#ifndef SENDCOINSENTRY_H
#define SENDCOINSENTRY_H

#include <QFrame>

namespace Ui {
    class SendCoinsEntry;
}
class WalletModel;
class SendCoinsRecipient;

class SendCoinsEntry : public QFrame
{
    Q_OBJECT

public:
    explicit SendCoinsEntry(QWidget *parent = 0);
    ~SendCoinsEntry();

    void setModel(WalletModel *model);
    bool validate();
    SendCoinsRecipient getValue();

    // Return true if the entry is still empty and unedited
    bool isClear();

    void setValue(const SendCoinsRecipient &value);

    // Qt messes up the tab chain by default in some cases (issue http://bugreports.qt.nokia.com/browse/QTBUG-10907)
    // Hence we have to set it up manually
    QWidget *setupTabChain(QWidget *prev);

public slots:
    void setRemoveEnabled(bool enabled);
    void clear();

signals:
    void removeEntry(SendCoinsEntry *entry);

private slots:
    void on_deleteButton_clicked();
    void on_payTo_textChanged(const QString &address);
    void on_addressBookButton_clicked();
    void on_pasteButton_clicked();

private:
    Ui::SendCoinsEntry *ui;
    WalletModel *model;
};

#endif // SENDCOINSENTRY_H
