#include "myplayer.h"
#include <QtMultimedia/QAudioBuffer>
#include <QDir>
#include <QTimer>

MyPlayer::MyPlayer()
{
    timer = new QTimer(this);
    playlist = new QMediaPlaylist(this);
    player = new QMediaPlayer(this);
    probe = new QAudioProbe(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(test(QAudioBuffer)));

    QStringList list = QDir::current().entryList(QStringList("*.mp3"));

    for (auto fileName : list)
        playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/" + fileName));

    player->setPlaylist(playlist);

    probe->setSource(player);

    player->play();

    timer->start(100);
}

void MyPlayer::test(QAudioBuffer buf)
{
    QAudioBuffer::S16S *frames = buf.data<QAudioBuffer::S16S>();
    m_curScale = 1 + 0.00005 * frames[0].average();
}

void MyPlayer::update()
{
    emit curScaleChanged();
}
