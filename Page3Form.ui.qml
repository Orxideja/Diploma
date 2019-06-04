import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page
    font.family: "Arial"

    title: qsTr("Тест на дополнительные знания")

    TextArea {
        id: textArea
        width: 984
        height: 143
        readOnly: true
        text: ltest.question
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 10
        textFormat: Text.RichText
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.QtRendering
        placeholderText: ""
    }

    ListView {
        id: listView
        width: 736
        height: 264
        anchors.top: textArea.bottom
        anchors.topMargin: 47
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        boundsBehavior: Flickable.StopAtBounds
        delegate: Item {
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
