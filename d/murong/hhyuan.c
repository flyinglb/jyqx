// /u/beyond/mr/hhyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"��԰"NOR);
	set ("long",@long
��԰��ׯ�������ط�һ��������ɽ�軨, �����ڼ�ɽ��ʯ, ����СϪ
��, ����ν: `ǧ����ʼ����, �̱����ð�����` �������ġ� ̧ͷ��ȥ, 
ֻ�������Ĵ����뿪��,һ������������ǽ�ϡ�һ����Ȫ�Ӽ�ɽ��ӿ����
��һ��������Ƣ��
long);
         set("resource/water", 1);
         set("exits",([
             "north" : __DIR__"yunjinlou",
             "west" : __DIR__"hffang",
             "east" : __DIR__"zahuoshi",
]));
         set("item_desc",([
             "teng" : "һ��˳��ǽ�����Ӷ��ϵ������١�\n"
]));
	setup();
}

int init()
{
	add_action("do_pa","pa");
	add_action("do_say","say");
}

int do_say(string arg)
{
          object me;
	 me = this_player();
         if( !arg || arg != "��Ҷ�Ʋ���, �軨ѩ����")
         return notify_fail("ʲô��\n");
        if (me->query("family/family_name")!="����Ľ��")
        return notify_fail("ʲô��\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) {
		write("���뱳���˽������񶴿���û��ô���װɣ�\n", me);
		return 0;
}
         message_vision("�������һ��ǽ�������˿�����ԭ���ǵ�Сľ�ţ�$N˳��С�����˽�ȥ��\n", me);
         me->move(__DIR__"midao");
         return 1;
}
                
int do_pa(string arg)
{
         object me;
         me = this_player();
         if (arg != "teng")
         return notify_fail("��Ҫ��ʲô��\n");
         if ( arg =="teng")
         { 
         write("�����Ŵ�����������ȥ��\n");
         message("vision",
         me->name() + "���Ŵ�����������ȥ��\n",
                     environment(me), ({me}) );
         me->move(__DIR__"shuteng");
         message("vision",
                  me->name() + "��������������������\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

         
