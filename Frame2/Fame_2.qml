import QtQuick 2.15
import QtQuick.Window 2.15
import "./Frame2"
Rectangle{
    anchors.fill: parent
    color: "red"
    Image {
        id: image
        source: "qrc:/Src/image_20/image 20.png"
        width: 300
        height: 300
        x: 439
        y: 82
    }

}
