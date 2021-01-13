mmap_ffinal()
{
    ///SONS
    SAMPLE* Som_Tiro = load_sample("sons\\arrow.wav");
    SAMPLE* Som_Flecha = load_sample("sons\\flecha.wav");
    int estado_anterior_SPACE;
//  ##################### - Variaveis - ###########################

    int x = 10, y = 520; // Posicao inicial do Terseu;
    int ini_x = 10, ini_y = 16; // Posicao inicial do Minotauro;
    int resolucao_x = 800, resolucao_y = 640;
    int velocidade_terseu = 2;
    int velocidade_mino = 2;
    int velocidade_do_tiro_terseu = 4;
    int y_tiro, x_tiro;
    int testa_tiro_terseu = 0;
    int teste_movimento = 0;
    int vida_do_inimigo = 10;
    int vida_do_terseu = 10;
    int aux_tiro = 0;
    int x_tiro_inimigo, y_tiro_inimigo;
    int velocidade_do_tiro_mino = 4;
    int testa_tiro_mino = 0;
    int acertou_terseu = 0;
    int acertou_mino = 0;
    int pause=1;
    char nome_do_jogo[40];
    char enemy_life[40];
    char my_life[40];
    int h = 0; //define a altura inicial
    int l = 0; //define a largura inicial
    int chama_sprite = 0;

//  #################################################################

    sprintf(nome_do_jogo,"Batalha Final");

    BITMAP *barra = load_bitmap("imgs/notificacoes.bmp",NULL);

    BITMAP *Fase_final = load_bitmap("imgs\\final.bmp", NULL);
    draw_sprite(screen, Fase_final, 0,0);

    BITMAP *terseu = load_bitmap("Personagens/terseu.bmp",NULL);

    BITMAP *minotauro = load_bitmap("imgs\\mino.bmp", NULL);
    draw_sprite(screen, minotauro, ini_x, ini_y);

    BITMAP *tiro = load_bitmap("imgs\\tiro.bmp", NULL);

    BITMAP *tiro_inimigo = load_bitmap("imgs\\tiro_inimigo.bmp", NULL);

    BITMAP *game_over = load_bitmap("imgs\\game_over.bmp", NULL);
    BITMAP *you_win = load_bitmap("imgs\\you_win.bmp", NULL);

    BITMAP *buffer = create_bitmap(resolucao_x,resolucao_y);

    while (!key[KEY_ESC] && vida_do_inimigo > 0 && vida_do_terseu > 0)
    {
        estado_anterior_SPACE = key[KEY_SPACE];
        poll_keyboard();
        clear_bitmap(buffer);
        draw_sprite(buffer, Fase_final, 0, 0);

// ################# - Pause - ######################
        if(key[KEY_P])
        {
            readkey();
        }


// ######### - Movimentos do Terseu - ############
        if(key[KEY_SPACE])
        {
            h = 0;
            l = 96;
            draw_sprite (buffer, Fase_final, 0, 0);
            masked_blit(terseu, buffer, h, l, x, y, 32, 32);

        }

        if(key[KEY_LEFT] && x >= 5)
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 32;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 32;
            }
            else
            {
                h = 64;
                l = 32;
                chama_sprite = -1;

            }
            chama_sprite++;
            x = x - velocidade_terseu;
            draw_sprite (buffer, Fase_final, 0, 0);
            masked_blit(terseu, buffer, h, l, x, y, 32, 32);
        }

        if(key[KEY_RIGHT]&& x <= resolucao_x-50)
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 64;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 64;
            }
            else
            {
                h = 64;
                l = 64;
                chama_sprite = -1;

            }
            chama_sprite++;
            x = x + velocidade_terseu;
            draw_sprite (buffer, Fase_final, 0, 0);
            masked_blit(terseu, buffer, h, l, x, y, 32, 32);
        }

        masked_blit(terseu, buffer, h, l, x, y, 32, 32);
// ########################################################

        draw_sprite(buffer, barra, 0, 0);
        textout_centre_ex(buffer,font,nome_do_jogo,70,580,makecol(255,0,0), -1);
        sprintf(enemy_life,"Minotauro life: %d",vida_do_inimigo);
        textout_centre_ex(buffer,font,enemy_life,370,620,makecol(255,0,0), -1);
        sprintf(my_life,"Terseu Life: 10",vida_do_terseu);
        textout_centre_ex(buffer,font,my_life,70,620,makecol(255,0,0), -1);


// ############## - Tiro do Terseu - ####################
        if (key[KEY_SPACE])
        {
            if(estado_anterior_SPACE == 0 && key[KEY_SPACE] != 0)
                play_sample(Som_Flecha, 255, 128, 1000, FALSE);
            x_tiro = x+15;
            y_tiro = y-10;
            testa_tiro_terseu = 1;
        }
        if ( testa_tiro_terseu == 1 )
        {
            y_tiro = y_tiro - velocidade_do_tiro_terseu;
            draw_sprite(buffer, tiro, x_tiro, y_tiro);
            if ( y_tiro <= -10 )
            {
                if ( acertou_mino == 1 )
                {
                    vida_do_inimigo--;
                }
                testa_tiro_terseu = 0;
                acertou_mino = 0;
            }
        }
// ########################################################

// ########## - Testa se atingiu o Inimigo - ##############
        if ( y_tiro <= 64 && y_tiro >= 0 )
        {
             if ( x_tiro >= ini_x && x_tiro <= ini_x+30)
                acertou_mino = 1;
        }
// ########################################################

// #########- Movimento do Minotauro - #################
        if ( ini_x <= resolucao_x-70 && teste_movimento == 0 )
        {
            ini_x = ini_x + velocidade_mino;
            draw_sprite(buffer, minotauro, ini_x, ini_y);
            if ( ini_x >= resolucao_x-70 )
                teste_movimento = 1;
        }
        else if ( ini_x >= 5 && teste_movimento == 1 )
        {
            ini_x = ini_x - velocidade_mino;
            draw_sprite(buffer, minotauro, ini_x, ini_y);
            if ( ini_x <= 5 )
                teste_movimento = 0;
        }
// ########################################################

// ############### - Tiro do Inimigo - ####################
        if ( aux_tiro % 300 == 0 )
        {
            play_sample(Som_Tiro, 255, 128, 1000, FALSE);
            x_tiro_inimigo = ini_x+20;
            y_tiro_inimigo = ini_y+50;
            testa_tiro_mino = 1;
        }
        if ( testa_tiro_mino == 1 )
        {
                y_tiro_inimigo = y_tiro_inimigo + velocidade_do_tiro_mino;
                draw_sprite(buffer, tiro_inimigo, x_tiro_inimigo, y_tiro_inimigo);
                if ( y_tiro_inimigo >= 550 )
                {
                    if ( acertou_terseu == 1 )
                    {
                        vida_do_terseu-=1;
                    }
                    testa_tiro_mino = 0;
                    acertou_terseu = 0;
                }
        }
        aux_tiro++;

// ########################################################

// ########## - Testa se atingiu o Terseu - #############
        if ( y_tiro_inimigo <= 550 && y_tiro_inimigo >= 500 )
        {
             if ( x_tiro_inimigo >= x && x_tiro_inimigo <= x+20)
                acertou_terseu=1;
        }
// ########################################################

// # - Carrega as imagens no buffer depois carrega o buffer na tela - #

        draw_sprite(buffer, minotauro, ini_x, ini_y);

        textout_ex(buffer,font," Instrucoes ",550,580,makecol(255,0,0), -1);
        textout_ex(buffer,font," SpaceBar = Tiro ",550,600,makecol(255,0,0), -1);
        textout_ex(buffer,font," P = pause ",550,610,makecol(255,0,0), -1);
        textout_ex(buffer,font," Movimentacao = setas ",550,620,makecol(255,0,0), -1);
        draw_sprite(screen, buffer, 0, 0);
// ########################################################
    } // Fim do "while (!key[KEY_ESC])";

    clear_bitmap(buffer);

    if (  vida_do_terseu > 0 && vida_do_inimigo <= 0 )
    {
        draw_sprite(buffer, you_win, 0, 0);
        readkey();
    }
    else if (  vida_do_inimigo > 0 && vida_do_terseu <= 0 )
    {
        draw_sprite(buffer, game_over, 0, 0);
        readkey();
    }
    else
    {
        textout(buffer,font,"Pressione qualquer tecla para finalizar!",resolucao_x/3, resolucao_y/3,makecol(255,255,0));
        readkey();
    }

    draw_sprite(screen, buffer, 0, 0);

    rest(4000);
    mmenu(0);

    return 0;
}
END_OF_FUNCTION(ffinal);
