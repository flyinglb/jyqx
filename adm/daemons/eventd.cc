/*
 * Object: Global Event Handle
 * File Path: /adm/daemons/eventd.c
 * Creater : Byp@MX 2001/05/14
 * Last Modify : 
 * Note : 
 *
 * EventQueue = ([
 *      "obj": object obj,
 *      "fun": function fun,
 *      "part": mixed parameter,
 * ]);
 */

#pragma optimize
#pragma save_binary

#define Event_Delay     60
#define Max_EventQueue   15000

mapping *EventQueue;
int EventQueueIndex;

void cleanup_event()
{
        EventQueue = 0;
}

private void next_event()
{
        remove_call_out("global_event_handle");
        call_out("global_event_handle",Event_Delay);
}

varargs int add_event(mixed obj, string fun, mixed *part)
{
        if( !objectp(obj) && !stringp(obj) )
                error("add_event(): Bad argument 0, expect object or string tyep.\n");
        if( !stringp(fun) )
                error("add_event(): Bad argument 1, expect string tyep.\n");
        if( sizeof(EventQueue) >= Max_EventQueue-100 )
                error("add_event(): Max Event Queue.\n");
        if(!EventQueue)
                EventQueue = ({(["obj":obj,"fun":fun,"part":part])});
        else    EventQueue += ({(["obj":obj,"fun":fun,"part":part])});
        return 1;
}

int del_event(int i)
{
        if( i<0 || i> sizeof(EventQueue)-1 )
                return 0;
        EventQueue -= ({ EventQueue[i] });
        return 1;
}

varargs mixed get_event()
{
        return EventQueue;
}

void create()
{
        EventQueueIndex = -1;
        next_event();
}

void global_event_handle()
{
        int i,i1;
        object obj;
        mixed *part;

        if( !EventQueue ) next_event();
        for(i=0,i1=sizeof(EventQueue);i<i1;i++) {
                if( objectp(EventQueue[i]["obj"]) )
                        obj = EventQueue[i]["obj"];
                else if( stringp(EventQueue[i]["obj"]) ) {
                        obj = find_object(EventQueue[i]["obj"]);
                        if( !obj ) obj = load_object(EventQueue[i]["obj"]);
                }
                if( !objectp(obj) ) {
                        call_out("del_event",2,i);
                        continue;
                }
                if( !EventQueue[i]["part"] )
                        catch( call_other(obj, EventQueue[i]["fun"]) );
                else {
                        part = ({ EventQueue[i]["fun"] }) + EventQueue[i]["part"];
                        catch( call_other(obj, part) );
                }
                call_out("del_event",2,i);
                break;
        }
        next_event();
}
