import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    font.family: "Arial"

    title: qsTr("Тест на логику")

    TextArea {
        id: textArea
        x: 52
        y: 37
        width: 476
        height: 143
        text: ltest.question
        font.pointSize: 10
        textFormat: Text.RichText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
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
                        hoverEnabled: true
                        // @disable-check M223
                        onClicked: {
                            // @disable-check M222
                            ltest.choose(index)
                        }
                        // @disable-check M223
                        onEntered: {
                            parent.radius = 15
                            parent.color = "blue"
                        }
                        // @disable-check M223
                        onExited: {
                            parent.radius = 0
                            parent.color = "#2525b6"
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
