//Room: /d/dali/dahejieeast.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ͽ�");
	set("long",@LONG
����Ե������������ֹ��ӣ������۴��αȣ���������������һ
Ƭ̫ƽ���־���·���������Ŵ���������������һ����(dong)��
һ̤�����У�����軨�����˱Ƕ�����
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"baiyiziguan",
	    "south"  : __DIR__"baiyiminju",
	    "west"   : __DIR__"shizilukou",
	]));
        set("item_desc", ([
            "dong" : "�ں����Ĵ󶴣���֪���ж��\n",
        ]));
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
                        me->name() + "����ؤ�����ǹ���һ���������������˽�ȥ��",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underdl");
               message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                        return 1;
           }
           return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
       }
} 
