#ifndef CALCULATE_UTIL_H
#define CALCULATE_UTIL_H

#include <QObject>
#include <QSize>
#include <QtCore>

class CalculateUtil : public QObject
{
    Q_OBJECT

signals:
    void layoutChanged() const;

public:
    static CalculateUtil *instance(QObject *parent = nullptr);

    static int calculateBesidePadding(const int screenWidth);

    inline int titleTextSize() const {return m_titleTextSize;}
    inline int navgationTextSize() const {return m_navgationTextSize;}
    inline int appColumnCount() const {return m_appColumnCount;}
    inline int appItemFontSize() const {return m_appItemFontSize;}
    inline QSize appIconSize() const { return QSize(m_appIconSize, m_appIconSize);}
    inline int appItemSpacing() const {return m_appItemSpacing;}
    inline QSize appItemSize() const {return QSize(m_appItemWidth, m_appItemHeight);}

#ifdef QT_DEBUG
    inline void increaseIconSize() {m_appIconSize += 16;}
    inline void decreaseIconSize() {m_appIconSize -= 16;}
    inline void increaseItemSize() {m_appItemWidth += 16; m_appItemHeight += 16;}
    inline void decreaseItemSize() {m_appItemWidth -= 16; m_appItemHeight -= 16;}
#endif

public slots:
    void calculateAppLayout(const QSize &containerSize, const int dockPosition);

private:
    explicit CalculateUtil(QObject *parent);
    int itemSpacing(const int containerWidth) const;
    int itemIconWidth(const int itemWidth) const;
    void calculateTextSize(const int screenWidth);

private:
    static CalculateUtil *INSTANCE;

    int m_appItemFontSize = 12;
    int m_appIconSize = 64;
    int m_appItemSpacing = 10;
    int m_appItemWidth = 130;
    int m_appItemHeight = 130;
    int m_appColumnCount = 7;

    int m_navgationTextSize = 14;
    int m_titleTextSize = 15;
};

#endif // CALCULATE_UTIL_H
