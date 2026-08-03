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

## Nota

La conversión implementada corresponde únicamente al **LM35**. Para utilizar un **TMP36** es necesario modificar la fórmula, ya que este sensor incorpora un **offset de 500 mV**.

## Licencia

Proyecto desarrollado con fines educativos.

