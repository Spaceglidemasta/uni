#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/timerfd.h>

#define DT_PERIOD_S        0L // this is the period (time difference) between two cyclic interrupts
#define DT_PERIOD_US  100000L // this is the period (time difference) between two cyclic interrupts
#define DT_WAIT_S          0L // this is the time to wait until the first interrupt (in sec=
#define DT_WAIT_US    500000L // this is the time to wait until the first interrupt (in us <1000000)

#define NUM_SLICES       100  // this defines the amount of interrupts 
 
// ********************************** MAIN ************************************************************** 
int main(void) 
{
  int cnt_tick = 0;                             // counter for ticks (interrupt events)
  struct timespec  tP_0;                        // timer stamp for time zero point
      
  // *********** Interrupt Service Routine to be called after timer interrupt ****************************
  // * get the time point of start of ISR and print it out, increase tick counter
  void interrupt_service_routine () 
  {

    struct timespec t_Start_isr  ;

    clock_gettime( CLOCK_REALTIME,  &t_Start_isr );
    printf("\n>%10ld %9ld ns -   -     Tick%i", t_Start_isr.tv_sec - tP_0.tv_sec, t_Start_isr.tv_nsec, cnt_tick);
    cnt_tick++;
  }
  // *********** end of Interrupt Service Routine *******************************************************

  // *********** setup part *****************************************************************************
  int ret;                                      // default return value buffer
  struct itimerval itval;                       // parameters for interrupt timer

  itval.it_interval.tv_sec  = DT_PERIOD_S;      // seconds for timer period
  itval.it_interval.tv_usec = DT_PERIOD_US;     // micro seconds for timer period
  itval.it_value.tv_sec     = DT_WAIT_S;        // seconds to wait after first start of timer
  itval.it_value.tv_usec    = DT_WAIT_US;       // micro seconds to wait after first start of timer
  
  // define the alarm by specifying the alarm type and the ISR
  signal (SIGALRM, interrupt_service_routine);
  
  // comment out the line above with signal and uncomment the following lines for sigaction
  /*
  struct sigaction mysigaction;                         // initiate my sigaction as my sigactionset
  sigemptyset(&mysigaction.sa_mask);                    // clear mysigactionset
  mysigaction.sa_handler = interrupt_service_routine;   // fill my ISF into mysigactionset
  mysigaction.sa_flags = SA_RESTART;                    // set the SA_RESTART-flag in mysiagaction

  sigaction (SIGALRM, &mysigaction, NULL);              // activate my sigaction set
  //*/
  
  // init and start the timer
  ret = setitimer (ITIMER_REAL, &itval, NULL);
      if (ret) { printf("timer init failed\n"); return(ret); }
  
  // get the time zero point and print it out
  clock_gettime( CLOCK_REALTIME,  &tP_0 );
//  printf("tP_0 %10ld %9ld\n\n", tP_0.tv_sec, tP_0.tv_nsec );
  printf("\n>%10ld %9ld ns -   -     Tick%i", tP_0.tv_sec, tP_0.tv_nsec, cnt_tick);
  // *********** end of setup part **********************************************************************
  
  
  // *************************** the program runs here (loop part)***************************************
  while (cnt_tick < NUM_SLICES) {};
  printf("\n");
  
}  // End of MAIN
