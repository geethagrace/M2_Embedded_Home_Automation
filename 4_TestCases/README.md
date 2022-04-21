## TEST PLAN AND OUTPUTS

# Test Plans

| **Test ID** | **Description** | **Input** | **Output** | **Status** |
| --- | --- | --- | --- | --- |
| TID\_01 | Light control | input = 1 | Light1 is ON  | PASS |
| TID\_02 | Light control | input = 2 | Light1 is OFF  | PASS |
| TID\_03 | Light control | input = 3 | Light2 is ON  | PASS |
| TID\_04 | Light control | input = 4 | Light2 is OFF  | PASS |
| TID\_05 | Heater control | input = H | Heater ON for 15mins  | PASS |
| TID\_01 | Heater control | timer = 15mins | Heater will get OFF | PASS |
| TID\_06 | Motor control | input = M | Motor will be ON till some water level | PASS |
| TID\_07 | Motor control | input = M && switch = 0 | Motor will get OFF | PASS |
| TID\_08 | Motor control | Ultrasonic sensor detected | Motor will get OFF | PASS |
| TID\_10 | Unauthorized control | input = except given set | Invalid instruction  | PASS |
