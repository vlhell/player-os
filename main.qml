import QtQuick 2.6
import QtQuick.Controls 2.0
import com.myplayer 1.0

ApplicationWindow {
    id: root

    visible: true
    width: 640
    height: 480

    Item {
        anchors.fill: parent

        MyPlayer {
            id: player

            scale: curScale

            width: 300
            height: 300
            anchors.centerIn: parent

            Image {
                source: "qrc:/bg.jpg"
                anchors.fill: parent
            }

            Behavior on scale { NumberAnimation { duration: 100} }
        }
    }
}
