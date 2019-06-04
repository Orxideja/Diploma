import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.0

ApplicationWindow {
    id: window
    visible: true
    visibility: Window.FullScreen
    title: qsTr("Программа для тестирования")

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

        function endAllTests() {
            stackView.push("EndForm.ui.qml")
        }
    }
}
