# Proyecto: Sistema de Detección Temprana de Incendios Basado en Monitoreo de CO
## Descripción del Proyecto
Este proyecto tiene como objetivo desarrollar un sistema de detección temprana de incendios mediante el monitoreo de los niveles de monóxido de carbono (CO) en el ambiente. El monóxido de carbono es un gas incoloro e inodoro que se produce como resultado de la combustión incompleta de combustibles fósiles y materiales orgánicos. El sistema está diseñado para identificar aumentos anormales en la concentración de CO, lo cual podría indicar un posible foco de ignición, permitiendo tomar medidas antes de que se desarrolle un incendio de mayor magnitud.

## Componentes Utilizados
### Sensor de Monóxido de Carbono (CO): Conectado al pin analógico A0, este sensor monitorea continuamente la concentración de CO en el aire.
### Buzzer Activo: Conectado al pin digital 12, este buzzer emite una alarma sonora cuando se detectan niveles peligrosos de CO.
### Arduino: Microcontrolador que realiza la lectura del sensor y controla el buzzer según los valores de CO detectados.

## Instrucciones de Uso
### Conexión del Hardware:

Conecte el pin de salida del sensor de CO al pin analógico A0 de Arduino.
Conecte el buzzer al pin digital 12 de Arduino.
Asegúrese de que Arduino esté alimentado adecuadamente.

### Carga del Código:

Conecte Arduino a su computadora y abra el Arduino IDE.
Copie el código proporcionado en un nuevo sketch de Arduino IDE.
Seleccione la placa y el puerto correspondientes en el menú de Arduino IDE.
Cargue el código en la placa Arduino.

### Operación:

Una vez que el código esté cargado, el sistema comenzará a monitorear los niveles de CO en el ambiente.
Si la concentración de CO supera un valor umbral (en este caso, 600), el buzzer comenzará a emitir una alarma sonora.
La alarma continuará hasta que los niveles de CO disminuyan o hasta que se intervenga manualmente.
