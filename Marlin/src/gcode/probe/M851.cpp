/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "../gcode.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../../module/probe.h"

void GcodeSuite::M851() {
<<<<<<< HEAD

  // Show usage with no parameters
  if (!parser.seen("XYZ")) {
    SERIAL_ECHOLNPAIR(MSG_PROBE_OFFSET " X", probe_offset[X_AXIS], " Y", probe_offset[Y_AXIS], " Z", probe_offset[Z_AXIS]);
    return;
  }

  float offs[XYZ] = { probe_offset[X_AXIS], probe_offset[Y_AXIS], probe_offset[Z_AXIS] };

  bool ok = true;

  if (parser.seenval('X')) {
    const float x = parser.value_float();
    if (WITHIN(x, -(X_BED_SIZE), X_BED_SIZE))
      offs[X_AXIS] = x;
    else {
      SERIAL_ECHOLNPAIR("?X out of range (-", int(X_BED_SIZE), " to ", int(X_BED_SIZE), ")");
      ok = false;
    }
  }

  if (parser.seenval('Y')) {
    const float y = parser.value_float();
    if (WITHIN(y, -(Y_BED_SIZE), Y_BED_SIZE))
      offs[Y_AXIS] = y;
    else {
      SERIAL_ECHOLNPAIR("?Y out of range (-", int(Y_BED_SIZE), " to ", int(Y_BED_SIZE), ")");
      ok = false;
    }
  }

  if (parser.seenval('Z')) {
    const float z = parser.value_float();
    if (WITHIN(z, Z_PROBE_OFFSET_RANGE_MIN, Z_PROBE_OFFSET_RANGE_MAX))
      offs[Z_AXIS] = z;
    else {
      SERIAL_ECHOLNPAIR("?Z out of range (", int(Z_PROBE_OFFSET_RANGE_MIN), " to ", int(Z_PROBE_OFFSET_RANGE_MAX), ")");
      ok = false;
    }
  }

  // Save the new offsets
  if (ok) COPY(probe_offset, offs);
=======
  if (parser.seenval('Z')) {
    const float value = parser.value_linear_units();
    if (WITHIN(value, Z_PROBE_OFFSET_RANGE_MIN, Z_PROBE_OFFSET_RANGE_MAX))
      zprobe_zoffset = value;
    else
      SERIAL_ERROR_MSG("?Z out of range (" STRINGIFY(Z_PROBE_OFFSET_RANGE_MIN) " to " STRINGIFY(Z_PROBE_OFFSET_RANGE_MAX) ")");
    return;
  }
  SERIAL_ECHO_START();
  SERIAL_ECHOLNPAIR(MSG_PROBE_Z_OFFSET ": ", zprobe_zoffset);
>>>>>>> parent of df1e51258... Add M851 X Y probe offsets (#15202)
}

#endif // HAS_BED_PROBE
