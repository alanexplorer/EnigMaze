volatile int timer;
void incrementa_timer() { timer++; }
END_OF_FUNCTION(incrementa_timer)

tempo()
{
    timer = 0;
  LOCK_FUNCTION(incrementa_timer);
  LOCK_VARIABLE(timer);
  install_int_ex(incrementa_timer, MSEC_TO_TIMER(1));

}
END_OF_FUNCTION(tempo);
