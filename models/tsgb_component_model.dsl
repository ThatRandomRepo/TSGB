
FUNCTION tsgb_component_model
VAR
  REAL gridFreqHz, gridRoCoFHzps, driveRpm
  REAL genRpm, torqueCommandNm
  INT gearIndex

BEGIN
  CALL tsgb_control(gridFreqHz, gridRoCoFHzps, driveRpm, torqueCommandNm, genRpm, gearIndex)
END
