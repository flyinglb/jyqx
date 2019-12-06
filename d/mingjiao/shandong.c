// Room: /d/mingjiao/shandong.c
// Date: Java 97/04/9
#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "�����ܶ�");
	set("long", @LONG
������һ��СС��������Χ�ں����ĺ��ѿ����������ԼԼ����
�Կ���һ�ȴ�ʯ��(men)��
LONG );
	set("exits", ([
		"out"  : __DIR__"huangtulu2",
	]));
	set("item_desc", ([
		"men"  : "һ�ȴ�ʯ�ţ���������������ذɡ�\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
}

void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        object *ob, me = this_player();
        int i;

        if (arg != "men") return notify_fail("���ڸ���? \n");
        if ( objectp(present("xiao zhao", environment(me))))
        {
            if ((me->query_skill("jiuyang-shengong",1)<50) || me->query("neili") < 500)
            {
                    message_vision(CYN"С�ѳ���$N����Ц������ľ����񹦻������ء�\n"NOR,me);
                    return 1;
            }
            message_vision(CYN"С��һ��������ʯ����$Nһ��֮���������죬�����ƿ���\n"NOR,me);

            ob = all_inventory(environment(me));
            for(i=0; i<sizeof(ob); i++)
            {
                if( !living(ob[i]) || ob[i]==me || ob[i]->query("id")=="xiao zhao") continue;
                message_vision(CYN"�޴�����˰�$N������ܶ���\n"NOR,ob[i]);
                ob[i]->move(__DIR__"huangtulu2");
            }
            set("exits/enter",__DIR__"midao0");
            me->add("neili", -400);
            remove_call_out("close");
            call_out("close", 5, this_object());
        }
        else
        {
            message_vision(CYN"ʯ����$Nһ��֮�£�����һЩ�۳���\n"NOR,me);
            me->add("neili", -100);
        }
        return 1;
}

void close(object room)
{
        message("vision","ʯ�������������죬�������ϡ�\n"NOR,room);
        room->delete("exits/enter");
}
