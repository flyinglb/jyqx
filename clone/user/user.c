// user.c
// Modified by Eatdami@MX (10/14/2000)
// modified by long

#include <origin.h>
#include <user.h>

#ifndef CMD_QUIT
#define CMD_QUIT "/cmds/usr/quit"
#endif

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_AUTOSAVE;
inherit F_ENCODING;

nosave int last_age_set;

void create()
{
	::create();
	set_name("�û�����", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�ն������趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
	//if( (int)query("potential") - (int)query("learned_points") < 100 )
	if( (int)query("potential") > (int)query("learned_points") * 2 )
		add("potential", 1);
	if( (int)query("thief") > 0 )
		add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
    if (!environment()) return;
    if (environment()->is_chatting_room()) {
        last_age_set = time();
        return;
    }
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void heart_beat()
{
//        object env = environment();

//        if( env && !env->is_chatting_room() )
		::heart_beat();
	autosave();
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}

protected void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "���߳��� "
				+ NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
//                        command("quit");
                        CMD_QUIT->main(this_object(),0);
			break;
		case DUMP_IDLE:
			if ( wizardp(this_object()) || environment()->is_chatting_room())
				return;
			tell_object( this_object(), "�Բ������Ѿ��������� " 
				+ IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
			tell_room( environment(), "һ��紵�����������е�" + query("name")
				+ "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
//                        command("quit");
                        CMD_QUIT->main(this_object(),0);
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
protected void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
            tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
	    CHANNEL_D->do_channel(this_object(), "sys", "�����ˡ�");
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "����������ϡ�\n");
}

