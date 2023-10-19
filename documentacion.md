# ESTRUCTURAS

## point
Contiene dos enteros, 'x' e 'y'. Usado para almacenar coordenadas.

## vector
Igual que point, pero en lugar de enteros son doubles 'x' e 'y'. Usado para almacenar coordenadas pero con decimales.

## pimg
- img_ptr -> puntero void de la mlx imagen en la que se imprimirá cada pixel.

- data -> array de pixeles de la imagen.
- size_l -> tamaño de la linea
- bpp -> bits por pixel
- endian -> ¿¿??

## cam
- start ->
- end ->
- x -> coordenada x de la cámara en el plano. 0 = centro de la pantalla, -1 = lado izquierdo y 1 = lado derecho.

## line
- start -> donde comienza la linea que se quiere imprimir.
- end -> donde termina la linea que se quiere imprimir.
- height -> altura de la linea a imprimir.
- wall_dist -> distancia del jugador con la pared;

## player

- player -> El caracter que representa el jugador (N, S, E, W). Para saber la orientacion inicial.
- grid_coord -> (vector) Posicion real del presonaje en el mapa.
Son las cooredenadas en las que se encuentra el caracter del jugador en el mapa.
Elemplo: casilla (4, 3).
- pos -> (vector) Posicion del presonaje en el mapa. Elemplo: si el jugador esta en la casilla (x = 4, y = 3), tanto a 'x' como a 'y' le sumamos 0,5 para que el personaje no aparezca pegado a la pared, si no que aparezca en el medio de la casilla.
- dir -> (vector) Direccion inicial del jugador. N = (0, -1) | S = (0, 1) | W = (-1, 0) | E (1, 0);
- plane -> el plano de cámara. La longitud de la direccion y la de este plano, determinarán el campo de visíon.
- map -> Posicion en el mapa de cada pared. Utilizado para localizar las colisiones de los rayos en raycasting.
- ray_dir -> (vector) La direccion de cada rayo que va a ser lanzado.
- side_dist -> (vector) Distancia que cada rayo debe recorrer hasta la primera colisión con una pared.
- delta -> (vector) distancia que debe recorrer el rayodesde primera colision con cooredenada 'x' the una pared hasta la siguiente. lo mismo con las coordenadas 'y'. se calcula con una version reducida del teorema de Pitagoras delta.x = (abs(1.x / ray_dir.x)  delta.y = abs(1rayDir / rayDirY)).
- is_side -> Informa si las coordenadas del rayo son los bordes de un cuadro o no. Usado para saber cuando acaba el bucle.
- side -> Indica que pared es cada una (N, S, E, W). Para saber que textura va en cada pared.
- cam -> camara.
- step -> cuanto avanza cada rayo hasta toparse con una pared.
- line -> (estructura t_line) informacion de la linea que se va a imprimir
- hit -> Informa si el rayo ha colisionado con una pared o no.
- p_img -> (estructura t_pimg) mlx imagen en la que se van a imprimir los pixeles y luego ponerla en la ventana. (para imprimir una vez en lugar de hacerlo pixel a pixel cada iteración)