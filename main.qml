import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Private 1.0
import QtGraphicalEffects 1.15
Window {
    width: 1112
    height: 742
    visible: true
    title: qsTr("Hello World")
    color: "#FFFFFF"
    Item {
        width: 1112
        height: 52
        Rectangle{
            anchors.fill:parent
            color: "red"
        }
    }
    Connections{
        target: nowplay
        onNameNowPlayingSongChanged: {
            nameMusicText.text = nowplay.nameNowPlayingSong
        }

        onImageNowPlayingSongChanged: imageNowPlayingSong.source = nowplay.imageNowPlayingSong
        onAuthorNowPlayingSongChanged: nameAuthorText.text = nowplay.authorNowPlayingSong
        onTimeNowPlayingSongChanged: timeEndMusic.text = nowplay.timeNowPlayingSong
        onDurationNowPlayingSongChanged: {
            slideBarmusic.width = 391 - (nowplay.durationNowPlayingSong/nowplay.timeIntNowPlayingSong)*391
            timeStartMusic.text = nowplay.durantionQStringNowPlayingSong
            //console.log((nowplay.durationNowPlayingSong/nowplay.timeIntNowPlayingSong)*391)
        }
    }
    Item {
        width: 1112
        height: 690
        y: 52
        Image {
            id: imageNowPlayingSong
            source: "qrc:/Src/Image_Start/Music-HD-Wallpaper-Free-download.jpg"
            width: 300
            height: 300
            x: 439
            y: 82
        }
        //fame918
        Rectangle{
            width: 300
            height: 45
            x: 439
            y: 397
            Image{
                id: addimage
                height:18
                width: 18
                x:4
                y:13.5
                source: "qrc:/Src/image_20/918/add.svg"
            }
            Image {
                id: heartimage
                height:18
                width: 18
                x: 276.85
                y:13.5
                source: "qrc:/Src/image_20/918/heart.svg"
            }
            // Song now play
            Text{
                id: nameMusicText
                width: 146
                height: 20
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter:  parent.horizontalCenter
                //text: nowplay.nameNowPlayingSong
                font.pixelSize: 18
                font.family: "Poppins"
                font.weight: Font.Bold
            }
            Text {
                id: nameAuthorText
                //text: "1000 Gecks"
                width: 100
                height: 20
                y:25
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter:  parent.horizontalCenter
                font.pixelSize: 18
                font.family: "Poppins"
                font.weight: Font.Normal
            }
        }
        //fame Now Playing
        Text {
            id: nowPlaying
            width: 114
            height:20
            x: 532
            y: 21
            text: qsTr("Now playing")
            font.pixelSize: 18
            font.family: "Poppins"
            font.weight: Font.Bold
            color: "#333333"
        }
        //startTimeMusic
        Text {
            id: timeStartMusic
            width: 25
            height:15
            x: 392
            y: 452
            text: qsTr("00:00")
            font.pixelSize: 14
            font.family: "Poppins"
            font.weight: Font.Normal
        }
        //endTimeMusic
        Text {
            id: timeEndMusic
            width: 25
            height:15
            x: 759
            y: 452
            text: qsTr("00:00")
            font.pixelSize: 14
            font.family: "Poppins"
            font.weight: Font.Normal
        }
        //musicTimeBar
        Rectangle{

            width: 391
            height: 5
            x: 394
            y: 474
            color: "#828282"
        }
        Rectangle{
            id:slideBarmusic
            width: 0
            height: 5
            x: 394
            y: 474
            color: "Green"
        }
        //Fame 914
        Rectangle{
            width: 454
            height: 64
            x: 362
            y: 510
            // play/pause button
            Rectangle{
                height:64
                width: 64
                x:195.5
                y:0
                Image {
                    id: playbutton
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectFit
                    source:nowplay.playStateNowPlayingSong ? "qrc:/Src/image_20/914/images.png" : "qrc:/Src/image_20/914/playbutton.svg"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if(nowplay.playStateNowPlayingSong === false){
                                nowplay.setPlayStateNowPlayingSong(true)
                                nowplay.play()

                            } else{
                                nowplay.setPlayStateNowPlayingSong(false)
                            }
                        }
                    }
                }
            }
            Image{
                id: previousButton
                height:16
                width: 21.4
                x:126.1
                y:24
                source: "qrc:/Src/image_20/914/left.svg"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        nowplay.previous()
                    }
                }
            }
            Image{
                id: nextButton
                height:16
                width: 21.4
                x:307.5
                y:24
                source: "qrc:/Src/image_20/914/right.svg"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
//                        nowplay.next(listNextSong.model.get(curentIndex).name
//                                     ,playnextmodel.model[1].image
//                                     ,playnextmodel.model[1].author
//                                     ,playnextmodel.model[1].time
//                                     ,0)
                        console.log(listNextSong.model(1).name)
                    }
                }
            }
            Image{
                id: repeatbutton
                height:20.39
                width: 21.11
                x:364.89
                y:21.3
                source: "qrc:/Src/image_20/914/repeat.svg"
            }
            Image{
                id: randombutton
                height:20.39
                width: 21.11
                x:68.99
                y:21.8
                source: "qrc:/Src/image_20/914/random.svg"
            }
        }
        //Fame 915
        Rectangle{
            width: 321.37
            height: 14
            x: 428
            y: 600
            Image{
                id: volumeUp
                height:14
                width: 16.23
                x:305.14
                y:0
                source: "qrc:/Src/image_20/915/Volume2.svg"
            }
            Image{
                id: volumeDown
                height:14
                width: 13.14
                x:0
                y:0
                source: "qrc:/Src/image_20/915/Volume1.svg"
            }
            Rectangle{
                width: 260
                height: 2
                x: 29.14
                y: 7
                color: "#828282"
            }
            Rectangle{
                id: slideBarVolumeUp
                width: 195
                height: 2
                x: 29.14
                y: 7
                color: "green"
            }
        }
        //Fame 25
        Rectangle{
            width: 2
            height:690
            x:362
            y:0
            color: "#eeeee4"
        }

        //line 27
        Rectangle{
            width: 2
            height:690
            x:816
            y:0
            color: "#eeeee4"
        }
        //fame 25
        Rectangle{
            width: 54
            height: 186
            y: 136

            Image {
                id: fame24
                height:42
                width: 42
                x: 6
                y: 0
                source: "qrc:/Src/image_20/25/Frame24.svg"
            }
            Image {
                id: fame23
                height:42
                width: 42
                x: 6
                y: 48
                source: "qrc:/Src/image_20/25/Frame23.svg"
            }
            Image {
                id: fame20
                height:42
                width: 42
                x: 6
                y: 144
                source: "qrc:/Src/image_20/25/Frame20.svg"
            }
            Image {
                id: fame19
                height:42
                width: 42
                x: 6
                y: 96
                source: "qrc:/Src/image_20/25/Frame19.svg"
            }
        }
        //fame 27
        Rectangle{
            width: 42
            height: 84
            y: 600
            x: 6
            Image {
                id: fame22
                height:42
                width: 42
                x: 0
                y: 0
                source: "qrc:/Src/image_20/27/Frame22.svg"
            }
            Image {
                id: fame26
                height:42
                width: 42
                x: 0
                y: 42

                source: "qrc:/Src/image_20/27/Frame26.svg"
            }
        }
        //line 1
        Rectangle{
            width: 36
            height: 1
            y: 122
            x: 9
            color: "#eeeee4"
        }
        //accout image
        Image {
            id: accoutImage
            width: 32
            height: 32
            x: 11
            y: 67
            source: "qrc:/Src/image_20/Ellipse 13.png"
        }
        //master Card
        Image{
            width: 32
            height: 32
            x: 11
            y: 21
            source: "qrc:/Src/image_20/mastercard-line.svg"
        }
        // Discover+topchart+album+you may like
        Rectangle{
            width: 275
            height: 719
            x:73
            //fame album
            Rectangle{
                width: 275
                height: 342
                y:168
                ScrollView{
                    anchors.fill: parent
                    GridView{
                        anchors.fill: parent
                        cellWidth: parent.width/2
                        cellHeight: parent.height/2
                        model: topchartmodel
                        clip: true
                        delegate: Rectangle{
                            id: albbumRectangle
                            width: 120
                            height: 162

                            Image {
                                id:topChart_imageSong
                                width:120
                                height:120
                                fillMode: Image.PreserveAspectFit
                                visible: false
                                source: model.image
                            }
                            OpacityMask {
                                anchors.fill: topChart_imageSong
                                source: topChart_imageSong
                                maskSource: Rectangle {
                                    width: topChart_imageSong.width
                                    height: topChart_imageSong.height
                                    radius: 20
                                    visible: false // this also needs to be invisible or it will cover up the image
                                }
                            }
                            Text{
                                id:topChart_nameSong
                                width: 96
                                height: 15
                                y: 126
                                x: 4
                                font.pixelSize: 14
                                font.family: "Poppins"
                                font.weight: Font.Bold
                                text: model.name
                            }
                            Text {
                                id:topChart_authorSong
                                x: 4
                                y: 143
                                width:120
                                height: 13
                                font.pixelSize: 12
                                font.family: "Poppins"
                                font.weight: Font.Normal
                                text: model.author +" - "+ model.year
                            }
                            MouseArea{
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered:{
                                    albbumRectangle.color = "#e2e1e6"
                                    topChart_imageSong.opacity = 0.5
                                    topChart_nameSong.opacity = 0.5
                                    topChart_authorSong.opacity = 0.5
                                }
                                onExited: {
                                    albbumRectangle.color = "white"
                                    topChart_imageSong.opacity = 1
                                    topChart_nameSong.opacity = 1
                                    topChart_authorSong.opacity = 1
                                }
                                onPressed: {
                                    albbumRectangle.color = "grey"

                                    console.log(topChart_nameSong.text)
                                }

                            }
                        }
                    }
                }

            }

            //fame You may like
            Rectangle{
                width: 261
                height: 112
                y:575
                ScrollView{
                    anchors.fill: parent
                    ListView{

                        anchors.fill: parent
                        clip: true
                        spacing: 9
                        model: mayyoulikemodel
                        delegate: Rectangle{
                            id: mayYoulikeRectangle
                            width: 261
                            height:42
                            Image {
                                id: image_mayYoulike
                                width: 42
                                height: 42
                                visible: false
                                fillMode: Image.PreserveAspectFit
                                source: model.image
                            }
                            OpacityMask {
                                anchors.fill: image_mayYoulike
                                source: image_mayYoulike
                                maskSource: Rectangle {
                                    width: image_mayYoulike.width
                                    height: image_mayYoulike.height
                                    radius: 5
                                    visible: false // this also needs to be invisible or it will cover up the image
                                }
                            }
                            Text {
                                id: name_mayYoulike
                                width:41
                                height:15
                                x: 54
                                y: 6
                                font.pixelSize: 14
                                font.family: "Poppins"
                                font.weight: Font.Bold
                                text: model.name
                            }
                            Text {
                                id: author_mayYoulike
                                width:134
                                height:13
                                x: 54
                                y: 23
                                font.pixelSize: 12
                                font.family: "Poppins"
                                text: model.author
                            }
                            Text {
                                id: year_mayYoulike
                                width:27
                                height:13
                                x: 230
                                y: 23
                                font.pixelSize: 12
                                font.family: "Poppins"
                                text:model.year
                            }
                            Text {
                                id: time_mayYoulike
                                width:37
                                height:15
                                x: 230
                                y: 6
                                font.pixelSize: 12
                                font.family: "Poppins"
                                text: model.time
                            }
                            MouseArea{
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered:{
                                    mayYoulikeRectangle.color = "#e2e1e6"
                                    image_mayYoulike.opacity = 0.5
                                    name_mayYoulike.opacity = 0.5
                                    author_mayYoulike.opacity = 0.5
                                    year_mayYoulike.opacity = 0.5
                                    time_mayYoulike.opacity = 0.5
                                }
                                onExited: {
                                    mayYoulikeRectangle.color = "white"
                                    image_mayYoulike.opacity = 1
                                    name_mayYoulike.opacity = 1
                                    author_mayYoulike.opacity = 1
                                    year_mayYoulike.opacity = 1
                                    time_mayYoulike.opacity = 1
                                }
                                onPressed: {
                                    mayYoulikeRectangle.color = "grey"
                                    console.log(name_mayYoulike.text)
                                }

                            }

                        }
                    }
                }
            }
            //Text You DIsco and Top-chart
            Rectangle{
                width: 275
                height: 168
                //Discovery new music
                Text{
                    id: discoverText
                    width: 181
                    height: 70
                    y: 18
                    font.family: "Poppins"
                    font.pixelSize: 32
                    font.weight: Font.Bold
                    text: qsTr("Discover \nNew music")
                    color: "#333333"
                }
                //Text Top-Chart
                Text{
                    width: 94
                    height: 20
                    y: 129
                    font.family: "Poppins"
                    font.weight: Font.Bold
                    font.pixelSize: 18
                    text: qsTr("Top Chart")
                    color: "#333333"
                }
                //Text Week
                Text{
                    width: 45
                    height: 18
                    y: 129
                    x:201.51
                    font.family: "Poppins"
                    font.weight: Font.Normal
                    font.pixelSize: 16
                    text: qsTr("Week")
                    color: "#828282"
                }
            }
            //Text: You may like
            Rectangle{
                width: 275
                height: 65
                y: 510
                Text{
                    width: 117
                    height: 20
                    y:24
                    font.family: "Poppins"
                    font.weight: Font.Bold
                    font.pixelSize: 18
                    text: qsTr("You may like")
                    color: "#333333"
                }
            }
        }
        //fame Play next
        Rectangle{
            width: 264
            height: 597
            x: 832
            y: 90
            ScrollView{
                width:261
                height: 570
                y: 27
                ListView {
                    id:listNextSong
                    anchors.fill: parent
                    model: playnextmodel
                    //interactive: false
                    clip: true
                    spacing: 6
                    delegate: Rectangle{
                        id: playingNextRectangle
                        width: 261
                        height:42
                        Image {
                            id: imageSong
                            width: 42
                            height: 42
                            x: 22
                            visible: false
                            fillMode: Image.PreserveAspectFit
                            source: model.image
                        }
                        OpacityMask {
                            anchors.fill: imageSong
                            source: imageSong
                            maskSource: Rectangle {
                                width: imageSong.width
                                height: imageSong.height
                                radius: 20
                                visible: false // this also needs to be invisible or it will cover up the image
                            }
                        }
                        Text {
                            id: nameSong
                            width:90.33
                            height:15
                            x: 74
                            y: 6
                            font.pixelSize: 14
                            font.family: "Poppins"
                            font.weight: Font.Bold
                            text: model.name
                        }
                        Text {
                            id: authorSong
                            width:72
                            height:13
                            x: 74
                            y: 23
                            font.pixelSize: 12
                            font.family: "Poppins"
                            text: model.author
                        }
                        Text {
                            id: yearSong
                            width:27
                            height:13
                            x: 230
                            y: 23
                            font.pixelSize: 12
                            font.family: "Poppins"
                            text: model.year
                        }
                        Text {
                            id: timeSong
                            width:26
                            height:15
                            x: 225
                            y: 6
                            font.pixelSize: 12
                            font.family: "Poppins"
                            text: model.time
                        }
                        MouseArea{
                            //id:
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered:{
                                playingNextRectangle.color = "#e2e1e6"
                                imageSong.opacity = 0.5
                                nameSong.opacity = 0.5
                                authorSong.opacity = 0.5
                                yearSong.opacity = 0.5
                                timeSong.opacity = 0.5
                            }
                            onExited: {
                                playingNextRectangle.color = "white"
                                imageSong.opacity = 1
                                nameSong.opacity = 1
                                authorSong.opacity = 1
                                yearSong.opacity = 1
                                timeSong.opacity = 1
                            }
                            onPressed: {
                                playingNextRectangle.color = "grey"
                                //console.log(imageSong.source)
                                nowplay.setNameNowPlayingSong(nameSong.text)
                                nowplay.setImageNowPlayingSong(imageSong.source)
                                nowplay.setAuthorNowPlayingSong(authorSong.text)
                                nowplay.setTimeNowPlayingSong(timeSong.text)
                                nowplay.setPlayStateNowPlayingSong(true)
                                nowplay.setDurationNowPlayingSong(0)
                                nowplay.play()
                            }

                        }

                    }
                }
            }
        }
        // TExt Playing nec
        Rectangle{
            width: 296
            height:115
            x:832
            y:0
            Text{
                width: 86
                height: 15
                y:90
                font.family: "Poppins"
                font.pixelSize: 14
                font.weight: Font.Normal
                text: qsTr("Playing next")
                color: "#333333"
            }
            Text{
                id: tracklistText
                width: 113
                height: 27
                x: 0
                y: 21
                font.family: "Poppins"
                font.pixelSize: 24
                font.weight: Font.Bold
                font.bold: true
                text: qsTr("Track list")
                color: "#333333"
            }
        }

    }
}
