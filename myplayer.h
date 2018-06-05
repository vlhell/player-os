#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QQuickItem>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioProbe>


class MyPlayer : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(float curScale READ curScale NOTIFY curScaleChanged)

public:
    MyPlayer();
    float curScale() const { return m_curScale; }

signals:
    void curScaleChanged();

public slots:
    void test(QAudioBuffer buf);
    void update();

private:
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QAudioProbe *probe;
    QTimer *timer;
    float m_curScale = 0.1;
};

#endif // MYPLAYER_H
