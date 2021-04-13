import QtQuick 2.5
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0
Item {
    id: main_item
    width: 200
    height: 200
    property bool isSelected: false
    property string image_source: "qrc:/image/house.png"
    signal changePosition(var xPosition, var yPosition)
    Rectangle {
        id: main_image
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        Image {
            id: content_image
            anchors.fill: parent
            source: image_source
        }

        MouseArea {
            id: image_mouse
            anchors.fill: parent
            propagateComposedEvents: true
            property int xposition: 0
            property int yposition: 0

            onClicked: {
                if (isSelected) {
                    arrow_image.visible = false
                    isSelected = false
                    rotattion_image.visible = false
                } else {
                    arrow_image.visible = true
                    isSelected = true
                    rotattion_image.visible = true
                }

            }
            onPositionChanged: {
                main_item.changePosition(mouseX, mouseY);
            }

        }
    }
    Rectangle {
        id: mask
        width: 20
        height: 20
        radius: 250
        visible: false
    }
    Image {
        id: rotattion_image
        y: 0
        anchors.horizontalCenter: parent.horizontalCenter
        width: 20
        height: 20
        visible: false
        source: "qrc:/image/rotation.png"
        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                content_image.rotation = content_image.rotation + 1
            }
            onPressAndHold: {
                elapsedTimer.start();
            }
            onReleased: {
                elapsedTimer.stop();
            }
        }
        Timer  {
            id: elapsedTimer
            interval: 10
            running: false
            repeat: true
            onTriggered: {
                content_image.rotation = content_image.rotation + 1
            }
        }
    }

    Image {
        id: arrow_image
        y: parent.height - 21
        x: parent.width - 21
        width: 20
        height: 20
        source: "qrc:/image/arrow.png"
        visible: false

        MouseArea {
            anchors.fill: parent
            property int mountYofArrow : arrow_image.y + arrow_image.height/2

            onClicked: {
                main_item.width = main_item.width + 1
                main_item.height = main_item.height + 1
            }

            onPressAndHold: {
                main_item.width = main_item.width + 1
                main_item.height = main_item.height + 1

                console.log(mouseX)
            }

            onMouseXChanged: {
                var arrow_current_X = arrow_image.x
                var arrow_mouse_x = mouseX + arrow_image.x
                if (arrow_mouse_x > arrow_current_X) {
                    main_item.width = main_item.width + 1
                } else {
                    main_item.width = main_item.width - 1
                }
            }

            onMouseYChanged: {
                var arrow_current_Y = arrow_image.y
                var arrow_mouse_y = mouseY + arrow_image.y
                if (arrow_mouse_y > arrow_current_Y) {
                    main_item.height = main_item.height + 1
                } else {
                    main_item.height = main_item.height - 1
                }
            }
        }
    }

}
