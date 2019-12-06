// Room: /d/fuzhou/nanmendou.c
// Date: may.12 1998 Java
inherit ROOM;

void create()
{
	set("short", "���Ŷ�");
	set("long", @LONG
���Ŷ�������һ��޴���ţ�����Ҷï��Ũ���ڸ���Ķ��
�������ֿ��ڱ���ʵ��©�չ⡣����������һС��(dong)��
��ظ��¡�
LONG );
	set("exits", ([ /* sizeof() == 1 */
	    "north"  : __DIR__"nandajie",
	    "south"  : __DIR__"nanmen",
	    "west"   : __DIR__"shiqiao",
	    "east"   : __DIR__"xiaochang",
	]));
	set("item_desc", ([
	    "dong"   : "һ�������İ��Ķ�Ѩ��\n",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
           {
               message("vision",
                        me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underfz");
               message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
       }
}
