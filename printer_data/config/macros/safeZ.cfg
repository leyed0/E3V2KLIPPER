# [gcode_macro SAFE_HOME_Z]
# description: "Home Z com até 3 tentativas caso o BLTouch falhe"
# gcode:

#   {% set max_attempts = 3 %}
#   {% for i in range(1, max_attempts + 1) %}
#     RESPOND PREFIX="info" MSG="Tentativa { i } de homming Z..."
#     G28 Z
#     {% if printer.toolhead.position.z > 0 %}
#       RESPOND PREFIX="info" MSG="Homing Z bem-sucedido na tentativa { i }"
#     {% else %}
#       RESPOND PREFIX="warn" MSG="Falha na tentativa { i }, levantando Z para tentar novamente..."
#       G91
#       FORCE_MOVE STEPPER=stepper_z DISTANCE=10 VELOCITY=10 ACCEL=100
#       G90
#     {% endif %}
#   {% endfor %}

#   {% if printer.toolhead.position.z <= 0 %}
#     RESPOND PREFIX="error" MSG="Todas as tentativas de homing Z falharam. Verifique o BLTouch."
#     M112
#   {% endif %}
