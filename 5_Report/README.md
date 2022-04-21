# HOME AUTOMATION
## INTRODUCTION :
Automation plays a vital role in today's world. Home automation will control home attributes such as lighting, temperature setting, control for motor, etc. Here inputs is given through USART which is considered as bluetooth. Lights are controlled by giving inputs through USART. By giving input to heater, it gets ON and will get OFF automatically using timer. Motor for water level is controlled by both switch and ultrasonic sensor.
## FEATURES :
1. Easy to control home appliances through USART communication.

2. Advanced security and variety of user interfaces.

3. Enables remote accesss .

## 4W'S and 1H :
### What?
* It is an automation which controls lights, turns ON heater and gets OFF automatically after 15mins using timer and motor for water level. If motor is turned ON , when it reaches certain level it gets OFF automatically with the help of sensor and too it also controlled using switch.
### WHY?
* It keeps our home safe. It is flexible and convenient for us to manage all the appliances from one place. It has more efficiency and gives us comfort.
### WHERE?
* We can use it in every Households, Offices and also in every places where automation or any control type working needed.
### WHO?
*  It is a control along with automation, So no need for any manual involvement to turn off some appliances when its done.
### HOW?
* It works via a network of devices that are connected through bluetooth module. The devices can be managed remotely.

## SWOT ANALYSIS :
### Strength :
- Customize as per our convenience.
- Save time with automated tasks.
- Improved appliance functionality.
- Flexibility and remote control.
### Weakness :
- As it is based on technology, if any sort of error happens all of a sudden it may cause a problem.
### Opportunity :
- Now-a-days everything becomes automated. Innovation plays key role. so automation with more innovation creates more opportunity for automated projects  
### Threat :
- Now there are many automations getting developed with various versions.


## REQUIREMENTS :
### High level requirements :
| S.no | High level requirement | Description | Status |
| :---:| :---: | :---: | ---: |
| 1 | HLR1 |  Atmega328 | Done |
| 2 | HLR2 | USART communication | Done |
| 3 | HLR3 | sensor | Done |
| 4 | HLR4 | Timer | Done |

### Low level requirements :
| S.no | Low level requirements | Description | Status |
| :---: | :---: | :---: | ---: |
| 1 | LR1 | Simulide | Done |
| 2 | LR2 | Avr Gcc compiler | Done |
| 3 | LR3 | LED Indication | Done |
| 4 | LR4 | Motor Indication | Done |

## BLOCK DIAGRAM :

![image](https://user-images.githubusercontent.com/101448322/164300315-b59f9049-1116-48ae-9c17-f6333c4a96f6.png)

## FLOWCHART :

![image](https://user-images.githubusercontent.com/101448322/164387457-bd79fccd-2a61-43ac-9881-376a637437d9.png)

## SIMULATION CIRCUIT :

![image](https://user-images.githubusercontent.com/101448322/164300816-f1100c2e-ca56-4191-8526-a6bdf9ee2517.png)

## TEST PLAN AND OUTPUTS :

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

## INSTRUCTION SET :
- 1 -  Light1 is ON . 
- 2 -  Light1 is OFF .
- 3 -  Light2 is ON .
- 4 -  Light2 is OFF .
- H -  Heater ON for 15mins .
- M -  Motor will be ON till ultrasonic gets detected for certain water level . 





