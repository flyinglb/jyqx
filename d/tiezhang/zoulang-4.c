// Room: /u/zqb/tiezhang/zoulang-4.c
#include <room.h>
inherit ROOM;
int have_man();
void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ������ƺ��и��ڰ���С�ݣ�����������һЩ������
LONG	);
        set("exits", ([ 
            "west" : __DIR__"zoulang-1",
        ]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
       add_action("do_tui", "push");
       add_action("do_tui", "tui");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xxs")) )
    room = load_object(__DIR__"xxs");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/south");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_tui(string arg)
{
    object room;

    if (!living(this_player())) return 0;
    if (query("exits/north"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");

    if (arg != "door" && arg != "men")
        return notify_fail("��Ҫ��ʲô��\n");

    if(!(room = find_object(__DIR__"xxs")))
    room = load_object(__DIR__"xxs");

    if(objectp(room))
    {
//    if (!have_man())
//    {
    set("exits/north", __DIR__"xxs");
    message_vision("$N����ذ����ƿ���\n", this_player());
    room->set("exits/south", __FILE__);
    remove_call_out("close_men");
    call_out("close_men", 10);
//    }
  }
    return 1;
}
/*
int have_man()
{
  object *ob = all_inventory(load_object(__DIR__"xxs"));
  int i, ret = 0;

   if (!ob) return 0;
  for (i = 0;i < sizeof(ob);i++) {
  if (!interactive(ob[i])) continue;
  if (living(ob[i])) return 1;
  ret = -1;
}
  return ret;
}
*/
