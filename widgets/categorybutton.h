#ifndef CATEGORYBUTTON_H
#define CATEGORYBUTTON_H

#include "../model/appslistmodel.h"
#include "global_util/calculate_util.h"

#include <QAbstractButton>
#include <QLabel>

class CategoryButton : public QAbstractButton
{
    Q_OBJECT

public:
    enum State {
        Normal,
        Hover,
        Checked,
    };

public:
    explicit CategoryButton(const AppsListModel::AppCategory category, QWidget *parent = 0);

    QLabel *textLabel();

public slots:
    void setChecked(bool isChecked);
    void setTextVisible(bool visible);
    AppsListModel::AppCategory category() const;

protected:
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

private:
    void setInfoByCategory();
    void updateState(const State state);
    void addTextShadow();

private:
    CalculateUtil *m_calcUtil;
    State m_state = Checked;
    AppsListModel::AppCategory m_category;
    QString m_iconName;

    QLabel *m_iconLabel;
    QLabel *m_textLabel;
};

#endif // CATEGORYBUTTON_H
