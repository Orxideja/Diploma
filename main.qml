import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.0

ApplicationWindow {
    id: window
    visible: true
    visibility: Window.FullScreen
    title: qsTr("Программа для тестирования")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.20
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Социальный тест")
                width: parent.width
                enabled: ltest.completed.includes(0) ? false : true;
                onClicked: {
                    ltest.test = 'social'
                    stackView.push("Page3Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Профессиональный тест")
                width: parent.width
                enabled: ltest.completed.includes(1) ? false : true;
                onClicked: {
                    ltest.test = 'prof'
                    stackView.push("Page3Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Тест на дополнительные знания")
                width: parent.width
                enabled: ltest.completed.includes(2) ? false : true;
                onClicked: {
                    ltest.test = 'logic'
                    stackView.push("Page3Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Выход")
                width: parent.width
                onClicked: {
                    drawer.close()
                    Qt.quit()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
        objectName: "baseView"
        function home() {
            stackView.pop()
        }

        function previewTest() {
            stackView.push("TestDescriptionForm.ui.qml")
        }

        function enterTest() {
            stackView.push("Page3Form.ui.qml")
        }
    }
}
