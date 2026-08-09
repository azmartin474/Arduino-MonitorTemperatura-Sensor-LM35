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

### Commit 4

**`Visualización de temperatura en LCD 16x2 mediante I2C`**

Se incorpora una LCD 16x2 con módulo I2C, sustituyendo la conexión paralela utilizada anteriormente.

#### Librerías:

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#### Configuración:

LiquidCrystal_I2C lcd(0x27, 16, 2);

- Dirección I2C utilizada: 0x27

- LCD de 16 columnas y 2 filas.

- Inicialización mediante lcd.init().

- Retroiluminación mediante lcd.backlight().

#### Conexiones en Arduino Uno:

| LCD I2C | Arduino |
|---|---|
| VCC | 5 V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

> **Nota:** la dirección 0x27 es una de las más comunes en módulos I2C para LCD, pero puede variar según el módulo. Otras direcciones frecuentes son 0x3F, 0x20 y 0x38. Si la pantalla no responde, es recomendable comprobar la dirección I2C del módulo mediante un escáner I2C.

La pantalla mantiene la visualización bilingüe, alternando entre "Temperatura:" y "Temperature:" cada segundo.

### Commit 5

**`Adaptar lectura de temperatura al sensor TMP36`**

Se modifica el cálculo de temperatura para utilizar un sensor TMP36.

#### El código ahora:

- Convierte la lectura analógica del sensor a voltaje.
- Aplica la fórmula correspondiente al TMP36.
- Muestra la temperatura en °C en el Monitor Serie.
- Muestra la temperatura en °C en la LCD 16x2 mediante I2C.
- Mantiene la dirección I2C 0x27.

#### Conversión utilizada:

Voltaje = lectura × (5.0 / 1023.0)

Temperatura = (Voltaje - 0.5) × 100

#### El TMP36 tiene un offset de aproximadamente 0.5 V a 0 °C y una sensibilidad aproximada de 10 mV/°C.

#### La LCD muestra la temperatura con el símbolo de grados:

Temperatura:
25°C

#### La lectura se actualiza cada 500 ms.

## Nota

La conversión implementada corresponde únicamente al **LM35**. Para utilizar un **TMP36** es necesario modificar la fórmula, ya que este sensor incorpora un **offset de 500 mV**.

La diferencia entre las dos fórmulas:

```text
LM35: Temperatura = Voltaje × 100
TMP36: Temperatura = (Voltaje - 0.5) × 100
```
Con el sensor TMP36 se usa float, para conservar los decimales durante la conversión.

Aunque en este código la LCD finalmente se usa ```(int)temperatura```, para que se muestre solamente la parte entera.
## Licencia

Proyecto desarrollado con fines educativos.