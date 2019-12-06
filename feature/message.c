// message.c
// Modified by Eatdami@MX (10/01/2000)

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
  int len;

  if(!msg || (len=strlen(msg))<1) return;
  //added by long trying to prevent crash.

  if(len>8000) 
   msg=msg[0..8000]+"\n\n������\n";
   //added by long trying to prevent crash.

	msg = CONVERT_D->output(msg,this_object());

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( in_input(this_object()) || in_edit(this_object()) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
	} else
		receive( msg );
}

void write_prompt()
{
        string pmsg, msg = "[����ʱ�ݴ�ѶϢ]\n" ;
        msg = CONVERT_D->output(msg,this_object());
        if( sizeof(msg_buffer) ) {
                receive(BOLD + msg + NOR);
                for(int i=0; i<sizeof(msg_buffer); i++)
                        receive(msg_buffer[i]);
                msg_buffer = ({});
        }
//modified by long
        pmsg = this_object()->query("env/prompt");
        if( wizardp(this_object()) 
        && stringp(pmsg = this_player()->query("cwd")) ) {
                        write(pmsg+HIY"> "NOR);
        } else  write(HIY "> " NOR);
}

void receive_snoop(string msg)
{
	receive("#" + msg);
}
