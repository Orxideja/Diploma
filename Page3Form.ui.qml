import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    font.family: "Arial"

    title: qsTr("Тест на логику")

    Label {
        text: qsTr("You are on Page 3.")
        anchors.centerIn: parent
    }

    TextArea {
        id: textArea
        x: 52
        y: 37
        width: 476
        height: 143
        text: ltest.question
        renderType: Text.QtRendering
        placeholderText: ""
    }

    ListView {
        id: listView
        x: 52
        y: 214
        width: 476
        height: 160
        boundsBehavior: Flickable.StopAtBounds
        delegate: Item {
            x: 5
            width: 80
            height: 40
            property alias mouseArea: mouseArea
            Row {
                id: row1

                Rectangle {
                    width: 40
                    height: 40
                    color: "#2525b6"

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            ltest.choose(index)
                        }
                    }
                }

                Text {
                    text: modelData
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }

                spacing: 10
            }
        }
        model: ltest.answers
    }
}
