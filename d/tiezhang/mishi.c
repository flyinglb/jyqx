// Room: /u/zqb/tiezhang/mishi.c

inherit ROOM;
#include <ansi.h>
void init();
void create()
{
	set("short", HIY"����"NOR);
	set("long", @LONG
    �����ٲ������һ�����ң����³����ѻ������ǳ�ʱ�����˵�����
���й�����İ���һ��ʯ����������һֻ���߼�����ʯ��(he)���п����˷�
�����������ޱ��
LONG	);
	set("exits", ([ 
        "out" : __DIR__"hhyuan-3",
        ]));

        set("item_desc", ([ 
        "he" : "һ�����ķ�����ʯ�У����������˳�����\n",
        ]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        
	object me = this_player();
	
	if((int)me->query_skill("dodge",1) <= 30) 
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi",  50);
		message_vision(HIR"$Nֻ���ñ��ٲ������ҡ�һΣ�����վ�ȣ����岻��������ˤ���ٲ�֮�⣡\n"NOR, me);
		me->move(__DIR__"hhyuan-3");
		tell_object(me, HIR"����ٲ���ˤ�˳�����ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
		message("vision", HIR"ֻ��" + me->query("name") + "���ٲ���ˤ�˳��������ڵ��ϰ�������������\n"NOR, environment(me), me);
	}

        add_action("do_open","open");
}

int do_open(string arg)
{
        object me = this_player();
        object ob;

       
    if (!arg || (arg != "he" && arg != "shi he"))
       {
        return notify_fail("�����ʲô��\n");
        return 1;
       }
    else
    {
    if (!present("tiezhang zhangpu",me))
       {
        write("��������ʯ�У�����������һ�������������鼮���㼱æ���������ڻ��С�\n");
        ob=new("/d/tiezhang/obj/zhangpu");
        ob->move(me);
        return 1;
       }
        write("��������ʯ�У���������տյ�ʲôҲû�С�\n");
        return 1;
    }
}



