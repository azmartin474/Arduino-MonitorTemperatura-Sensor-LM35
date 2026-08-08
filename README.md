# Monitor de Temperatura con Arduino (LM35 / TMP36)



## Descripción



Este proyecto muestra la evolución de un monitor de temperatura utilizando sensores analógicos con Arduino.



## Historial de cambios



### Commit 1

**`Lectura analógica compatible con sensores LM35 y TMP36`**

- Se implementa la lectura del valor analógico mediante `analogRead()`.

- El programa imprime en el Monitor Serie el valor del ADC (0–1023).

- Este código es compatible con los sensores \*\*LM35\*\* y \*\*TMP36\*\*, ya que ambos entregan una señal analógica.

### Commit 2

**`Cálculo de temperatura en °C usando el sensor LM35`**

- Se convierte la lectura del ADC a temperatura en grados Celsius.
- Se utiliza el factor de conversión correspondiente al **LM35** (10 mV/°C).
- El Monitor Serie muestra directamente la temperatura en °C.

### Commit 3

**`Visualización de temperatura en LCD 16x2 sin I2C`**

En esta versión se incorpora una pantalla LCD 16x2 conectada directamente a Arduino, utilizando la librería LiquidCrystal y comunicación paralela de 4 bits.

La temperatura continúa mostrándose en el Monitor Serie y ahora también se visualiza en la pantalla LCD.

#### Conexión de la LCD 16x2

La LCD se conecta directamente al Arduino mediante comunicación paralela de 4 bits.

#### Alimentación y contraste LCD

| LCD | Arduino |
|---|---|
| VSS | GND |
| VDD | 5 V |
| VO | Potenciómetro |
| RW | GND |

> **Nota:** El pin de 5 V del Arduino puede alimentar varios componentes simultáneamente. En una protoboard se puede distribuir la alimentación desde los rieles de 5 V y GND.

#### Control LCD

| LCD | Arduino |
|---|---|
| RS | Pin digital 12 |
| E | Pin digital 11 |
| D4 | Pin digital 5 |
| D5 | Pin digital 4 |
| D6 | Pin digital 3 |
| D7 | Pin digital 2 |

> **Nota:** Los pines D0–D3 no se conectan porque la LCD funciona en modo de 4 bits.

#### Retroiluminación

| LCD | Arduino |
|---|---|
| A (+) | 5 V* |
| K (-) | GND* |

> ⚠️ **Precaución:** Antes de conectar A a 5 V, verificar si la LCD tiene una resistencia integrada. Si no la tiene, utilizar una resistencia externa para limitar la corriente.

#### Configuración en el código

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
```

En esta configuración, los números corresponden a pines digitales del Arduino utilizados por la LCD.

 Si la tarejta Arduino tiene un solo pin 5V, ese mismo punto puede alimentar VDD y la retroiluminación A, siempre que el consumo total esté dentro de lo que puede suministrar la placa y la retroiluminación tenga su limitación de corriente correspondiente.

## Nota

La conversión implementada corresponde únicamente al **LM35**. Para utilizar un **TMP36** es necesario modificar la fórmula, ya que este sensor incorpora un **offset de 500 mV**.

## Licencia

Proyecto desarrollado con fines educativos.