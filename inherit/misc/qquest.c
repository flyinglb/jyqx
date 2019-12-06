// qquest.c write by jackyboy

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
        set("no_get", 1);
        set("no_get_from",1);
        restore();
}

void init()
{
        add_action("do_post", "add");
        add_action("do_read", "view");
        add_action("do_discard", "remove");
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("quest_id")) ) return 0;
        return DATA_DIR + "quest/" + id;
}

string short()
{
        mapping *notes;
        int i, unread, last_read_time;

        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                return ::short() + " [ û���κ����� ]";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("quest_last_read/" +(string)query("quest_id"));
                for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if( unread )
                return sprintf(HIC + "%s" + NOR + " [ %d ������" + HIY + "%d"+ NOR + " ��" + HIR + "������" + NOR + "]", ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ %d ������ ]", ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
//        string msg, myid;
        string msg;

        notes = query("notes");
        msg = query("long");
        msg = msg + "�����������ʹ�÷������ help quest��\n";
        if( !pointerp(notes) || !sizeof(notes) ) return query("long");

        last_time_read = this_player()->query("quest_last_read/" + (string)query("quest_id"));
        for(i=0; i<sizeof(notes); i++)
                msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
                        ( notes[i]["time"] > last_time_read ? HIY: ""),
                        i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
        return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
        mapping *notes;

        note["msg"] = text;
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        // Truncate the notes if maximum capacity exceeded.
        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

        set("notes", notes);
        tell_object(me, "����������ϡ�\n");

        save();
        return;
}

int do_post(string arg)
{
        mapping note;
        if(!arg) return notify_fail("����������ָ��һ�����������\n");

        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = this_player()->query("name");
        note["time"] = time();
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}

int do_read(string arg)
{
        int num;
        mapping *notes, last_read_time;
        string myid;

        last_read_time = this_player()->query("quest_last_read");
        myid = query("quest_id");
        notes = query("notes");

        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("Ŀǰû���κ�����\n");

        if( !arg ) return notify_fail("ָ���ʽ��view <������>|new|next\n");
        if( arg=="new" || arg=="next" ) {
                if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                        num = 1;
                else
                        for(num = 1; num<=sizeof(notes); num++)
                                if( notes[num-1]["time"] > last_read_time[myid]) break;

        } else if( !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ�鿴�ڼ�������\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("û���������ԡ�\n");
        num--;
        this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
                num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
                + notes[num]["msg"] );

        // Keep track which post we were reading last time.
        if( !mapp(last_read_time) )
                this_player()->set("quest_last_read", ([ myid: notes[num]["time"] ]) );
        else
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                        last_read_time[myid] = notes[num]["time"];

        return 1;
}


int do_discard(string arg)
{
        mapping *notes;
        int num;

        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��remove <������>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("û���������\n");
        num--;
        if( notes[num]["author"] != (string) this_player(1)->query("name")
        &&      (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
        &&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
                return notify_fail("�����������д�ġ�\n");

        if(num == 0)
                notes = notes[num+1..sizeof(notes)-1];
        else
                notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
        write("ɾ���� " + (num+1) + " ������....Ok��\n");
        return 1;
}
