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
                return ::short() + " [ 没有任何任务 ]";

        if( this_player() ) {
                last_read_time = (int)this_player()->query("quest_last_read/" +(string)query("quest_id"));
                for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if( unread )
                return sprintf(HIC + "%s" + NOR + " [ %d 个任务，" + HIY + "%d"+ NOR + " 个" + HIR + "新任务" + NOR + "]", ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ %d 个任务 ]", ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
//        string msg, myid;
        string msg;

        notes = query("notes");
        msg = query("long");
        msg = msg + "任务管理器的使用方法请见 help quest。\n";
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
        tell_object(me, "任务增加完毕。\n");

        save();
        return;
}

int do_post(string arg)
{
        mapping note;
        if(!arg) return notify_fail("增加任务请指定一个简短描述。\n");

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
                return notify_fail("目前没有任何任务。\n");

        if( !arg ) return notify_fail("指令格式：view <任务编号>|new|next\n");
        if( arg=="new" || arg=="next" ) {
                if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                        num = 1;
                else
                        for(num = 1; num<=sizeof(notes); num++)
                                if( notes[num-1]["time"] > last_read_time[myid]) break;

        } else if( !sscanf(arg, "%d", num) )
                return notify_fail("你要查看第几个任务？\n");

        if( num < 1 || num > sizeof(notes) )
                return notify_fail("没有这张留言。\n");
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
                return notify_fail("指令格式：remove <任务编号>\n");
        notes = query("notes");
        if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
                return notify_fail("没有这个任务。\n");
        num--;
        if( notes[num]["author"] != (string) this_player(1)->query("name")
        &&      (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
        &&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
                return notify_fail("这个任务不是你写的。\n");

        if(num == 0)
                notes = notes[num+1..sizeof(notes)-1];
        else
                notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
        write("删除第 " + (num+1) + " 个任务....Ok。\n");
        return 1;
}
