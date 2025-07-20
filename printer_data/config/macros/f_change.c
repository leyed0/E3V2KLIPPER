######################################################################
# Filament Change
######################################################################

# M600: Filament Change. This macro will pause the printer, move the
# tool to the change position, and retract the filament 50mm. Adjust
# the retraction settings for your own extruder. After filament has
# been changed, the print can be resumed from its previous position
# with the "RESUME" gcode.

[pause_resume]

[gcode_macro M600]
gcode:
    {% set X = params.X|default(50)|float %}
    {% set Y = params.Y|default(0)|float %}
    {% set Z = params.Z|default(10)|float %}
    SAVE_GCODE_STATE NAME=M600_state
    PAUSE
    G91
    G1 E-.8 F2700
    G1 Z{Z}
    G90
    G1 X{X} Y{Y} F3000
    G91
    G1 E-50 F1000
    RESTORE_GCODE_STATE NAME=M600_state

[gcode_macro LOAD_FILAMENT]
variable_load_distance:  50
variable_purge_distance:  25
gcode:
    {% set speed = params.SPEED|default(300) %}
    {% set max_velocity = printer.configfile.settings['extruder'].max_extrude_only_velocity  * 60 %}
    SAVE_GCODE_STATE NAME=load_state
    G91
    G92 E0
    G1 E{load_distance} F{max_velocity} # fast-load
    G1 E{purge_distance} F{speed} # purge
    RESTORE_GCODE_STATE NAME=load_state

[gcode_macro UNLOAD_FILAMENT]
variable_unload_distance:  50
variable_purge_distance:  25
gcode:
    {% set speed = params.SPEED|default(300) %}
    {% set max_velocity = printer.configfile.settings['extruder'].max_extrude_only_velocity  * 60 %}
    SAVE_GCODE_STATE NAME=unload_state
    G91
    G92 E0
    G1 E{purge_distance} F{speed} # purge
    G1 E-{unload_distance} F{max_velocity} # fast-unload
    RESTORE_GCODE_STATE NAME=unload_state