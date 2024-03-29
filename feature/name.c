// name.c
// Modified by Eatdami@MX (10/01/2000)

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

nosave string *my_id;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) ) 
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;
			
	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id")) 
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {
		if( stringp(str = query("name")) )
			return str;
		else
			return file_name(this_object());
	}
}

varargs string short(int raw)
{
	string *idlescr = ({ "有点呆","呆子","很呆","狂呆","巨呆","呆毙了" });
	string party_title,title, nick, str, *mask;
	mapping party;
	int idletime;
	
	if( !stringp(str = query("short")) )
                str = name(raw) + "(" + capitalize(query("id")) + ")";

        if( !this_object()->is_character() ) return str;

	if (!raw) {
		if ((int)query_temp("pending/exercise") != 0)
			return name() + "正坐在地下修炼内力。";
		else if ((int)query_temp("pending/respirate") != 0)
			return name() + "正坐在地下吐纳炼精。";
	}
	
        if( !raw && sizeof(mask = query_temp("apply/short")) )
                str = (string)mask[sizeof(mask)-1];
	else 
	{
		if( stringp(nick = query("nickname")) )
			str = sprintf("「%s」%s", nick, str);

		if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);

		if ( mapp(party = query("party")) ) 
		{
			party_title = party["party_name"] + party["rank"];
			str=sprintf("%s %s%s%s", party_title,(title?"":" "),(nick?"":" "), str);
		}
	}

	if( !raw ) {
                if( this_object()->is_ghost() ) str = HIB "(鬼气) " NOR + str;
		if( query_temp("netdead") ) str += HIG " <断线中>" NOR;
		else
		if (query("hunmi")) str += HIR "<昏迷不醒>"NOR;
		else{
			if( in_input() ) str += HIC " <输入文字中>" NOR;
			if( in_edit() ) str += HIY " <编辑档案中>" NOR;
		}
		if( interactive(this_object())
		&&	(idletime = query_idle(this_object()) - 60) > 60 ) 
//                        str += HIM"＜"+idlescr[((idletime>3600)?3600:idletime)/600]+"＞"NOR;
                        str += HIM"＜"+idlescr[((idletime>3600)?3000:idletime)/600]+"＞"NOR;
		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;
	
	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "。\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}

