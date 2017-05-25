import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
    width: 512
    height: 512
    visible: true

    property double zoom_level: mapData.get_zoom() // 10
    property double map_latitude: mapData.get_lat() //44.5638
    property double map_longitude: mapData.get_long() //-123.2794
    property bool circle_state: mapData.get_circleState() //false
    //property ListModel rocketPath: mapData.get_rocketPath()

    property bool focusRocket: mapData.get_focusRocketState()

    Connections {
            target: mapData
            onZoomChanged: zoom_level = mapData.get_zoom()
            onLatitudeChanged: map_latitude = mapData.get_lat()
            onLongitudeChanged: map_longitude = mapData.get_long()
            onCircleChanged: circle_state = mapData.get_circleState()
            onFocusOptionChanged: focusRocket = mapData.get_focusRocketState()
            onRocketPathChanged: rocketPath.addCoordinate(QtPositioning.coordinate(map_latitude, map_longitude))
            onMapTypeChanged: map.activeMapType = map.supportedMapTypes[mapData.get_mapType()]
    }

    Connections {
            target: mapData
            onFocusRocketChanged: map.center = getMapFocus()
    }

    Plugin {
        id: osmPlugin
        name: "osm"
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }

        //PluginParameter { name: "osm.useragent"; value: "RADAV" }
        //PluginParameter { name: "osm.mapping.providersrepository.address"; value: "http://mt1.google.com/vt/lyrs=s" }
        //PluginParameter { name: "osm.mapping.custom.host"; value: "https://tile.thunderforest.com/outdoors/0/0/0.png?apikey=3893a8e9c6ff4e99a6839ad9c43493c7" }

        PluginParameter {
        name: "googlemaps.useragent"
        value: "OSU Rocketry RADAV"
        }
        PluginParameter {
        name: "googlemaps.route.apikey"
        value: "AIzaSyBgoNlqfN3Po0iqgKTQiG1J2u9c3plIyqo"
        }
        PluginParameter {
        name: "googlemaps.maps.apikey"
        value: "AIzaSyBgoNlqfN3Po0iqgKTQiG1J2u9c3plIyqo"
        }
        PluginParameter {
        name: "googlemaps.maps.tilesize"
        value: "256"
        }
    }



    /*PositionSource {
        id: positionSource
    }*/


    Map {
        id: map
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(43.7958, -120.65164) // defaults to OSU
        zoomLevel: zoom_level
        copyrightsVisible: false
        activeMapType: supportedMapTypes[1]

        MapQuickItem {
            id: rocketMarker
            anchorPoint.x: rocket_image.width/2
            anchorPoint.y: rocket_image.height/2
            coordinate: QtPositioning.coordinate(map_latitude, map_longitude) // defaults to OSU
            scale: 0.05

            visible: true

            sourceItem: Image {
                id:rocket_image
                source: "qrc:/Resources/images/rocket_icon.png"
            }
        }

        MapPolyline {
                id:rocketPath
                line.width: 3
                line.color: 'red'
        }

        MapCircle {
            center: QtPositioning.coordinate(map_latitude, map_longitude) // defaults to OSU
            /*{
                latitude: 44.5638
                longitude: -123.2794
            }*/
            radius: 30 //meters --> ~90 feet based on test launch
            color: 'red'
            opacity : 0.4
            border.width: 1 //pixels
            visible: circle_state
        }
    }

    function getMapFocus()
    {
        var mapFocus
        var lastCoord = QtPositioning.coordinate(map_latitude, map_longitude)
        if(focusRocket == true)
        {
            map.center = QtPositioning.coordinate(map_latitude, map_longitude)
            mapFocus = map.center
        }
        else
        {
           //map.center = QtPositioning.coordinate(44.5638, -123.2794)
            mapFocus = map.center
        }

        return mapFocus
    }
}
