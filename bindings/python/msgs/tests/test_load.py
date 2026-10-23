# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

def test_inclusion():
    import trintrin.bindings.msgs as ttm


def test_tactile_message_bindings():
    import trintrin.bindings.msgs as ttm

    frame = ttm.CompleteTactileFrame()
    frame.metadata.schema_version = 1
    frame.metadata.sequence = 42
    frame.metadata.timestamp_s = 1.25
    frame.metadata.all_sensors_valid = True

    force = ttm.ForceVector3()
    force.x = 1.0
    force.y = 2.0
    force.z = 3.0

    contact = ttm.TactileContactPoint()
    contact.contact_index = 0
    contact.x_mm = 4.0
    contact.y_mm = 5.0
    contact.z_mm = 6.0
    contact.force_n = 7.0

    sensor = ttm.CompleteTactileSensor()
    sensor.sensor_index = 0
    sensor.sensor_name = "THUMB_PROXIMAL"
    sensor.valid = True
    sensor.resultant_force_n = force
    sensor.contacts = [contact]
    sensor.temperature_c = 25.0
    frame.sensors = [sensor]

    assert frame.metadata.sequence == 42
    assert frame.sensors[0].sensor_name == "THUMB_PROXIMAL"
    assert frame.sensors[0].resultant_force_n.z == 3.0
    assert frame.sensors[0].contacts[0].force_n == 7.0

    port = ttm.BufferedPortCompleteTactileFrame()
    assert port.isClosed()
