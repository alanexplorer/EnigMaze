ccreditos(int *sair)
{
  ///BITMAPS
  BITMAP* creditos = load_bitmap("Map/creditos.bmp",NULL);
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

  ///GAME LOOP
  while(!key[KEY_ESC])
  {
    //DRAW
     draw_sprite (buffer, creditos, 0, 0);
     draw_sprite(screen, buffer, 0, 0);

  }

  ///FINALIZAÇÃO
  destroy_bitmap(creditos);
  destroy_bitmap(buffer);
  mmenu();

  return 0;
}
END_OF_FUNCTION(ccreditos);
