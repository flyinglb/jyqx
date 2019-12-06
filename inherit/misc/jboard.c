// jboard.c

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

void setup()
{
	string loc;

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_project", "project");
	add_action("do_report", "report");
	add_action("do_read", "read");
	add_action("do_terminate", "terminate");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ û���κι����ƻ� ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d �������ƻ���%d ���½��ȱ��� ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d �������ƻ� ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, j, last_time_read, new_report;
//        string msg, myid;
        string msg;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	msg = query("long");
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++) {
		new_report = 0;
		if( arrayp(notes[i]["report"]) ) {
			j = sizeof(notes[i]["report"]);
			while(j--)
				if( notes[i]["report"][j]["time"] <= last_time_read ) break;
			new_report = sizeof(notes[i]["report"]) - j - 1;
		}
		msg += sprintf("%s[%2d]" NOR "  %-30s %12s %+3d (%s)\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1, notes[i]["title"], notes[i]["author"], new_report,
			ctime(notes[i]["time"])[0..15] );
	}
	return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_describe_project(object me, mapping note, string text)
{
	mapping *notes;

	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	set("notes", notes);
	tell_object(me, "�¹����ƻ������\n");

	save();
	return;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_report(object me, mapping report, int project, string text)
{
	mapping *notes, *reports;

	report["msg"] = text;
	notes = query("notes");
	reports = notes[project]["report"];
	if( !arrayp(reports) )	reports = ({ report });
	else					reports += ({ report });

	notes[project]["report"] = reports;
	notes[project]["time"] = time();

	set("notes", notes);
	tell_object(me, "���ȱ�����ϡ�\n");

	save();
	return;
}

int do_project(string arg)
{
	mapping note;

	if(!arg) return notify_fail("�����ƻ���ָ��һ�����⡣\n");
	
	note = allocate_mapping(5);
	note["title"] = arg;
	note["owner"] = this_player()->query("id");
	note["author"] = this_player()->name(1);
	note["time"] = time();
	this_player()->edit( (: done_describe_project, this_player(), note :) );
	return 1;
}

int do_report(string arg)
{
	int num;
	string title;
	mapping note, *notes;

	if(!arg || sscanf(arg, "%d %s", num, title)!=2 )
		return notify_fail("ָ���ʽ��report <�ƻ����> <���ȱ������>\n");

	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û����������ƻ���\n");

	note = allocate_mapping(5);
	note["title"] = arg;
	note["owner"] = this_player()->query("id");
	note["author"] = this_player()->name(1);
	note["time"] = time();
	this_player()->edit( (: done_report, this_player(), note, num-1 :) );
	return 1;
}

int do_read(string arg)
{
	int num, rep, last_read_time;
	mapping *notes;
	string myid;

	last_read_time = this_player()->query("board_last_read/" + query("board_id"));
	myid	= query("board_id");
	notes	= query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("���ȱ���Ŀǰû���κμƻ���\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <�ƻ����>[.<������>]|new|next\n");
	if( arg=="new" || arg=="next" ) {
		for(num = 1; num<=sizeof(notes); num++)
			if( notes[num-1]["time"] > last_read_time ) break;
	} else if( sscanf(arg, "%d.%d", num, rep)==2 ) {
		if( num < 1 || num > sizeof(notes) ) return notify_fail("û������ƻ���\n");
		else num--;
		if( rep < 1 || rep > sizeof(notes[num]["report"]) )	return notify_fail("û��������ȱ��档\n");
		else rep --;
		this_player()->start_more( sprintf(
"[%d.%d] %s: %s\n-------------------------------------------------------------------\n"
"%s\n-------------------------------------------------------------------\n%s\t\t%s(%s)\n",
			num + 1, rep + 1,
			notes[num]["title"],
			notes[num]["report"][rep]["title"],
			notes[num]["report"][rep]["msg"],
			ctime(notes[num]["report"][rep]["time"]),
			notes[num]["report"][rep]["author"],
			notes[num]["report"][rep]["owner"] ) );

		if( notes[num]["time"] > last_read_time )
			this_player()->set("board_last_read/" + query("board_id"),
				notes[num]["time"]);

		return 1;
	} if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ����ƻ��ļ򱨣�\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û������ƻ���\n");
	num--;
	this_player()->start_more( sprintf(
"[%2d]\t%s\n�����ˣ�%s(%s) : %s\n----------------------------------------------------------------------\n%s"
"----------------------------------------------------------------------\n���ȱ��棺%d �ݡ�\n",
		num + 1,
		notes[num]["title"],
		notes[num]["author"], notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		notes[num]["msg"],
		sizeof(notes[num]["report"]) ) );

	// Keep track which post we were reading last time.
	if( notes[num]["time"] > last_read_time )
		this_player()->set("board_last_read/" + query("board_id"),
			notes[num]["time"]);

	return 1;
}


int do_terminate(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	if( notes[num]["owner"] != (string)this_player(1)->query("id")
	&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("������Բ�����д�ġ�\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return 1;
}
