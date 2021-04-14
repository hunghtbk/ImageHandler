import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.1
import "componentCreation.js" as MyScript

Window {
    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")
    property int objectCounter: 0

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            UIBridge.log("abcd");
        }
    }
    MouseArea {
        id: mouseParent
        anchors.fill: parent
    }

    Rectangle {
        x: 690
        y: 0
        width: 100
        height: 40
        color: "green"
        Text {
            anchors.centerIn: parent
            text: "Select Image"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                fileDialog.visible = true
            }
        }
    }

//    ImageElement {
//        id: img1
//        x: 0
//        y: 0
//        width: 200
//        height: 200
//        visible: true
//    }

//    Connections {
//        target: img1
//        ignoreUnknownSignals: true
//        onChangePosition: {
//            UIBridge.mainQMLCallChangePosition(xPosition, yPosition);
//            img1.x = img1.x + xPosition - img1.width/2
//            img1.y = img1.y + yPosition - img1.height/2
//        }
//    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            var str = ""
            for(var i in fileDialog.fileUrls){
                var url = fileDialog.fileUrls[i]
                str += Qt.resolvedUrl(url)
            }
            objectCounter = objectCounter + 1;
            var objName = "hunght" + objectCounter
            MyScript.createSpriteObjects(str, objName);
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false
    }
}
