relogio(BITMAP* buffer)
{
    textprintf_ex(buffer, font, 660, 625, makecol(0,0,0), -1,
       "Tempo: %02d:%02d:%02d", (((timer/1000)/3600)%24) ,(((timer/1000)/60)%60) ,((timer/1000)%60));
}
END_OF_FUNCTION(buf);
