#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T18:22:59
#
#-------------------------------------------------

QT       += core gui opengl quick network multimedia
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport core designer

lessThan(QT_MAJOR_VERSION, 5) {
   CONFIG += designer
}

CONFIG += plugin release

#TARGET = TestApplication
#TEMPLATE = app

TEMPLATE = app
TARGET = $$qtLibraryTarget($$TARGET)
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

INCLUDEPATH += .

SOURCES += main.cpp\
        mainwindow.cpp \
    settingsdialog.cpp \
    dataprocessing.cpp \
    qcustomplot.cpp \
    graphs.cpp \
    BmpToTexture.cpp \
    glwidget.cpp \
    loadobjfile.cpp \
    mpu9250.cpp \
    createprofile.cpp \
    mavlinkIncludes/tcplink.cpp \
    mavproxyint.cpp \
    LED.cpp \
    LEDPlugin.cpp

HEADERS  += mainwindow.h \
    settingsdialog.h \
    qcustomplot.h \
    dataprocessing.h \
    graphs.h \
    glwidget.h \
    mpu9250.h \
    createprofile.h \
    mavlinkIncludes/common/common.h \
    mavlinkIncludes/common/mavlink.h \
    mavlinkIncludes/common/mavlink_msg_actuator_control_target.h \
    mavlinkIncludes/common/mavlink_msg_adsb_vehicle.h \
    mavlinkIncludes/common/mavlink_msg_altitude.h \
    mavlinkIncludes/common/mavlink_msg_att_pos_mocap.h \
    mavlinkIncludes/common/mavlink_msg_attitude.h \
    mavlinkIncludes/common/mavlink_msg_attitude_quaternion.h \
    mavlinkIncludes/common/mavlink_msg_attitude_quaternion_cov.h \
    mavlinkIncludes/common/mavlink_msg_attitude_target.h \
    mavlinkIncludes/common/mavlink_msg_auth_key.h \
    mavlinkIncludes/common/mavlink_msg_autopilot_version.h \
    mavlinkIncludes/common/mavlink_msg_battery_status.h \
    mavlinkIncludes/common/mavlink_msg_camera_trigger.h \
    mavlinkIncludes/common/mavlink_msg_change_operator_control.h \
    mavlinkIncludes/common/mavlink_msg_change_operator_control_ack.h \
    mavlinkIncludes/common/mavlink_msg_collision.h \
    mavlinkIncludes/common/mavlink_msg_command_ack.h \
    mavlinkIncludes/common/mavlink_msg_command_int.h \
    mavlinkIncludes/common/mavlink_msg_command_long.h \
    mavlinkIncludes/common/mavlink_msg_control_system_state.h \
    mavlinkIncludes/common/mavlink_msg_data_stream.h \
    mavlinkIncludes/common/mavlink_msg_data_transmission_handshake.h \
    mavlinkIncludes/common/mavlink_msg_debug.h \
    mavlinkIncludes/common/mavlink_msg_debug_vect.h \
    mavlinkIncludes/common/mavlink_msg_distance_sensor.h \
    mavlinkIncludes/common/mavlink_msg_encapsulated_data.h \
    mavlinkIncludes/common/mavlink_msg_estimator_status.h \
    mavlinkIncludes/common/mavlink_msg_extended_sys_state.h \
    mavlinkIncludes/common/mavlink_msg_file_transfer_protocol.h \
    mavlinkIncludes/common/mavlink_msg_follow_target.h \
    mavlinkIncludes/common/mavlink_msg_global_position_int.h \
    mavlinkIncludes/common/mavlink_msg_global_position_int_cov.h \
    mavlinkIncludes/common/mavlink_msg_global_vision_position_estimate.h \
    mavlinkIncludes/common/mavlink_msg_gps2_raw.h \
    mavlinkIncludes/common/mavlink_msg_gps2_rtk.h \
    mavlinkIncludes/common/mavlink_msg_gps_global_origin.h \
    mavlinkIncludes/common/mavlink_msg_gps_inject_data.h \
    mavlinkIncludes/common/mavlink_msg_gps_input.h \
    mavlinkIncludes/common/mavlink_msg_gps_raw_int.h \
    mavlinkIncludes/common/mavlink_msg_gps_rtcm_data.h \
    mavlinkIncludes/common/mavlink_msg_gps_rtk.h \
    mavlinkIncludes/common/mavlink_msg_gps_status.h \
    mavlinkIncludes/common/mavlink_msg_heartbeat.h \
    mavlinkIncludes/common/mavlink_msg_high_latency.h \
    mavlinkIncludes/common/mavlink_msg_highres_imu.h \
    mavlinkIncludes/common/mavlink_msg_hil_actuator_controls.h \
    mavlinkIncludes/common/mavlink_msg_hil_controls.h \
    mavlinkIncludes/common/mavlink_msg_hil_gps.h \
    mavlinkIncludes/common/mavlink_msg_hil_optical_flow.h \
    mavlinkIncludes/common/mavlink_msg_hil_rc_inputs_raw.h \
    mavlinkIncludes/common/mavlink_msg_hil_sensor.h \
    mavlinkIncludes/common/mavlink_msg_hil_state.h \
    mavlinkIncludes/common/mavlink_msg_hil_state_quaternion.h \
    mavlinkIncludes/common/mavlink_msg_home_position.h \
    mavlinkIncludes/common/mavlink_msg_landing_target.h \
    mavlinkIncludes/common/mavlink_msg_local_position_ned.h \
    mavlinkIncludes/common/mavlink_msg_local_position_ned_cov.h \
    mavlinkIncludes/common/mavlink_msg_local_position_ned_system_global_offset.h \
    mavlinkIncludes/common/mavlink_msg_log_data.h \
    mavlinkIncludes/common/mavlink_msg_log_entry.h \
    mavlinkIncludes/common/mavlink_msg_log_erase.h \
    mavlinkIncludes/common/mavlink_msg_log_request_data.h \
    mavlinkIncludes/common/mavlink_msg_log_request_end.h \
    mavlinkIncludes/common/mavlink_msg_log_request_list.h \
    mavlinkIncludes/common/mavlink_msg_manual_control.h \
    mavlinkIncludes/common/mavlink_msg_manual_setpoint.h \
    mavlinkIncludes/common/mavlink_msg_memory_vect.h \
    mavlinkIncludes/common/mavlink_msg_message_interval.h \
    mavlinkIncludes/common/mavlink_msg_mission_ack.h \
    mavlinkIncludes/common/mavlink_msg_mission_clear_all.h \
    mavlinkIncludes/common/mavlink_msg_mission_count.h \
    mavlinkIncludes/common/mavlink_msg_mission_current.h \
    mavlinkIncludes/common/mavlink_msg_mission_item.h \
    mavlinkIncludes/common/mavlink_msg_mission_item_int.h \
    mavlinkIncludes/common/mavlink_msg_mission_item_reached.h \
    mavlinkIncludes/common/mavlink_msg_mission_request.h \
    mavlinkIncludes/common/mavlink_msg_mission_request_int.h \
    mavlinkIncludes/common/mavlink_msg_mission_request_list.h \
    mavlinkIncludes/common/mavlink_msg_mission_request_partial_list.h \
    mavlinkIncludes/common/mavlink_msg_mission_set_current.h \
    mavlinkIncludes/common/mavlink_msg_mission_write_partial_list.h \
    mavlinkIncludes/common/mavlink_msg_named_value_float.h \
    mavlinkIncludes/common/mavlink_msg_named_value_int.h \
    mavlinkIncludes/common/mavlink_msg_nav_controller_output.h \
    mavlinkIncludes/common/mavlink_msg_optical_flow.h \
    mavlinkIncludes/common/mavlink_msg_optical_flow_rad.h \
    mavlinkIncludes/common/mavlink_msg_param_map_rc.h \
    mavlinkIncludes/common/mavlink_msg_param_request_list.h \
    mavlinkIncludes/common/mavlink_msg_param_request_read.h \
    mavlinkIncludes/common/mavlink_msg_param_set.h \
    mavlinkIncludes/common/mavlink_msg_param_value.h \
    mavlinkIncludes/common/mavlink_msg_ping.h \
    mavlinkIncludes/common/mavlink_msg_position_target_global_int.h \
    mavlinkIncludes/common/mavlink_msg_position_target_local_ned.h \
    mavlinkIncludes/common/mavlink_msg_power_status.h \
    mavlinkIncludes/common/mavlink_msg_radio_status.h \
    mavlinkIncludes/common/mavlink_msg_raw_imu.h \
    mavlinkIncludes/common/mavlink_msg_raw_pressure.h \
    mavlinkIncludes/common/mavlink_msg_rc_channels.h \
    mavlinkIncludes/common/mavlink_msg_rc_channels_override.h \
    mavlinkIncludes/common/mavlink_msg_rc_channels_raw.h \
    mavlinkIncludes/common/mavlink_msg_rc_channels_scaled.h \
    mavlinkIncludes/common/mavlink_msg_request_data_stream.h \
    mavlinkIncludes/common/mavlink_msg_resource_request.h \
    mavlinkIncludes/common/mavlink_msg_safety_allowed_area.h \
    mavlinkIncludes/common/mavlink_msg_safety_set_allowed_area.h \
    mavlinkIncludes/common/mavlink_msg_scaled_imu.h \
    mavlinkIncludes/common/mavlink_msg_scaled_imu2.h \
    mavlinkIncludes/common/mavlink_msg_scaled_imu3.h \
    mavlinkIncludes/common/mavlink_msg_scaled_pressure.h \
    mavlinkIncludes/common/mavlink_msg_scaled_pressure2.h \
    mavlinkIncludes/common/mavlink_msg_scaled_pressure3.h \
    mavlinkIncludes/common/mavlink_msg_serial_control.h \
    mavlinkIncludes/common/mavlink_msg_servo_output_raw.h \
    mavlinkIncludes/common/mavlink_msg_set_actuator_control_target.h \
    mavlinkIncludes/common/mavlink_msg_set_attitude_target.h \
    mavlinkIncludes/common/mavlink_msg_set_gps_global_origin.h \
    mavlinkIncludes/common/mavlink_msg_set_home_position.h \
    mavlinkIncludes/common/mavlink_msg_set_mode.h \
    mavlinkIncludes/common/mavlink_msg_set_position_target_global_int.h \
    mavlinkIncludes/common/mavlink_msg_set_position_target_local_ned.h \
    mavlinkIncludes/common/mavlink_msg_sim_state.h \
    mavlinkIncludes/common/mavlink_msg_statustext.h \
    mavlinkIncludes/common/mavlink_msg_sys_status.h \
    mavlinkIncludes/common/mavlink_msg_system_time.h \
    mavlinkIncludes/common/mavlink_msg_terrain_check.h \
    mavlinkIncludes/common/mavlink_msg_terrain_data.h \
    mavlinkIncludes/common/mavlink_msg_terrain_report.h \
    mavlinkIncludes/common/mavlink_msg_terrain_request.h \
    mavlinkIncludes/common/mavlink_msg_timesync.h \
    mavlinkIncludes/common/mavlink_msg_v2_extension.h \
    mavlinkIncludes/common/mavlink_msg_vfr_hud.h \
    mavlinkIncludes/common/mavlink_msg_vibration.h \
    mavlinkIncludes/common/mavlink_msg_vicon_position_estimate.h \
    mavlinkIncludes/common/mavlink_msg_vision_position_estimate.h \
    mavlinkIncludes/common/mavlink_msg_vision_speed_estimate.h \
    mavlinkIncludes/common/mavlink_msg_wind_cov.h \
    mavlinkIncludes/common/testsuite.h \
    mavlinkIncludes/common/version.h \
    mavlinkIncludes/checksum.h \
    mavlinkIncludes/mavlink_conversions.h \
    mavlinkIncludes/mavlink_helpers.h \
    mavlinkIncludes/mavlink_types.h \
    mavlinkIncludes/protocol.h \
    mavlinkIncludes/tcplink.h \
    tmpDPclass.h \
    mavproxyint.h \
    LED.h \
    LEDPlugin.h

FORMS    += mainwindow.ui \
    settingsdialog.ui \
  #  graphs.ui \
    createprofile.ui \
    mavproxyint.ui

DISTFILES += \
    icons/Connected-50.png \
    icons/Disconnected-48.png \
    accel-Data.csv \
    MavProxyInt.qml

RESOURCES += \
    myresources.qrc

RC_FILE = RADAV.rc

LIBS += opengl32.lib GlU32.lib
