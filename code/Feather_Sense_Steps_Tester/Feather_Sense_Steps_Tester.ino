/**
 * Quick sketch to test the step counter on Adafruit's Feather Sense
 * 
 * Version 1.0
 *
 * Copyright (C) 2021  jens alexander ewald <jens@poetic.systems>
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * ------
 * 
 * This project has received funding from the European Union’s Horizon 2020
 * research and innovation programme under the Marie Skłodowska-Curie grant
 * agreement No. 813508.
 */
#include <Adafruit_LSM6DS33.h>

Adafruit_LSM6DS33 sensor;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  sensor.begin_I2C();
  sensor.enablePedometer(true);
  sensor.resetPedometer();
}

void loop() {
  Serial.println(sensor.readPedometer());
  sensor.resetPedometer();
  delay(1000);
}
