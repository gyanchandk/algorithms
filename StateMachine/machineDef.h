//states
typedef enum
{
    INITIAL_STATE,
    INTERMEDIATE_STATE,
    FINAL_STATE,
} eSystemState;

//events
typedef enum
{
  zero_Event,
  one_Event,
  exit_Event
} eSystemEvent;

#define MAX_EVENTS 2
//typedef of function pointer
typedef eSystemState (*pfEventHandler)(void);
//structure of state and event with event handler
typedef struct
{
    eSystemState eStateMachine;
    eSystemEvent eStateMachineEvent[MAX_EVENTS];
    pfEventHandler pfStateMachineEventHandler[MAX_EVENTS];
} sStateMachine;

eSystemState initialZerohandler(void);
eSystemState initialOnehandler(void);
eSystemState intermediateZerohandler(void);
eSystemState intermediateOnehandler(void);
eSystemState finalZerohandler(void);
eSystemState finalOnehandler(void);


//Initialize array of structure with states and event with proper handler
sStateMachine asStateMachine [] =
{
    {INITIAL_STATE,
      {zero_Event,one_Event},
      {initialZerohandler,initialOnehandler}},

    {INTERMEDIATE_STATE,
      {zero_Event,one_Event},
      {intermediateZerohandler,intermediateOnehandler}},

    {FINAL_STATE,
      {zero_Event,one_Event},
      {finalZerohandler,finalOnehandler}},

};
