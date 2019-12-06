// Room: /u/zqb/tiezhang/shanlu-1.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", GRN"�ϼ�"NOR);
	set("long", @LONG
    ת��һ��С�䣬��Ȼ��ǰһ�̣���ǰ��һƬ�ܴ�Ĺϼܡ��ڸߴ�
��ľ���ԣ���ֲ��һЩ�߲˺͹��࣬�������������˸���ֲ���ï�ܵ�Ҷ 
���У����¸����Ѿ�����Ĺ�ʵ��˿�ϣ���ϣ���«...����һЩ�в�����
�ƵĹϹ�Ҳ���������С�
LONG	);
    set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
    "southeast" : __DIR__"shuijing.c",
"west" : __DIR__"guangchang.c",
]));
    set("objects", ([
     __DIR__"npc/qqzhang" : 1,
    ]));
	set("no_clean_up", 0);
    set("hulu_count", 5);
	setup();
}
void init()
{
        add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
        object me = this_player();
        object ob;

        if (me->query_temp("marks/ժ1") )
            return notify_fail("���Ѿ�ժ���ˣ���Ҫ��ô̰�ģ�\n");

    if (!arg || (arg != "hulu" && arg != "��«"))
{
        if (query("hulu_count") < 1)
        {
        message_vision ("$N����֦Ҷ������ȥ�����ֺ�«�Ѿ�������ժû�ˣ�\n",this_player());
        return 1;
        }
        return notify_fail("����ժʲô��\n");
        return 1;
}

{
        write("������ż⣬�Ӽ�����ժ����һ����«��\n");
        this_player()->set_temp("marks/ժ1", 1);

            ob=new("/d/tiezhang/obj/qingshui-hulu");
            ob->move(this_player());
            add("hulu_count", -1);

        return 1;
       }
}

