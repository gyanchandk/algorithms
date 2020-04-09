#include<stdio.h>
#include "machineDef.h"
#include "eventHandling.h"


eSystemEvent read_event(char event)
{
  switch (event) {
    case '0':return zero_Event;
    case '1':return one_Event;
    default:return exit_Event;

  }
}

int main()
{
    eSystemState eNextState = INITIAL_STATE;
    char inputStr[500]="10101010010010111";


    for(int i=0;inputStr[i]!='\0';i++)
    {
        //Api read the event
        eSystemEvent eNewEvent;
        char ch=inputStr[i];

        eNewEvent=read_event(ch);


        if((asStateMachine[eNextState].eStateMachineEvent[eNewEvent] == eNewEvent) && (asStateMachine[eNextState].pfStateMachineEventHandler[eNewEvent] != NULL))
        {

            // function call as per the state and event and return the next state of the finite state machine
            eNextState = (*asStateMachine[eNextState].pfStateMachineEventHandler[eNewEvent])();

        }
        else
        {
            //Invalid
            printf("Exit! : wrong input string");
            break;
        }
    }

    if(eNextState==FINAL_STATE)
        printf("\n VALID STRING");
    else{
        printf("\n INVALID STRING");
    }

  return 0;
}
//(eNextState <= FINAL_STATE) && (eNewEvent <= one_Event)&&
