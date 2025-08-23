
FUNCTION tsgb_control
VAR
  REAL gridFreqHz, gridRoCoFHzps, driveRpm
  REAL torqueCommandNm, genRpm
  INT gearIndex

BEGIN
  ! Gear shifting thresholds based on RoCoF
  IF gridRoCoFHzps < -1.0 THEN
    gearIndex := 1
  ELSIF gridRoCoFHzps < -0.8 THEN
    gearIndex := 2
  ELSIF gridRoCoFHzps < -0.6 THEN
    gearIndex := 3
  ELSIF gridRoCoFHzps < -0.4 THEN
    gearIndex := 4
  ELSIF gridRoCoFHzps < -0.2 THEN
    gearIndex := 5
  ELSE
    gearIndex := 6
  ENDIF

  ! Clamp gearIndex to 1–12
  IF gearIndex < 1 THEN gearIndex := 1 ENDIF
  IF gearIndex > 12 THEN gearIndex := 12 ENDIF

  ! Calculate generator RPM based on drive RPM and gear ratio
  genRpm := driveRpm / Lookup("gearbox_curve.csv", "GearIndex", gearIndex, "Ratio")

  ! Calculate torque offset from table
  torqueCommandNm := Lookup("gearbox_curve.csv", "GearIndex", gearIndex, "TorqueOffsetNm")

END
